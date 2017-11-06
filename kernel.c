/*
*  kernel.c
*/

void disable_ints();
void enable_ints();
int check_A20();
void enable_A20();
void cls(char *vidptr);
void kprint(char *vidptr,char *str); 
unsigned long strlen(const char* str);

void kmain(void)
{
	const char *a20on = "A20 is enabled\n";
	const char *a20off = "A20 is disabled\n";
	const char *str = "My fucking first kernel\nDario Clavijo\n";

	char *vidptr = (char*)0xb8000; 	//video mem begins here.

	cls(vidptr);
	kprint(vidptr,str);

	if (check_A20() == 1) {
		kprint(vidptr,a20on);
	} else { 
		kprint(vidptr,a20off); 
	}

	//enable_A20();

	return 0;
}
