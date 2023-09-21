#include "CH58x_common.h"

void main(void) {
	SetSysClock(CLK_SOURCE_PLL_60MHz);
	GPIOB_ModeCfg(GPIO_Pin_4, GPIO_ModeOut_PP_5mA);
	while(1) {
		DelayMs(100);
		GPIOB_SetBits(GPIO_Pin_4);
		DelayMs(100);
		GPIOB_ResetBits(GPIO_Pin_4);
	}
}
