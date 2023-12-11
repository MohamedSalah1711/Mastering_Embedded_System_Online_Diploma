/* Learn-In-Depth
 * File name :Stm32f103C6_Driver_gpio.c
 *  Description: source file for EXTI DRIVER stm32f103xx
 * Created By: mohamed salah fathy
 */

#include "Stm32F103C6_EXTI_Driver.h"
//-----------------------------
//Generic Variables (Call back)
//-----------------------------

void (*GP_CallBack [15])(void);


/**================================================================
 * @Fn			-Disable_NVIC
 * @brief 		-Disable NIVC for specific input line
 * @param[in]	- Number of input line
 * @retval-		- None
 */
void  Disable_NVIC(uint8 Input_Line){
	switch(Input_Line){
	case EXTI_0:
		EXTI0_NVIC_DISABLE();
		break;
	case EXTI_1:
		EXTI1_NVIC_DISABLE();
		break;

	case EXTI_2:
		EXTI2_NVIC_DISABLE();
		break;

	case EXTI_3 :
		EXTI3_NVIC_DISABLE();
		break;

	case EXTI_4:
		EXTI4_NVIC_DISABLE();
		break;
	case EXTI_5:
	case EXTI_6:
	case EXTI_7:
	case EXTI_8:
	case EXTI_9:
		EXTI9_5_NVIC_DISABLE();
		break;
	case EXTI_10:
	case EXTI_11:
	case EXTI_12:
	case EXTI_13:
	case EXTI_14:
	case EXTI_15:
		EXTI15_10_NVIC_DISABLE();
		break;

	}

}
/**================================================================
 * @Fn			-Enable_NVIC
 * @brief 		-Enable NIVC for specific input line
 * @param[in]	- Number of input line
 * @retval-		- None
 */
void  Enable_NVIC(uint8 Input_Line){
	switch(Input_Line){
	case EXTI_0:
		EXTI0_NVIC_ENABLE();
		break;
	case EXTI_1:
		EXTI1_NVIC_ENABLE();
		break;

	case EXTI_2:
		EXTI2_NVIC_ENABLE();
		break;

	case EXTI_3 :
		EXTI3_NVIC_ENABLE();
		break;

	case EXTI_4:
		EXTI4_NVIC_ENABLE();
		break;
	case EXTI_5:
	case EXTI_6:
	case EXTI_7:
	case EXTI_8:
	case EXTI_9:
		EXTI9_5_NVIC_ENABLE();
		break;
	case EXTI_10:
	case EXTI_11:
	case EXTI_12:
	case EXTI_13:
	case EXTI_14:
	case EXTI_15:
		EXTI15_10_NVIC_ENABLE();
		break;

	}



}
/**================================================================
 * @Fn			-Get_AFIO_EXTICR_Port_value
 * @brief 		-Check The port and return value for AFIO_EXTICR
 * @param[in]	- GPIO_Typedef* GPIOx
 * @param[out]	- uint8 value for AFIO_EXTICR
 * @retval-		- Val
 */
uint8 Get_AFIO_EXTICR_Port_value(GPIO_Typedef* GPIOx){
	uint8 Val=0;
	if(GPIOx==GPIOA){
		Val=0;
	}else if(GPIOx==GPIOB){
		Val=1;
	}else if(GPIOx==GPIOC){
		Val=2;
	}else if(GPIOx==GPIOD){
		Val=3;
	}
	return Val;
}
/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Init
 * @brief 		-init specific pin for interrupt
 * @param[in]	- EXTI_Pin_Config_t* EXTI_Config
 * @param[out]	- None
 * @retval-		- None
 * Note-
 */
void MCAL_EXTI_GPIO_Init(EXTI_Pin_Config_t* EXTI_Config){
	Update_EXTI(EXTI_Config);
}
/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Update
 * @brief 		-update specific pin for interrupt
 * @param[in]	- EXTI_Pin_Config_t* EXTI_Config
 * @param[out]	- None
 * @retval-		- None
 * Note-
 */
void MCAL_EXTI_GPIO_Update(EXTI_Pin_Config_t* EXTI_Config){
	Update_EXTI(EXTI_Config);
}
/**================================================================
 * @Fn			-Get_CR_shif
 * @brief 		-get the shift number for cr reg
 * @param[in]	- Pin number
 * @param[out]	- uint8 value for shifted position
 * @retval-		- None
 * Note-
 */
/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Deinit
 * @brief 		-Disable interrupt and reset it for MCU
 * @param[in]	- None
 * @param[out]	- None
 * @retval-		- None
 * Note-
 */
void MCAL_EXTI_GPIO_Deinit(){
	EXTI->EXTI_IMR = EXTI_IMR_Reset;
	EXTI->EXTI_EMR = EXTI_EMR_Reset ;
	EXTI->EXTI_RTSR = EXTI_RTSR_Reset;
	EXTI->EXTI_FTSR = EXTI_FTSR_Reset ;
	EXTI->EXTI_SWIER = EXTI_SWIER_Reset;
	EXTI->EXTI_PR = EXTI_PR_Reset ;
	//Enable nvic interrupt by write one to clear
	EXTI0_NVIC_DISABLE();
	EXTI1_NVIC_DISABLE();
	EXTI2_NVIC_DISABLE();
	EXTI3_NVIC_DISABLE();
	EXTI4_NVIC_DISABLE();
	EXTI9_5_NVIC_DISABLE();
	EXTI15_10_NVIC_DISABLE();
}




void EXTI0_IRQHandler(void){
	/*
	 * 	PRx: Pending bit
		0: No trigger request occurred
		1: selected trigger request occurred
		This bit is set when the selected edge event arrives on the external interrupt line. This bit is
		cleared by writing a ‘1’ into the bit.
		Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
	 */
	EXTI->EXTI_PR |=(1<<EXTI_0);
	GP_CallBack[EXTI_0]();
}
void EXTI1_IRQHandler(void){
	/*
	 * 	PRx: Pending bit
			0: No trigger request occurred
			1: selected trigger request occurred
			This bit is set when the selected edge event arrives on the external interrupt line. This bit is
			cleared by writing a ‘1’ into the bit.
			Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
	 */
	EXTI->EXTI_PR |=(1<<EXTI_1);
	GP_CallBack[EXTI_1]();
}
void EXTI2_IRQHandler(void){
	/*
	 * 	PRx: Pending bit
			0: No trigger request occurred
			1: selected trigger request occurred
			This bit is set when the selected edge event arrives on the external interrupt line. This bit is
			cleared by writing a ‘1’ into the bit.
			Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
	 */
	EXTI->EXTI_PR |=(1<<EXTI_2);
	GP_CallBack[EXTI_2]();
}
void EXTI3_IRQHandler(void){
	/*
	 * 	PRx: Pending bit
			0: No trigger request occurred
			1: selected trigger request occurred
			This bit is set when the selected edge event arrives on the external interrupt line. This bit is
			cleared by writing a ‘1’ into the bit.
			Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
	 */
	EXTI->EXTI_PR |=(1<<EXTI_3);
	GP_CallBack[EXTI_3]();
}
void EXTI4_IRQHandler(void){
	/*
	 * 	PRx: Pending bit
			0: No trigger request occurred
			1: selected trigger request occurred
			This bit is set when the selected edge event arrives on the external interrupt line. This bit is
			cleared by writing a ‘1’ into the bit.
			Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
	 */
	EXTI->EXTI_PR |=(1<<EXTI_4);

	GP_CallBack[EXTI_4]();
}
void EXTI9_5_IRQHandler(void){
	/*
	 * 	PRx: Pending bit
			0: No trigger request occurred
			1: selected trigger request occurred
			This bit is set when the selected edge event arrives on the external interrupt line. This bit is
			cleared by writing a ‘1’ into the bit.
			Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
	 */
	if(EXTI->EXTI_PR & (1<<EXTI_5)){
		EXTI->EXTI_PR |=(1<<EXTI_5);
		GP_CallBack[EXTI_5]();
	}if(EXTI->EXTI_PR & (1<<EXTI_6)){
		EXTI->EXTI_PR |=(1<<EXTI_6);
		GP_CallBack[EXTI_6]();
	}if(EXTI->EXTI_PR & (1<<EXTI_7)){
		EXTI->EXTI_PR |=(1<<EXTI_7);
		GP_CallBack[EXTI_7]();
	}if(EXTI->EXTI_PR & (1<<EXTI_8)){
		EXTI->EXTI_PR |=(1<<EXTI_8);
		GP_CallBack[EXTI_8]();
	}if(EXTI->EXTI_PR & (1<<EXTI_9)){
		EXTI->EXTI_PR |=(1<<EXTI_9);
		GP_CallBack[EXTI_9]();
	}
}
void EXTI15_10_IRQHandler(void){
	/*
	 * 	PRx: Pending bit
			0: No trigger request occurred
			1: selected trigger request occurred
			This bit is set when the selected edge event arrives on the external interrupt line. This bit is
			cleared by writing a ‘1’ into the bit.
			Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
	 */
	if(EXTI->EXTI_PR & (1<<EXTI_10)){
		EXTI->EXTI_PR |=(1<<EXTI_10);
		GP_CallBack[EXTI_10]();
	}if(EXTI->EXTI_PR & (1<<EXTI_11)){
		EXTI->EXTI_PR |=(1<<EXTI_11);
		GP_CallBack[EXTI_11]();
	}if(EXTI->EXTI_PR & (1<<EXTI_12)){
		EXTI->EXTI_PR |=(1<<EXTI_12);
		GP_CallBack[EXTI_12]();
	}if(EXTI->EXTI_PR & (1<<EXTI_13)){
		EXTI->EXTI_PR |=(1<<EXTI_13);
		GP_CallBack[EXTI_13]();
	}if(EXTI->EXTI_PR & (1<<EXTI_14)){
		EXTI->EXTI_PR |=(1<<EXTI_14);
		GP_CallBack[EXTI_14]();
	}if(EXTI->EXTI_PR & (1<<EXTI_15)){
		EXTI->EXTI_PR |=(1<<EXTI_15);
		GP_CallBack[EXTI_15]();
	}
}
void Update_EXTI(EXTI_Pin_Config_t* EXTI_Config){
	//	1-Configure The pin as alternative input floating
	GPIO_PIN_Config PinConfig={EXTI_Config->EXTI_Pin.Pin_Number,Max_speed_10MHZ,Floating_Mode};
	MCAL_GPIO_Init(EXTI_Config->EXTI_Pin.GPIO_PORT,&PinConfig);
	//  2-Configure AFIO_EXTICR[index] Register
	uint8 AFIO_EXTICR_index = (EXTI_Config->EXTI_Pin.Line_Number/4);
	uint8 AFIO_EXTICR_position = (EXTI_Config->EXTI_Pin.Line_Number%4)*4;
	//Clear the corresponding Four bits
	AFIO->AFIO_EXTICR[AFIO_EXTICR_index] &=~(0xF<<AFIO_EXTICR_position);
	AFIO->AFIO_EXTICR[AFIO_EXTICR_index] |=(Get_AFIO_EXTICR_Port_value(EXTI_Config->EXTI_Pin.GPIO_PORT)<<AFIO_EXTICR_position);
	// 3-To generate the interrupt, the interrupt line should be configured and Enabled. This is done
	//by programming the two trigger registers with the desired edge detection
	if(EXTI_Config->trigger==Falling){
		EXTI->EXTI_FTSR|= (1<<EXTI_Config->EXTI_Pin.Line_Number);

	}else if (EXTI_Config->trigger==Rising){
		EXTI->EXTI_RTSR|= (1<<EXTI_Config->EXTI_Pin.Line_Number);
	}else{	//Both Rising and falling
		EXTI->EXTI_FTSR|= (1<<EXTI_Config->EXTI_Pin.Line_Number);
		EXTI->EXTI_RTSR|= (1<<EXTI_Config->EXTI_Pin.Line_Number);
	}

	// 4-Set Call back Function
	GP_CallBack[EXTI_Config->EXTI_Pin.Line_Number] = EXTI_Config->P_CallBack;

	// 5-enabling the interrupt request by writing a ‘1’ to
	//	 the corresponding bit in the interrupt mask register.
	if(EXTI_Config->IRQ_EN==Interrupt_Enable){
		EXTI->EXTI_IMR |= (1<<EXTI_Config->EXTI_Pin.Line_Number);
	}else{
		EXTI->EXTI_IMR &= ~(1<<EXTI_Config->EXTI_Pin.Line_Number);
	}
	// 5-Enable NVIC
	if(EXTI_Config->IRQ_EN==Interrupt_Enable){
		Enable_NVIC(EXTI_Config->EXTI_Pin.Line_Number);
	}else{

		Disable_NVIC(EXTI_Config->EXTI_Pin.Line_Number);
	}
}
