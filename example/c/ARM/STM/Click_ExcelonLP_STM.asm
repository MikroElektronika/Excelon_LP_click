_systemInit:
;Click_ExcelonLP_STM.c,43 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_ExcelonLP_STM.c,45 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #2
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_ExcelonLP_STM.c,46 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #6
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_ExcelonLP_STM.c,47 :: 		mikrobus_spiInit( _MIKROBUS1, &_EXCELONLP_SPI_CFG[0] );
MOVW	R0, #lo_addr(__EXCELONLP_SPI_CFG+0)
MOVT	R0, #hi_addr(__EXCELONLP_SPI_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_spiInit+0
;Click_ExcelonLP_STM.c,48 :: 		mikrobus_logInit( _LOG_USBUART_A, 115200 );
MOV	R1, #115200
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_ExcelonLP_STM.c,49 :: 		mikrobus_logWrite("--- System init ---", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_ExcelonLP_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_ExcelonLP_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_ExcelonLP_STM.c,50 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_ExcelonLP_STM.c,51 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_ExcelonLP_STM.c,53 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_ExcelonLP_STM.c,55 :: 		excelonlp_spiDriverInit( (T_EXCELONLP_P)&_MIKROBUS1_GPIO, (T_EXCELONLP_P)&_MIKROBUS1_SPI );
MOVW	R1, #lo_addr(__MIKROBUS1_SPI+0)
MOVT	R1, #hi_addr(__MIKROBUS1_SPI+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_excelonlp_spiDriverInit+0
;Click_ExcelonLP_STM.c,56 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_ExcelonLP_STM.c,58 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_ExcelonLP_STM.c,60 :: 		mikrobus_logWrite("Read Device ID : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr2_Click_ExcelonLP_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_ExcelonLP_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_ExcelonLP_STM.c,61 :: 		excelonlp_sendCommand(_EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH);
MOVS	R0, __EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH
BL	_excelonlp_sendCommand+0
;Click_ExcelonLP_STM.c,62 :: 		excelonlp_readData(_EXCELONLP_OPCODE_READ_DEVICE_ID, OUTBuf, 9);
MOVS	R2, #9
MOVW	R1, #lo_addr(_OUTBuf+0)
MOVT	R1, #hi_addr(_OUTBuf+0)
MOVS	R0, __EXCELONLP_OPCODE_READ_DEVICE_ID
BL	_excelonlp_readData+0
;Click_ExcelonLP_STM.c,63 :: 		for(cnt = 0; cnt < 9; cnt++)
MOVS	R1, #0
MOVW	R0, #lo_addr(_cnt+0)
MOVT	R0, #hi_addr(_cnt+0)
STRB	R1, [R0, #0]
L_applicationTask2:
MOVW	R0, #lo_addr(_cnt+0)
MOVT	R0, #hi_addr(_cnt+0)
LDRB	R0, [R0, #0]
CMP	R0, #9
IT	CS
BCS	L_applicationTask3
;Click_ExcelonLP_STM.c,65 :: 		IntToHex(OUTBuf[cnt], demoText);
MOVW	R0, #lo_addr(_cnt+0)
MOVT	R0, #hi_addr(_cnt+0)
LDRB	R1, [R0, #0]
MOVW	R0, #lo_addr(_OUTBuf+0)
MOVT	R0, #hi_addr(_OUTBuf+0)
ADDS	R0, R0, R1
LDRB	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_IntToHex+0
;Click_ExcelonLP_STM.c,66 :: 		mikrobus_logWrite(" 0x", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr3_Click_ExcelonLP_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_ExcelonLP_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_ExcelonLP_STM.c,67 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_ExcelonLP_STM.c,68 :: 		Delay_100ms();
BL	_Delay_100ms+0
;Click_ExcelonLP_STM.c,63 :: 		for(cnt = 0; cnt < 9; cnt++)
MOVW	R1, #lo_addr(_cnt+0)
MOVT	R1, #hi_addr(_cnt+0)
LDRB	R0, [R1, #0]
ADDS	R0, R0, #1
STRB	R0, [R1, #0]
;Click_ExcelonLP_STM.c,69 :: 		}
IT	AL
BAL	L_applicationTask2
L_applicationTask3:
;Click_ExcelonLP_STM.c,70 :: 		mikrobus_logWrite(" ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr4_Click_ExcelonLP_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_ExcelonLP_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_ExcelonLP_STM.c,72 :: 		mikrobus_logWrite("Write MikroE data.", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr5_Click_ExcelonLP_STM+0)
MOVT	R0, #hi_addr(?lstr5_Click_ExcelonLP_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_ExcelonLP_STM.c,73 :: 		excelonlp_sendCommand(_EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH);
MOVS	R0, __EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH
BL	_excelonlp_sendCommand+0
;Click_ExcelonLP_STM.c,74 :: 		for(cnt = 0; cnt < 6; cnt++)
MOVS	R1, #0
MOVW	R0, #lo_addr(_cnt+0)
MOVT	R0, #hi_addr(_cnt+0)
STRB	R1, [R0, #0]
L_applicationTask5:
MOVW	R0, #lo_addr(_cnt+0)
MOVT	R0, #hi_addr(_cnt+0)
LDRB	R0, [R0, #0]
CMP	R0, #6
IT	CS
BCS	L_applicationTask6
;Click_ExcelonLP_STM.c,76 :: 		excelonlp_sendCommand(_EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH);
MOVS	R0, __EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH
BL	_excelonlp_sendCommand+0
;Click_ExcelonLP_STM.c,77 :: 		excelonlp_writeMemoryData(_EXCELONLP_OPCODE_WRITE_MEMORY_DATA, memoryAddress++, sendBuffer[cnt]);
MOVW	R0, #lo_addr(_cnt+0)
MOVT	R0, #hi_addr(_cnt+0)
LDRB	R1, [R0, #0]
MOVW	R0, #lo_addr(_sendBuffer+0)
MOVT	R0, #hi_addr(_sendBuffer+0)
ADDS	R0, R0, R1
LDRB	R0, [R0, #0]
UXTB	R1, R0
MOVW	R0, #lo_addr(_memoryAddress+0)
MOVT	R0, #hi_addr(_memoryAddress+0)
LDR	R0, [R0, #0]
UXTB	R2, R1
MOV	R1, R0
MOVS	R0, __EXCELONLP_OPCODE_WRITE_MEMORY_DATA
BL	_excelonlp_writeMemoryData+0
MOVW	R1, #lo_addr(_memoryAddress+0)
MOVT	R1, #hi_addr(_memoryAddress+0)
LDR	R0, [R1, #0]
ADDS	R0, R0, #1
STR	R0, [R1, #0]
;Click_ExcelonLP_STM.c,78 :: 		Delay_100ms();
BL	_Delay_100ms+0
;Click_ExcelonLP_STM.c,74 :: 		for(cnt = 0; cnt < 6; cnt++)
MOVW	R1, #lo_addr(_cnt+0)
MOVT	R1, #hi_addr(_cnt+0)
LDRB	R0, [R1, #0]
ADDS	R0, R0, #1
STRB	R0, [R1, #0]
;Click_ExcelonLP_STM.c,79 :: 		}
IT	AL
BAL	L_applicationTask5
L_applicationTask6:
;Click_ExcelonLP_STM.c,80 :: 		memoryAddress = 0x00000055;
MOVS	R1, #85
MOVW	R0, #lo_addr(_memoryAddress+0)
MOVT	R0, #hi_addr(_memoryAddress+0)
STR	R1, [R0, #0]
;Click_ExcelonLP_STM.c,81 :: 		mikrobus_logWrite("Read memory data : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr6_Click_ExcelonLP_STM+0)
MOVT	R0, #hi_addr(?lstr6_Click_ExcelonLP_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_ExcelonLP_STM.c,82 :: 		for(cnt = 0; cnt < 6; cnt++)
MOVS	R1, #0
MOVW	R0, #lo_addr(_cnt+0)
MOVT	R0, #hi_addr(_cnt+0)
STRB	R1, [R0, #0]
L_applicationTask8:
MOVW	R0, #lo_addr(_cnt+0)
MOVT	R0, #hi_addr(_cnt+0)
LDRB	R0, [R0, #0]
CMP	R0, #6
IT	CS
BCS	L_applicationTask9
;Click_ExcelonLP_STM.c,84 :: 		MemoryData = excelonlp_readMemoryData(_EXCELONLP_OPCODE_READ_MEMORY_DATA, memoryAddress++);
MOVW	R0, #lo_addr(_memoryAddress+0)
MOVT	R0, #hi_addr(_memoryAddress+0)
LDR	R0, [R0, #0]
MOV	R1, R0
MOVS	R0, __EXCELONLP_OPCODE_READ_MEMORY_DATA
BL	_excelonlp_readMemoryData+0
MOVW	R1, #lo_addr(_MemoryData+0)
MOVT	R1, #hi_addr(_MemoryData+0)
STRB	R0, [R1, #0]
MOVW	R1, #lo_addr(_memoryAddress+0)
MOVT	R1, #hi_addr(_memoryAddress+0)
LDR	R0, [R1, #0]
ADDS	R0, R0, #1
STR	R0, [R1, #0]
;Click_ExcelonLP_STM.c,85 :: 		mikrobus_logWrite(&MemoryData, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_MemoryData+0)
MOVT	R0, #hi_addr(_MemoryData+0)
BL	_mikrobus_logWrite+0
;Click_ExcelonLP_STM.c,86 :: 		Delay_100ms();
BL	_Delay_100ms+0
;Click_ExcelonLP_STM.c,82 :: 		for(cnt = 0; cnt < 6; cnt++)
MOVW	R1, #lo_addr(_cnt+0)
MOVT	R1, #hi_addr(_cnt+0)
LDRB	R0, [R1, #0]
ADDS	R0, R0, #1
STRB	R0, [R1, #0]
;Click_ExcelonLP_STM.c,87 :: 		}
IT	AL
BAL	L_applicationTask8
L_applicationTask9:
;Click_ExcelonLP_STM.c,88 :: 		Delay_ms( 5000 );
MOVW	R7, #34559
MOVT	R7, #915
NOP
NOP
L_applicationTask11:
SUBS	R7, R7, #1
BNE	L_applicationTask11
NOP
NOP
NOP
;Click_ExcelonLP_STM.c,89 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_ExcelonLP_STM.c,91 :: 		void main()
;Click_ExcelonLP_STM.c,93 :: 		systemInit();
BL	_systemInit+0
;Click_ExcelonLP_STM.c,94 :: 		applicationInit();
BL	_applicationInit+0
;Click_ExcelonLP_STM.c,96 :: 		while (1)
L_main13:
;Click_ExcelonLP_STM.c,98 :: 		applicationTask();
BL	_applicationTask+0
;Click_ExcelonLP_STM.c,99 :: 		}
IT	AL
BAL	L_main13
;Click_ExcelonLP_STM.c,100 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
