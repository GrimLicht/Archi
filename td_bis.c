#include <stdio.h>
#include <stdlib.h>

unsigned char rot (unsigned char n)
{
   n = (n << 4) | (n >> 4);
   n = ((n << 2) & 0xCC) | ((n >> 2) & 0x33);
   n = ((n << 1) & 0xAA) | ((n >> 1) & 0x55);
 
   return n;
}

int main()
{
	int a;
	printf("Entrez le nombre à convertir: ");
	scanf("%d",&a);
	printf("\nLe nombre binaire est = %d\n", rot(a));
}
