#include "CH58x_common.h"

void main(void) {
  SetSysClock(CLK_SOURCE_PLL_60MHz);

  // gpio output example
  GPIOB_SetBits(GPIO_Pin_4);
  GPIOB_ModeCfg(GPIO_Pin_4, GPIO_ModeOut_PP_5mA);

  // uart example
  GPIOA_SetBits(GPIO_Pin_9);
  GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);      // RXD
  GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA); // TXD
  UART1_DefInit();
  char *msg = "HelloWorld\n\r";
  UART1_SendString(msg, strlen(msg));

  // timer example
  TMR0_TimerInit(FREQ_SYS / 10);
  TMR0_ITCfg(ENABLE, TMR0_3_IT_CYC_END); // config interrupt
  PFIC_EnableIRQ(TMR0_IRQn);

  while (1) {
  }
}

__attribute__((interrupt("WCH-Interrupt-fast")))
__attribute__((section(".highcode"))) void
TMR0_IRQHandler(void) {
  if (TMR0_GetITFlag(TMR0_3_IT_CYC_END)) {
    TMR0_ClearITFlag(TMR0_3_IT_CYC_END);
    GPIOB_InverseBits(GPIO_Pin_4);
  }
}
