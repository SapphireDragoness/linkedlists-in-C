#include <stdio.h>

void stringa_leggi(char *sPtr);

int main(void)
{
	char s1[] = "Ciao a tutti";
	
	stringa_leggi(s1);
	
	printf("s1 = %s \n", s1);
	
	return 1;
}

void stringa_leggi(char *sPtr) // [0]
{
	while(*sPtr!='\0')
	{
		if (*sPtr==' ')
		{
			*sPtr='_';
		}
		printf("Carattere: %c\n", *sPtr);
		++sPtr;
	}
}