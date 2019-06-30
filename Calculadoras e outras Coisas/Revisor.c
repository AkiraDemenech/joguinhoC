#include<stdio.h>
#include<string.h>
int b, c, d = 0;
char a, n[164];
int d4(char n[], int b) { for(c=1; c<=b; c++) { if(n[c]=='a' || n[c]=='A') { d++; } } return(d); }
void c3(char n[], int b) { printf("\n ao contrario: "); for(c=b; c>=0; c--) { printf("%c",n[c]); } }
void b2(char n[], int b) { printf("\n so Letras Impares: "); for(c=0; c<=b; c++) { if(c%2==0) { printf("%c",n[c]); } } }
int a1(char n[]) { b = strlen(n); return(b); }
int main () { do {
	printf("\n Insira seu NOME: \n");
	gets(n);
	a1(n);
	printf("\n %d letras",b);
	b2(n,b);
	c3(n,b);
	d4(n,b);
	printf("\n %d letras A",d);
	printf("\n Reiniciar Registrador? s1m na0 A = ");
	scanf("%c",&a);
} while(a=='1' || a=='s' || a=='S' || a=='y' || a=='Y'); return 0; }
