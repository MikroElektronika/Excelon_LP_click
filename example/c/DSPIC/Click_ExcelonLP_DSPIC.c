/*
Example for ExcelonLP Click

    Date          : avg 2018.
    Author        : Katarina Perenidc

Test configuration dsPIC :
    
    MCU                : P33FJ256GP710A
    Dev. Board         : EasyPIC Fusion v7
    dsPIC Compiler ver : v7.1.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes SPI module and set CS and PWM pin as OUTPUT
- Application Initialization - Initializes Driver init
- Application Task - (code snippet) - Reads device ID, writes 6-bytes (MikroE) to memory and reads 6-bytes from memory

*/

#include "Click_ExcelonLP_types.h"
#include "Click_ExcelonLP_config.h"

uint8_t OUTBuf[ 20 ] = {0};
char demoText[ 50 ] = {0};
uint8_t cnt;
char MemoryData[3];
uint8_t sendBuffer[ 7 ] = {'M','i','k','r','o','E',0};
uint32_t memoryAddress = 0x00000055;


void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_EXCELONLP_SPI_CFG[0] );
    mikrobus_logInit( _LOG_USBUART_A, 115200 );
    mikrobus_logWrite("--- System init ---", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    excelonlp_spiDriverInit( (T_EXCELONLP_P)&_MIKROBUS1_GPIO, (T_EXCELONLP_P)&_MIKROBUS1_SPI );
}

void applicationTask()
{
    mikrobus_logWrite("Read Device ID : ", _LOG_TEXT);
    excelonlp_sendCommand(_EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH);
    excelonlp_readData(_EXCELONLP_OPCODE_READ_DEVICE_ID, &OUTBuf[0], 9);
    for(cnt = 0; cnt < 9; cnt++)
    {
        IntToHex(OUTBuf[cnt], demoText);
        mikrobus_logWrite(" 0x", _LOG_TEXT);
        mikrobus_logWrite(demoText, _LOG_TEXT);
        Delay_100ms();
    }
    mikrobus_logWrite(" ", _LOG_LINE);

   mikrobus_logWrite("Write MikroE data.", _LOG_LINE);
   excelonlp_sendCommand(_EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH);
   for(cnt = 0; cnt < 6; cnt++)
   {
        excelonlp_sendCommand(_EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH);
        excelonlp_writeMemoryData(_EXCELONLP_OPCODE_WRITE_MEMORY_DATA, memoryAddress++, sendBuffer[cnt]);
        Delay_100ms();
   }
   memoryAddress = 0x00000055;
   mikrobus_logWrite("Read memory data : ", _LOG_TEXT);
   for(cnt = 0; cnt < 6; cnt++)
   {
       MemoryData[0] = excelonlp_readMemoryData(_EXCELONLP_OPCODE_READ_MEMORY_DATA, memoryAddress++);
       mikrobus_logWrite(MemoryData, _LOG_TEXT);
       Delay_100ms();
   }
   Delay_ms( 5000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}