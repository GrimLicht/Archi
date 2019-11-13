#include <stdio.h>
#include <stdlib.h>

unsigned char rot (unsigned char n)
{
   n = (n << 4) | (n >> 4);
   n = ((n << 2) & 0xCC) | ((n >> 2) & 0x33);
   n = ((n << 1) & 0xAA) | ((n >> 1) & 0x55);
 
   return n;
}

unsigned char pop(unsigned char v)
{
 v = (v & 0x55) + ((v >> 1) & 0x55);
 v = (v & 0x33) + ((v >> 2) & 0x33);
 v = (v & 0x0F) + ((v >> 4) & 0x0F);
 return v;
 }
 
 unsigned char rot_left(unsigned char a, unsigned char r)
{
	
 return ((a << r) | (a >> (8 - r)));
 }


unsigned char aggregate(unsigned char v)
{
	unsigned r = 0;
	unsigned s = 0;
	unsigned char wb; //weak bit 
	
	while (v)
	{
		wb = v & 0x01;
		
		r <<= wb;
		
		rb |= wb;
		
		v >>= 1;
	}
	return r;
}


int main()
{
	unsigned char a;
	unsigned char r; 
	printf("Entrez le nombre à convertir: ");
	scanf("%d",&a);
	printf("\nLe nombre binaire inversé est = %d\n", rot(a));
	printf("\nLe nombre de bit à 1 est = %u\n", pop(a));
	printf("Entrez le nombre de decalage: ");
	scanf("%hhu",&r);	
	printf("\nLe nombre après rotation est = %d\n", rot_left(a,r));

	return 0;
}
