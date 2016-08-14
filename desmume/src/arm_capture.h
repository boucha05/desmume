/*
	Copyright (C) 2006 yopyop
	Copyright (C) 2006-2015 DeSmuME team

	This file is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 2 of the License, or
	(at your option) any later version.

	This file is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with the this software.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ARM_CAPTURE
#define ARM_CAPTURE

#if defined(ARM_TRACE)

#include "../../tools/CpuTrace/src/CpuTraceArm.h"

#include "types.h"
#include "bits.h"

extern CpuTrace::ICapture* NDS_Capture_ARM[2];
extern CpuTrace::ICaptureDevice* NDS_CaptureDevice_ARM[2];

void arm_capture_create(u32 id);
void arm_capture_destroy(u32 id);

#define ARMCAPTURE (NDS_Capture_ARM[PROCNUM])

#endif

#endif
