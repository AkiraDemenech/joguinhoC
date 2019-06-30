#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ans (int n) {
	int a = n;
	if(n<10) {
		do {
			a = getch() - 48;
		} while(a<0 || a>=n);
	}
	return a;
}

int isDigit(char c) {
	if(c>=48 && c<58)
		return 1;
	return 0;
}

int isLetter (char c) {
	if(c>=97) c -= 32;
	if(c>=65 && c<91) return 1;
	return 0;
}

int isLetterOrDigit (char c) {
	return isLetter (c) + isDigit (c);
}

int letter2int (char c) {
	int a = 0;
	if(isLetter(c)) {
		if(c>=97) c -= 32;
		a = c - 65;
	}
	return a;
}

int char2num (char c) {
	int a = -1;
	if(isLetterOrDigit(c)) {
		a = c - 48;
		if(isLetter(c))
			a = 10 + letter2int(c);
	}
	return a;
}

int digit (int n) {
	return (11 - (n%11));
}

int digit01 (int cpf[]) {
	int c, i = 10, s = 0;
	for(c=0; c<9; c++) {
		s += cpf[c]*i;
		i--;
	}
	s = digit(s);
	if(s>9) s = 0;
	return s;
}

int digit02 (int cpf[]) {
	int c, i = 11, s = 0;
	for(c=0; c<10; c++) {
		s += cpf[c]*i;
		i--;
	}
	s = digit(s);
	if(s>9) s = 0;
	return s;
}

int valid01 (int cpf[]) {
	int a = 0;
	if(cpf[9]==digit01(cpf)) a = 1;
	return a;
}

int valid02 (int cpf[]) {
	int a = 0;
	if(cpf[10]==digit02(cpf)) a = 1;
	return a;
}

void printUF (int cpf[]) {
	switch (cpf[8]) {
		case 0: printf("Rio Grande do Sul (RS)"); break;
		case 1: printf("Distrito Federal (DF), Goias (GO), Mato Grosso (MT), Mato Grosso do Sul (MS) e Tocantins (TO)"); break;
		case 2: printf("Amazonas (AM), Para (PA), Roraima (RR), Amapa (AP), Acre (AC) e Rondonia (RO)"); break;
		case 3: printf("Ceara (CE), Maranhao (MA) e Piaui (PI)"); break;
		case 4: printf("Paraiba (PB), Pernambuco (PE), Alagoas (AL) e Rio Grande do Norte (RN)"); break;
		case 5: printf("Bahia (BA) e Sergipe (SE)"); break;
		case 6: printf("Minas Gerais (MG)"); break;
		case 7: printf("Rio de Janeiro (RJ) e Espirito Santo (ES)"); break;
		case 8: printf("Sao Paulo (SP)"); break;
		case 9: printf("Parana (PR) e Santa Catarina (SC)"); break;
	}
}

int validadorCpf (char cpf[]) {
	int c, i = 0;
	for(c=strlen(cpf)-1; c>=0; c--)
		if(isDigit(cpf[c])) i++;
		
	int num[i];
	for(c=strlen(cpf)-1; c>=0; c--)
		if(isDigit(cpf[c]))
			num[--i] = char2num (cpf[c]);
			
	printf("\n%s\n",cpf);
	for(c=0; c<11; c++)
		printf("%d",num[c]);
		
	printf("\n");
	printUF(num);
	printf("\n");
	
	return valid01(num) + valid02(num);
}

int main () {
	int c = 0;
	char cod[14] = "xxx.xxx.xxX-yY";
	do {
		printf("\n");
		scanf("%s",cod);
		if(validadorCpf(cod)==0)
			printf("IN");
			
		printf("VALIDO");
		c = ans(2);
	} while(c!=0);
	return 0;
}
