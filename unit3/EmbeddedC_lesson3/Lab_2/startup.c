#include <stdint.h>
extern int main();
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
extern uint32_t _stack_top;
void Reset_Handler(void);
void NMI_Handler()__attribute__((weak,alias("Default_Handler")));
void H_fault_Handler()__attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler()__attribute__((weak,alias("Default_Handler")));
void Bus_Fault()__attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler()__attribute__((weak,alias("Default_Handler")));
void Default_Handler(){
	Reset_Handler();
}
uint32_t vectors[] __attribute__((section(".vectors"))) ={
	(uint32_t)&_stack_top,
	(uint32_t)&Reset_Handler,	
	(uint32_t)&NMI_Handler,
	(uint32_t)&H_fault_Handler,
	(uint32_t)&MM_Fault_Handler,
	(uint32_t)&Bus_Fault,
	(uint32_t)&Usage_Fault_Handler
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