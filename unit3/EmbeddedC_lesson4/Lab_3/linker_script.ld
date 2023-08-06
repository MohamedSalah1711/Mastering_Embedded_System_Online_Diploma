MEMORY
{
flash(rx) : ORIGIN = 0x00000000, LENGTH = 512M
sram(rwx) : ORIGIN = 0x20000000, LENGTH = 512M
}
SECTIONS
{
	.text : {
		*(.vector*)
		*(.text*)
		*(.rodata)
		_E_text = .;
	}>flash
	.data : {
		_S_data = .; 
		*(.data)
		_E_data = .;
		. = ALIGN(4);
	}
	.bss : {
		_S_bss = .;
		*(.bss)
		_E_bss = .;
	}>sram



}