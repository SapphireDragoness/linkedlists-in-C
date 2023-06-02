#include <stdio.h>

int main(void)
{
	int a = 7;
	int *aPtr;
	
	aPtr = &a;
	
	printf("La variabile a contiene: %d\n",a);
	printf("La variabile a e' all'indirizzo: %p\n",&a);
	
	printf("La variabile a contiene: %d\n",*aPtr);
	
	*aPtr = *aPtr + 1;
	
	printf("La variabile a contiene: %d\n",a);
	
	(*aPtr)++;
	
	printf("La variabile a contiene: %d\n",a);
	
	return 1;
}