/*
*  kernel.c
*/

void cls(char *vidptr);
void kprint(char *vidptr,char *str); 
unsigned long strlen(const char* str);

void kmain(void)
{
	const char *str = "My fucking first kernel\nDario Clavijo";
	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	cls(vidptr);
	kprint(vidptr,str);

	return 0;
}
