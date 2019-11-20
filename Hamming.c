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

void writeb( unsigned char b){
    int i = 0;
    for(i=3; i>=0; i--)
        printf("%d",(b & (1<<i) ? 1 : 0));
     printf("\n");
}

int bits_parite2(uint8_t a){
	uint8_t z2;
	int a0,a2,a3;
	for(int i=3; i>=0; i--)
	{
		if (i==3) {a0 = (a & (1<<i) ? 1 : 0);}
		if (i==1) {a2 = (a & (1<<i) ? 1 : 0);}
		if (i==0) {a3 = (a & (1<<i) ? 1 : 0);}
	}
	z2 = a0 ^ a2 ^ a3;
	return z2;
}

int bits_parite1(uint8_t a){
	uint8_t z1;
	int a0,a1,a3;
	for(int i=3; i>=0; i--)
	{
		if (i==3) {a0 = (a & (1<<i) ? 1 : 0);}
		if (i==2) {a1 = (a & (1<<i) ? 1 : 0);}
		if (i==0) {a3 = (a & (1<<i) ? 1 : 0);}
	}
	z1 = a0 ^ a1 ^ a3;
	return z1;
}

int bits_parite3(uint8_t a){
	uint8_t z3;
	int a1,a2,a3;
	for(int i=3; i>=0; i--)
	{
		if (i==2) {a1 = (a & (1<<i) ? 1 : 0);}
		if (i==1) {a2 = (a & (1<<i) ? 1 : 0);}
		if (i==0) {a3 = (a & (1<<i) ? 1 : 0);}
	}
	z3 = a1 ^ a2 ^ a3;
	return z3;
}

void affiche(uint8_t z1,uint8_t z2,uint8_t z3, uint8_t a)
{
	int a0,a1,a2,a3;
	for(int i=3; i>=0; i--)
	{
		if (i==3) {a0 = (a & (1<<i) ? 1 : 0);}
		if (i==2) {a1 = (a & (1<<i) ? 1 : 0);}
		if (i==1) {a2 = (a & (1<<i) ? 1 : 0);}
		if (i==0) {a3 = (a & (1<<i) ? 1 : 0);}
	}
	printf("Nombre encoder : %d%d%d%d%d%d%d\n", z1,z2,a0,z3,a1,a2,a3);

}

int main(){
	int a, b;
	uint8_t z1,z2,z3;
	printf("Entrez votre nombre en decimal (sur 4 bits) :");
	scanf("%d",&a);
	printf("Entrez votre nombre en decimal (sur 4 bits) :");
	scanf("%d",&b);
	writeb(a);
	writeb(b);
	printf("Distance de hamming = %d\n",hamming(a,b));
	z1 = bits_parite1(a);
	z2 = bits_parite2(a);
	z3 = bits_parite3(a);
	affiche(z1,z2,z3,a);
	

	exit(0);
}
