#include<stdio.h>
#include<string.h>
int main () {
	int a = 1, c;
	while(a==1) {
		printf("\n Insira a QUANTIDADE DE CARACTERES (letras): ");
		scanf("%d",&a);
		char b[a];
		printf("\n Escreva a PALAVRA: \n ");
		scanf("%s",&b);
		a = strlen(b);
		printf("\n Insira o NUMERO DE REPETICOES (sugestao: %d): ",a);
		scanf("%d",&a);
		int d=2, e=2, f=2;
		printf("\n Opcoes de Exibicao: \n\n 1. \n (0) Simples \n (1) Com ESPACO \n\n R: ");
		while(d>1 || d<0) {
			scanf("%d",&d);
		}
		printf("\n 2. \n (0) Simples \n (1) Com ENTER \n\n R: ");
		while(e>1 || e<0) {
			scanf("%d",&e);
		}
		printf("\n 3. \n (0) Simples \n (1) Com NUMERACAO \n\n R: ");
		while(f>1 || f<0) {
			scanf("%d",&f);
		}
		c = 2;
		while(c>1 || c<0) {
			printf("\n\n INICIAR?? (N=0 S=1) R: ");
			scanf("%d",&c);
		}
		if(c==1) {
			c = 3;
			while(c>2 || c<0) {
				printf("\n\n EM QUE LACO??? \n\n (0) FOR \n (1) WHILE \n (2) DO WHILE \n\n R: ");
				scanf("%d",&c);
			}
			c++;
		}
		if(c==1) {
			for(c=0; c<a; c++) {
				if(d==1) {printf(" ");}
				if(e==1) {printf("\n");}
				if(f==1) {printf("%d",c);}
				printf("%s",b);
			}
		}
		if(c==2) {
			c = 0;
			while(c<a) {
				if(d==1) {printf(" ");}
				if(e==1) {printf("\n");}
				if(f==1) {printf("%d",c);}
				printf("%s",b);
				c++;
			}
		}
		if(c==3) {
			do {
				if(d==1) {printf(" ");}
				if(e==1) {printf("\n");}
				if(f==1) {printf("%d",c);}
				printf("%s",b);
				c++;
			} while(c<a);
		}
		a = 2;
		while(a>1 || a<0) {
			printf("\n\n Reiniciar ??? N=0 S=1 R: ");
			scanf("%d",&a);
		}
	}
	return 0;
}
