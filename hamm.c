#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

unsigned char pop(unsigned char v)
{
	v = (v & 0x55) + ((v >> 1) & 0x55);
	v = (v & 0x33) + ((v >> 2) & 0x33);
	v = (v & 0x0F) + ((v >> 4) & 0x0F);
	return v;
 }
 
 int hamming (uint8_t a, uint8_t b)
{
	uint8_t c = a ^ b;
	return pop(c);
}

void writeb(unsigned char b){
    int i = 0;
    for(i=3; i>=0; i--)
        printf("%d",(b & (1<<i) ? 1 : 0));
    printf("\n");
}

int parite(uint8_t a)
{
	p = (a>>3)^((a<<1)>>3)^((a<<3)>>3)
	return p;
}

int parite2(uint8_t a)
{
	p = (a>>3)^((a<<2)>>3)^((a<<3)>>3)
	return p;
}

int parite3(uint8_t a)
{
	p = ((a<<1)>>3)^((a<<2)>>3)^((a<<3)>>3)
	return p;
}



int main(){
	int a = 16;
	int b = 16;
	printf("Entrez votre nombre en decimal (sur 4 bits) : ");
	scanf("%d",&a);
	while ((a > 15) || (a < 0))
	{
		printf("\nLe nombre n'est pas sur 4 bits\n");
		scanf("%d",&a);
	}
	writeb(a);
	
	printf("%d\n",bits_parite(a,b));
	exit(0);
}
