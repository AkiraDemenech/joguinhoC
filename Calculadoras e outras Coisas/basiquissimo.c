#include<stdio.h>
float a, b, c;
float soma (float a, float b) {
	c = a + b;
	return (c);
}
float subtrai (float a, float b) {
	c = a - b;
	return (c);
}
float multiplica (float a, float b) {
	c = a*b;
	return (c);
}
float divide (float a, float b) {
	c = a/b;
	return (c);
}
int main () {
	printf("soma: ");
	scanf("%f %f",&a,&b);
	soma(a,b);
	printf("%f \nsubtrai: ",c);
	scanf("%f %f",&a,&b);
	subtrai(a,b);
	printf("%f \nmultiplica: ",c);
	scanf("%f %f",&a,&b);
	multiplica(a,b);
	printf("%f \ndivide: ",c);
	scanf("%f %f",&a,&b);
	divide(a,b);
	printf("%f",c);
	return 0;
}
