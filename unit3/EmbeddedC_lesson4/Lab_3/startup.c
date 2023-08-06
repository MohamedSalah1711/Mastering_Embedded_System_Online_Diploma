#include <stdint.h>
extern int main();
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
void Reset_Handler(void);
void NMI_Handler()__attribute__((weak,alias("Default_Handler")));
void H_fault_Handler()__attribute__((weak,alias("Default_Handler")));
//Booking 1024 Bytes located by .Bss through uninitialized array of int 256 element
static uint32_t Stack_top[256];
void Default_Handler(){
	Reset_Handler();
}
void (*const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) =
{
	(void (*)()) ((uint32_t)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,	
	&NMI_Handler,
	&H_fault_Handler
	
};
void Reset_Handler()
{
	uint32_t Data_Size = (uint8_t*)&_E_data - (uint8_t*)&_S_data;
	uint8_t* P_src = (uint8_t*)&_E_text;
	uint8_t* P_dest = (uint8_t*)&_S_data;
	for(uint32_t i=0 ; i< Data_Size ; i++){
		*((uint8_t*)P_dest++)=*((uint8_t*)P_src++);
	}
	uint32_t Bss_Size = (uint8_t*)&_E_bss - (uint8_t*)&_S_bss;
	P_dest=(uint8_t*)&_S_bss;
	for(uint32_t i=0 ; i< Bss_Size ; i++){
		*((uint8_t*)P_dest++)=(uint8_t)0;
	}
	
	main();
}