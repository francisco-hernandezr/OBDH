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

//TODO 14 Execute FT_UAH_ASW_Monitoring_0100 and check log with expected log
#define FT_UAH_ASW_Monitoring_0100
#define FT_UAH_ASW_Monitoring_EvDisabled_0110
#define FT_UAH_ASW_Monitoring_MaskedValue_0120

#ifdef FT_UAH_ASW_Monitoring_0100

#define FT_0100_TIME_step0 (OBT_AFTER_POWER_ON + 5)
#define FT_0100_TIME_step1 (OBT_AFTER_POWER_ON + 7)
#define FT_0100_TIME_step2 (OBT_AFTER_POWER_ON + 18)
#define FT_0100_TIME_step3 (OBT_AFTER_POWER_ON + 40)
#define FT_0100_TIME_step4 (OBT_AFTER_POWER_ON + 60)

EmuGSS_TCProgram12_5_Limit_UINT8 prog_FT_0100_step_0(FT_0100_TIME_step0,
		"FT_UAH_ASW_Monitoring_0100 step 0, Config PMODID 0 for monitoring PID 15 with limits [1,20]",
		0, 15, 1, 2, 1, 0x4001, 20, 0x4002);

EmuGSS_TCProgram12_1 prog_FT_0100_step_1(FT_0100_TIME_step1,
		"FT_UAH_ASW_Monitoring_0100 step 1, Enable Monitoring PMODID 0", 0);

EmuGSS_TCProgram20_3_uint8 prog_FT_0100_step_2(FT_0100_TIME_step2,
		"FT_UAH_ASW_Monitoring_0100 step 2, Update PID 15 to 99", 15, 99);

EmuGSS_TCProgram20_3_uint8 prog_FT_0100_step_3(FT_0100_TIME_step3,
		"FT_UAH_ASW_Monitoring_0100 step 3, Update PID 15 to 5", 15, 5);

EmuGSS_TCProgram20_3_uint8 prog_FT_0100_step_4(FT_0100_TIME_step4,
		"FT_UAH_ASW_Monitoring_0100 step 4, Update PID 15 to 0", 15, 0);

#endif

//TODO 15 CREATE TEST FT_UAH_ASW_Monitoring_EvDisabled_0110
//Same steps than FT_UAH_ASW_Monitoring_0100 but use
//EmuGSS_TCProgram5_6 to disable event 0x4002 at OBT_AFTER_POWER_ON + 12



#ifdef FT_UAH_ASW_Monitoring_EvDisabled_0110

#define FT_0110_TIME_step0 (OBT_AFTER_POWER_ON + 5)
#define FT_0110_TIME_step1 (OBT_AFTER_POWER_ON + 7)
#define FT_0110_TIME_step2 (OBT_AFTER_POWER_ON + 12)
#define FT_0110_TIME_step3 (OBT_AFTER_POWER_ON + 18)
#define FT_0110_TIME_step4 (OBT_AFTER_POWER_ON + 40)
#define FT_0110_TIME_step5 (OBT_AFTER_POWER_ON + 60)

EmuGSS_TCProgram12_5_Limit_UINT8 prog_FT_0110_step_0(FT_0110_TIME_step0,
		"FT_UAH_ASW_Monitoring_0110 step 0, Config PMODID 0 for monitoring PID 15 with limits [1,20]",
		0, 15, 1, 2, 1, 0x4001, 20, 0x4002);

EmuGSS_TCProgram12_1 prog_FT_0110_step_1(FT_0110_TIME_step1,
		"FT_UAH_ASW_Monitoring_0110 step 1, Enable Monitoring PMODID 0", 0);

EmuGSS_TCProgram5_6 prog_FT_0110_step_2(FT_0110_TIME_step2,
		"FT_UAH_ASW_Monitoring_0110 step 2, Disable Monitoring event report", 0x4002);

EmuGSS_TCProgram20_3_uint8 prog_FT_0110_step_3(FT_0110_TIME_step3,
		"FT_UAH_ASW_Monitoring_0100 step 3, Update PID 15 to 99", 15, 99);

EmuGSS_TCProgram20_3_uint8 prog_FT_0110_step_4(FT_0110_TIME_step4,
		"FT_UAH_ASW_Monitoring_0100 step 4, Update PID 15 to 5", 15, 5);

EmuGSS_TCProgram20_3_uint8 prog_FT_0110_step_5(FT_0110_TIME_step5,
		"FT_UAH_ASW_Monitoring_0100 step 5, Update PID 15 to 0", 15, 0);


#endif

//TODO 16 CREATE TEST FT_UAH_ASW_Monitoring_MaskedValue_0120

/* Use EmuGSS_TCProgram12_5_Value_UINT8 class to monitor Param 16
 * with a mask = 0x0F and expected value 0x03.
 *  EvID shal be 0x4003. Use the PMONID =1
 * 	EmuGSS_TCProgram12_5_Value_UINT8(uint32_t uniTime2YK
 * 			, const char *brief, uint16_t pmonid,
 *           uint16_t pid, uint8_t interval, uint8_t repetition,
 *           uint8_t mask,
 *           uint8_t expectedValue,
 *           uint16_t unexpectedValEvID);
 *
 */
//Use EmuGSS_TCProgram20_3_uint8 to set PID=16 value to 0x3
//before enable monitoring, and change it to 0x02 after monitoring to obtain
//0x4003 event. After that restore PID to 0x03 and check TM[12,2] transition

#ifdef FT_UAH_ASW_Monitoring_MaskedValue_0120

#define FT_0120_TIME_step0 (OBT_AFTER_POWER_ON)
#define FT_0120_TIME_step1 (OBT_AFTER_POWER_ON + 5)
#define FT_0120_TIME_step2 (OBT_AFTER_POWER_ON + 7)
#define FT_0120_TIME_step3 (OBT_AFTER_POWER_ON + 9)

EmuGSS_TCProgram20_3_uint8 prog_FT_0120_step_0(FT_0120_TIME_step0,
		"FT_UAH_ASW_Monitoring_0120 step 0, Update PID 16 to 0", 16, 3);

EmuGSS_TCProgram12_5_Value_UINT8 prog_FT_0120_step1(FT_0120_TIME_step1,
"FT_SOLO_EPD_ICU_SERV_12_0120_Step1 ,Define PMONID 1 para monitorizar el PID 16",
1, 16, 10, 2 , 0x0F, 0x03, 0x4003);

EmuGSS_TCProgram20_3_uint8 prog_FT_0120_step_2(FT_0120_TIME_step2,
		"FT_UAH_ASW_Monitoring_0120 step 2, Update PID 16 to 2", 16, 2);

EmuGSS_TCProgram20_3_uint8 prog_FT_0120_step_3(FT_0120_TIME_step3,
		"FT_UAH_ASW_Monitoring_0120 step 3, Update PID 16 to 2", 16, 3);

#endif


