/* Linker_script cortexM3
by Eng.mohamed salah fathy
*/
MEMORY
{
	ROM(RX) : ORIGIN = 0X08000000 , LENGTH = 128K
	RAM(RWX) : ORIGIN = 0X20000000 , LENGTH = 20K
}
SECTIONS
{
	.text : {
		*(.vectors*)
		. = ALIGN(4) ;
		*(.text)
		. = ALIGN(4) ;
		*(.rodata)
		. = ALIGN(4) ;
		_E_text = . ;
	}>ROM

	.data : {
		_S_data = . ;
		*(.data)
		. = ALIGN(4) ;
		_E_data = . ;
	}> RAM AT> ROM
	
	.bss : {
		_S_bss = . ;
		*(.bss*)
		. = ALIGN(4) ;
		_E_bss = . ;
		. = . + 0x1500 ;
		_stack_top = . ;
	}> RAM
}