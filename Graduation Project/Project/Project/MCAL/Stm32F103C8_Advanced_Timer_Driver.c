/*
 * Stm32F103C8_Advanced_Timer_Driver.c
 *
 *  Created on: Nov 28, 2023
 *      Author: LEGION
 */

#include "Stm32F103C8_Advanced_Timer_Driver.h"
Timer_Config G_cfg;
GPIO_PIN_Config Pin_Cfg;
Timer_ICU_Config G_Icu_Con;
void MCAL_Timer_GPIO_Init(Advanced_TIM_Reg* TIMx,Timer_Config* Cfg){
	G_cfg = *Cfg;
	//Enable Clock For Timer 1
	if(TIMx == TIM1)
		ENABLE_CLOCK_TIM1();
	switch(Cfg->Mode){
	case  Upcounting :
		TIMx->CR1.BIT_NAME.DIR= PIN_Clear;
		break;
	case  Downcounting :
		TIMx->CR1.BIT_NAME.DIR= PIN_Set;
		break;
	case  Center_aligned :
		TIMx->CR1.BIT_NAME.CMS = 0b11;
		break;
	}
	//ARR is the value to be loaded in the actual auto-reload register.
	TIMx->ARR=Cfg->ARR_Val;
	//The counter clock frequency (CK_CNT) is equal to fCK_PSC / (PSC[15:0] + 1).
	TIMx->PSC = Cfg->Prescaler;
	if(Cfg->Repetition== Repetition_ON){
		TIMx->REP = Cfg->Repetition_Val;
	}
	MCAL_SET_TIMx_GPIO(TIM1);
	if(Cfg->Mechanism == INT_ON){
		//Enable NVIC REQ
		TIM1_UP_NVIC_ENABLE();
		TIMx->DIER.BIT_NAME.UIE = PIN_Set;
	}
	TIMx->CR1.BIT_NAME.CEN = PIN_Set;
	if(Cfg->Mechanism == INT_OFF){
		while(!TIMx->SR.BIT_NAME.UIF){
			TIMx->SR.BIT_NAME.UIF = PIN_Clear ;
		}
	}
}
void MCAL_SET_TIMx_GPIO(Advanced_TIM_Reg* TIMx){
	//Output compare channel x Alternate function push-pull
	Pin_Cfg.Mode = ALT_OUTPUT_PP;
	Pin_Cfg.speed = Max_speed_10MHZ;
	Pin_Cfg.Pin_Num = PIN_8;
	MCAL_GPIO_Init(GPIOA,&Pin_Cfg);


}
void MCAL_Timer_GPIO_DeInit(Advanced_TIM_Reg* TIMx){
	TIM1_RESET();
	TIMx->ARR = 0xFFFF;
	TIMx->CCR1=0;
	TIMx->CCR2=0;
	TIMx->CCR3=0;
	TIMx->CCR4=0;
	TIMx->CNT=0;
	TIMx->DMAB=0;
	TIMx->PSC=0;
	TIMx->REP=0;
}
void MCAL_ICU_GPIO_Init(Advanced_TIM_Reg* TIMx,Timer_ICU_Config* Config){
	G_Icu_Con = *Config;
	//Enable Clock
	if(TIMx == TIM1)
		ENABLE_CLOCK_TIM1();
	TIMx->ARR=65535;
	//1.Select the active input: TIMx_CCR1 must be linked to the TI1 input, so write the CC1S
	//bits to 01 in the TIMx_CCMR1 register.
	switch(Config->Channel_Num){
	case Channel1 :{
		TIMx->CCMR1.input_NAME.CC1S=0b01;

		//2.Program the needed input filter duration with respect to the signal connected to the
		//timer (by programming ICxF bits in the TIMx_CCMRx register if the input is a TIx input).
		//We can validate a transition on TI1 when 8 consecutive samples with the new
		//level have been detected (sampled at fDTS frequency). Then write IC1F bits to 0011 in
		//the TIMx_CCMR1 register
		TIMx->CCMR1.input_NAME.IC1F = 0b0011;
		//4.Program the input prescaler. In our example, we wish the capture to be performed at
		//each valid transition, so the prescaler is disabled (write IC1PS bits to ‘00’ in the
		//TIMx_CCMR1 register).00: no prescaler, capture is done each time an edge is detected on the capture input
		TIMx->CCMR1.input_NAME.IC1PSC = 0b00;
		//Select the edge of the active transition on the TI1 channel by writing CC1P bit to 0 in
		//the TIMx_CCER register (rising edge in this case).
		//0: non-inverted: capture is done on a rising edge of IC1. When used as external trigger, IC1
		//is non-inverted
		TIMx->CCER.BIT_NAME.CC1P = Config->Edge;
		//5.Enable capture from the counter into the capture register by setting the CC1E bit in the
		//TIMx_CCER register.
		TIMx->CCER.BIT_NAME.CC1E = 1;
		//6.If needed, enable the related interrupt request by setting the CC1IE bit in the
		//TIMx_DIER register,
		if(Config->Mechanism == INT_ON){
			TIMx->DIER.BIT_NAME.CC1IE = 1;
		}
		break;
	}
	case Channel2 :{
		TIMx->CCMR1.input_NAME.CC2S=0b01;
		//2.Program the needed input filter duration with respect to the signal connected to the
		//timer (by programming ICxF bits in the TIMx_CCMRx register if the input is a TIx input).
		//We can validate a transition on TI1 when 8 consecutive samples with the new
		//level have been detected (sampled at fDTS frequency). Then write IC1F bits to 0011 in
		//the TIMx_CCMR1 register
		TIMx->CCMR1.input_NAME.IC2F = 0b0011;
		TIMx->CCMR1.input_NAME.IC2PSC = 0b00;
		TIMx->CCER.BIT_NAME.CC2P = Config->Edge;
		TIMx->CCER.BIT_NAME.CC2E = 1;
		if(Config->Mechanism == INT_ON){
			TIMx->DIER.BIT_NAME.CC2IE = 1;
		}

		break;
	}case Channel3 :{
		TIMx->CCMR2.input_NAME.CC3S=0b01;
		TIMx->CCMR2.input_NAME.IC3F = 0b0011;
		TIMx->CCMR2.input_NAME.IC3PSC = 0b00;
		TIMx->CCER.BIT_NAME.CC3P = Config->Edge;
		TIMx->CCER.BIT_NAME.CC3E = 1;
		if(Config->Mechanism == INT_ON){
			TIMx->DIER.BIT_NAME.CC3IE = 1;
		}
		break;
	}case Channel4 :{
		TIMx->CCMR2.input_NAME.CC4S=0b01;
		TIMx->CCMR2.input_NAME.IC4F = 0b0011;
		TIMx->CCMR2.input_NAME.IC4PSC = 0b00;
		TIMx->CCER.BIT_NAME.CC4P = Config->Edge;
		TIMx->CCER.BIT_NAME.CC4E = 1;
		if(Config->Mechanism == INT_ON){
			TIM1_ICU_NVIC_ENABLE();
			TIMx->DIER.BIT_NAME.CC4IE = 1;
		}
		break;
	}
	}
	TIMx->CR1.BIT_NAME.CEN=1;
}

void MCAL_CTC_GPIO_Init(Advanced_TIM_Reg* TIMx,Timer_CTC_Config* Config,Timer_CTC_Output_Mode* Config_Mode){

	/*Procedure:
	1. Select the counter clock (internal, external, prescaler).
	2. Write the desired data in the TIMx_ARR and TIMx_CCRx registers.
	3. Set the CCxIE bit if an interrupt request is to be generated.
	4. Select the output mode. For example:
	– Write OCxM = 011 to toggle OCx output pin when CNT matches CCRx
	– Write OCxPE = 0 to disable preload register
	– Write CCxP = 0 to select active high polarity
	– Write CCxE = 1 to enable the output
	5. Enable the counter by setting the CEN bit in the TIMx_CR1 register*/
	//Enable Clock
	if(TIMx == TIM1)
		ENABLE_CLOCK_TIM1();
	TIMx->ARR =Config->ARR_Val ;
	TIMx->REP = Config->Repetition_Val;
	TIMx->PSC = Config->Prescaler;
	switch(Config->Channel_Num){
	case Channel1 :{
		MCAL_SET_TIMx_CTC_GPIO(TIMx,Channel1);
		TIMx->CCR1 = Config->CCRx_Val;
		if(Config->Mechanism == INT_ON){
			TIM1_ICU_NVIC_ENABLE();
			TIMx->DIER.BIT_NAME.CC1IE = 1;
		}
		TIMx->CCMR1.Compare_BIT_NAME.OC1M = Config_Mode->Mode;
		TIMx->CCMR1.Compare_BIT_NAME.OC1PE = Config_Mode->PRR;
		TIMx->CR1.BIT_NAME.ARPE = 1;
		TIMx->CCER.BIT_NAME.CC1P = Config_Mode->Polarityy;
		TIMx->CCER.BIT_NAME.CC1E = 1;
		break;
	}
	case Channel2 :{
		MCAL_SET_TIMx_CTC_GPIO(TIMx,Channel2);
		TIMx->CCR2 = Config->CCRx_Val;
		if(Config->Mechanism == INT_ON){
			TIM1_ICU_NVIC_ENABLE();
			TIMx->DIER.BIT_NAME.CC2IE = 1;
		}
		TIMx->CCMR1.Compare_BIT_NAME.OC2M = Config_Mode->Mode;
		TIMx->CCMR1.Compare_BIT_NAME.OC2PE = Config_Mode->PRR;
		TIMx->CCER.BIT_NAME.CC2P = Config_Mode->Polarityy;
		TIMx->CCER.BIT_NAME.CC2E = 1;
		break;
	}case Channel3 :{
		MCAL_SET_TIMx_CTC_GPIO(TIMx,Channel3);
		TIMx->CCR3 = Config->CCRx_Val;
		if(Config->Mechanism == INT_ON){
			TIM1_ICU_NVIC_ENABLE();
			TIMx->DIER.BIT_NAME.CC3IE = 1;
		}
		TIMx->CCMR2.BIT_NAME.OC3M = Config_Mode->Mode;
		TIMx->CCMR2.BIT_NAME.OC3PE = Config_Mode->PRR;
		TIMx->CCER.BIT_NAME.CC3P = Config_Mode->Polarityy;
		TIMx->CCER.BIT_NAME.CC3E = 1;
		break;
	}case Channel4 :{
		MCAL_SET_TIMx_CTC_GPIO(TIMx,Channel4);
		TIMx->CCR4 = Config->CCRx_Val;
		if(Config->Mechanism == INT_ON){
			TIM1_ICU_NVIC_ENABLE();
			TIMx->DIER.BIT_NAME.CC4IE = 1;
		}
		TIMx->CCMR2.BIT_NAME.OC4M = Config_Mode->Mode;
		TIMx->CCMR2.BIT_NAME.OC4PE = Config_Mode->PRR;
		TIMx->CCER.BIT_NAME.CC4P = Config_Mode->Polarityy;
		TIMx->CCER.BIT_NAME.CC4E = 1;

		break;
	}

	}
	TIMx->BDTR.BIT_NAME.MOE=1;
	TIMx->CR1.BIT_NAME.CEN = 1;

}





void MCAL_SET_TIMx_CTC_GPIO(Advanced_TIM_Reg* TIMx,uint8 Channel){
	switch(Channel){
	case Channel1:{
		Pin_Cfg.Mode = ALT_OUTPUT_PP;
		Pin_Cfg.speed = Max_speed_10MHZ;
		Pin_Cfg.Pin_Num = PIN_8;
		MCAL_GPIO_Init(GPIOA,&Pin_Cfg);

		break;
	}
	case Channel2:{
		Pin_Cfg.Mode = ALT_OUTPUT_PP;
		Pin_Cfg.speed = Max_speed_10MHZ;
		Pin_Cfg.Pin_Num = PIN_9;
		MCAL_GPIO_Init(GPIOA,&Pin_Cfg);

		break;
	}
	case Channel3:{
		Pin_Cfg.Mode = ALT_OUTPUT_PP;
		Pin_Cfg.speed = Max_speed_10MHZ;
		Pin_Cfg.Pin_Num = PIN_10;
		MCAL_GPIO_Init(GPIOA,&Pin_Cfg);

		break;
	}

	case Channel4:{

		Pin_Cfg.Mode = ALT_OUTPUT_PP;
		Pin_Cfg.speed = Max_speed_10MHZ;
		Pin_Cfg.Pin_Num = PIN_11;
		MCAL_GPIO_Init(GPIOA,&Pin_Cfg);
		break;
	}

	}

}
