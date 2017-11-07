[bits 32]
global enable_ints
global disable_ints


enable_ints:
	sti
	
disable_ints:
	cli
