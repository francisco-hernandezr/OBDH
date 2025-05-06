/*
 * emu_tc_programming.cpp
 *
 *  Created on: Oct 26, 2024
 *      Author: Oscar Rodriguez Polo
 */

/****************************************************************************
 *
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License
 *   as published by the Free Software Foundation; either version 2
 *   of the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,USA.
 *
 *
 ****************************************************************************/

#include <public/emu_hw_timecode_drv_v1.h>
#include <public/emu_sc_channel_drv_v1.h>
#include <public/emu_gss_v1.h>

#define FT_UAH_ASW_Event_Action_0130

//#define FT_UAH_ASW_Ev_Disabled_0140

//#define FT_UAH_ASW_Ev_Action_Disabled_0150

//#define FT_UAH_ASW_Event_Action_Delete_Action_Error_0160

#ifdef FT_UAH_ASW_Event_Action_0130

#define FT_0130_TIME_step0 (OBT_AFTER_POWER_ON + 3)
#define FT_0130_TIME_step1 (OBT_AFTER_POWER_ON + 4)
#define FT_0130_TIME_step2 (OBT_AFTER_POWER_ON + 9)
#define FT_0130_TIME_step3 (OBT_AFTER_POWER_ON + 20)
#define FT_0130_TIME_step4 (OBT_AFTER_POWER_ON + 30)
#define FT_0130_TIME_step5 (OBT_AFTER_POWER_ON + 40)

EmuGSS_TCProgram20_3_uint8 prog_FT_0130_step_0A(FT_0130_TIME_step0,
		"FT_UAH_ASW_ICU_Monitoring_0130 step 0, Set PID 15 to 5",15,5);

EmuGSS_TCProgram12_5_Limit_UINT8 prog_FT_0130_step_1(FT_0130_TIME_step1,
		"FT_UAH_ASW_ICU_Monitoring_0130 step 0B, Config PMODID 0 for monitoring PID 15",
		0, 15, 1, 2, 1, 0x4001, 20, 0x4002);

EmuGSS_TCProgram19_1_Action_2_1 prog_FT_0130_step_2(FT_0130_TIME_step2,
					"FT_UAH_ASW_Event_Action_0130 step 1, 0x4002 Action is Device  Off",
					0x4002, DeviceCommandOff);


//TODO 17 Complete Test in order to force the DeviceCommandOff execution
//as recovery action After step 5.





EmuGSS_TCProgram20_3_uint8 prog_FT_0130_step_5(FT_0130_TIME_step5,
		"FT_UAH_ASW_Monitoring_0130 step 5, Update PID 15 to 99",15,99);


#endif


#ifdef FT_UAH_ASW_Ev_Disabled_0140

#define FT_0140_TIME_step0 (OBT_AFTER_POWER_ON + 3)
#define FT_0140_TIME_step1 (OBT_AFTER_POWER_ON + 4)
#define FT_0140_TIME_step2 (OBT_AFTER_POWER_ON + 9)
#define FT_0140_TIME_step3 (OBT_AFTER_POWER_ON + 10)
#define FT_0140_TIME_step4 (OBT_AFTER_POWER_ON + 12)
#define FT_0140_TIME_step5 (OBT_AFTER_POWER_ON + 14)
#define FT_0140_TIME_step6 (OBT_AFTER_POWER_ON + 16)
#define FT_0140_TIME_step7 (OBT_AFTER_POWER_ON + 20)
#define FT_0140_TIME_step8 (OBT_AFTER_POWER_ON + 40)

//TODO 18 Create the test as a modification of the 0140 test, but disabling the event
//, so the action is not executed (nor the event is reported)

#endif



#ifdef FT_UAH_ASW_Event_Action_Delete_Action_Error_0150

#define FT_0150_TIME_step0 (OBT_AFTER_POWER_ON + 3)
#define FT_0150_TIME_step1 (OBT_AFTER_POWER_ON + 4)
#define FT_0150_TIME_step2 (OBT_AFTER_POWER_ON + 9)
#define FT_0150_TIME_step3 (OBT_AFTER_POWER_ON + 10)
#define FT_0150_TIME_step4 (OBT_AFTER_POWER_ON + 12)
#define FT_0150_TIME_step5 (OBT_AFTER_POWER_ON + 14)
#define FT_0150_TIME_step6 (OBT_AFTER_POWER_ON + 16)
#define FT_0150_TIME_step7 (OBT_AFTER_POWER_ON + 20)
#define FT_0150_TIME_step8 (OBT_AFTER_POWER_ON + 40)

//TODO 19 Create a test as a modification of the 0150 test, but disabling the
//event-action, so the action is not executed but the event is reported

#endif




#ifdef FT_UAH_ASW_Event_Action_Delete_Action_Error_0160

//TODO 20 Create a test to force the failure when a TC tries to delete an Ev-Action
// that has been added previously


#endif
