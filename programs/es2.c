#include <stdio.h>

int main(void)
{
	int v[10]; // [0] .. [9]
	int *vPtr;
	
	vPtr = v; // v[0]
	
	v[0] = 10;
	v[1] = 15;
	
	printf("vPtr contiene: %d\n",*vPtr);
	
	++vPtr;
	
	printf("vPtr contiene: %d\n",*vPtr);
	
	*vPtr = *vPtr + 1;
	
	printf("v[1] contiene: %d\n",v[1]);
	
	printf("vPtr contiene: %d\n",*vPtr);
	
	return 1;
}