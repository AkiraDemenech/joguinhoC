#include<stdio.h>

int main () {
	while(1>0) {
		float a, b, c;
		scanf("%f %f %f",&a,&b,&c);
		if(a<b+c && b<a+c && c<a+b) {
			printf("E UM TRIANGULO ");
			if(a==b || b==c || a==c) {
				if(a==b && b==c ) {
					printf("EQUILATERO");
				} else {
					printf("ISOSCELES");
				}
			} else {
				printf("ESCALENO ");
				if(a*a==b*b+c*c || b*b==a*a+c*c || c*c==b*b+a*a) {
					printf("RETANGULO");
				}
			}
		} else {
			printf("NAO E TRIANGULO");
		}
		getch();
		printf("\n");
	}
	return 0;
}
