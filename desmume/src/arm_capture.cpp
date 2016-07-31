#include "arm_capture.h"
#include "armcpu.h"

using namespace CpuTrace;
using namespace CpuTrace::ARM;

ICapture* NDS_Capture_ARM[2] = { nullptr, nullptr };
ICaptureDevice* NDS_CaptureDevice_ARM[] = { nullptr, nullptr };

namespace
{
    class CaptureHandler : public ICaptureHandler
    {
    public:
        CaptureHandler(armcpu_t& cpu, CpuTrace::ICapture*& capture)
            : mCpu(cpu)
            , mCapture(capture)
        {
        }

        virtual void start(ICapture& capture) override
        {
            mCapture = &capture;
        }

        virtual void stop(ICapture& capture) override
        {
            (void)capture;
            mCapture = nullptr;
        }

        virtual void getState(State& state) override
        {
            for (uint32_t index = 0; index < 16; ++index)
                state.usr.r[index] = mCpu.R[index];
            state.usr.r[13] = mCpu.R13_usr;
            state.usr.r[14] = mCpu.R14_usr;
            state.usr.cpsr = mCpu.CPSR.val;
            state.fiq.r8 = mCpu.R8_fiq;
            state.fiq.r9 = mCpu.R9_fiq;
            state.fiq.r10 = mCpu.R10_fiq;
            state.fiq.r11 = mCpu.R11_fiq;
            state.fiq.r12 = mCpu.R12_fiq;
            state.fiq.r13 = mCpu.R13_fiq;
            state.fiq.r14 = mCpu.R14_fiq;
            state.fiq.spsr = mCpu.SPSR_fiq.val;
            state.svc.r13 = mCpu.R13_svc;
            state.svc.r14 = mCpu.R14_svc;
            state.svc.spsr = mCpu.SPSR_svc.val;
            state.abt.r13 = mCpu.R13_abt;
            state.abt.r14 = mCpu.R14_abt;
            state.abt.spsr = mCpu.SPSR_abt.val;
            state.irq.r13 = mCpu.R13_irq;
            state.irq.r14 = mCpu.R14_irq;
            state.irq.spsr = mCpu.SPSR_irq.val;
            state.und.r13 = mCpu.R13_und;
            state.und.r14 = mCpu.R14_und;
            state.und.spsr = mCpu.SPSR_und.val;
        }

    private:
        armcpu_t&   mCpu;
        ICapture*&  mCapture;
    };

    CaptureHandler captureHandler[] =
    {
        CaptureHandler(NDS_ARM9, NDS_Capture_ARM[ARMCPU_ARM9]),
        CaptureHandler(NDS_ARM7, NDS_Capture_ARM[ARMCPU_ARM7]),
    };

    const char* cpuName[] =
    {
        "ARM946ES",
        "ARM7TDMI",
    };
}

void arm_capture_create(u32 id)
{
    if (id < 2)
        NDS_CaptureDevice_ARM[id] = &CpuTrace::ARM::createCaptureDevice(cpuName[id],captureHandler[id]);
}

void arm_capture_destroy(u32 id)
{
    if (id < 2)
        CpuTrace::ARM::destroyCaptureDevice(*NDS_CaptureDevice_ARM[id]);
}
