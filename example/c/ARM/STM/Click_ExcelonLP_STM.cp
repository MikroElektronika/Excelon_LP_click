#line 1 "D:/Clicks_git/E/Excelon-LP_Click/SW/example/c/ARM/STM/Click_ExcelonLP_STM.c"
#line 1 "d:/clicks_git/e/excelon-lp_click/sw/example/c/arm/stm/click_excelonlp_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/e/excelon-lp_click/sw/example/c/arm/stm/click_excelonlp_config.h"
#line 1 "d:/clicks_git/e/excelon-lp_click/sw/example/c/arm/stm/click_excelonlp_types.h"
#line 3 "d:/clicks_git/e/excelon-lp_click/sw/example/c/arm/stm/click_excelonlp_config.h"
const uint32_t _EXCELONLP_SPI_CFG[ 2 ] =
{
 _SPI_FPCLK_DIV4,
 _SPI_FIRST_CLK_EDGE_TRANSITION |
 _SPI_CLK_IDLE_LOW |
 _SPI_MASTER |
 _SPI_MSB_FIRST |
 _SPI_8_BIT |
 _SPI_SSM_ENABLE |
 _SPI_SS_DISABLE |
 _SPI_SSI_1
};
#line 28 "D:/Clicks_git/E/Excelon-LP_Click/SW/example/c/ARM/STM/Click_ExcelonLP_STM.c"
uint8_t OUTBuf[ 20 ] = {0};
char demoText[ 50 ] = {0};
uint8_t cnt;
char MemoryData[1];
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
 excelonlp_spiDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_SPI );
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
