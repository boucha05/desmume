#pragma once

#include "CpuTrace.h"

namespace CpuTrace
{
    namespace ARM
    {
        const uint32_t Version = 1;

        namespace Interrupt
        {
            enum
            {
                IRQ,
                FIQ,
            };
        }

        namespace Signal
        {
            enum
            {
                Unhalted,
            };
        }

        namespace MemoryAccess
        {
            enum
            {
                Code,
                Data,
                GPU,
                DMA,
                Debug,
            };
        }

        struct State
        {
            struct
            {
                uint32_t    r[16];
                uint32_t    cpsr;
            }               user;
            struct
            {
                uint32_t    r8;
                uint32_t    r9;
                uint32_t    r10;
                uint32_t    r11;
                uint32_t    r12;
                uint32_t    r13;
                uint32_t    r14;
                uint32_t    spsr;
            }               fiq;
            struct
            {
                uint32_t    r13;
                uint32_t    r14;
                uint32_t    spsr;
            }               svc;
            struct
            {
                uint32_t    r13;
                uint32_t    r14;
                uint32_t    spsr;
            }               abt;
            struct
            {
                uint32_t    r13;
                uint32_t    r14;
                uint32_t    spsr;
            }               irq;
            struct
            {
                uint32_t    r13;
                uint32_t    r14;
                uint32_t    spsr;
            }               und;
        };
    }
}