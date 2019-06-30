#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void color (int cor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, cor);
}

void gotoxy (int x, int y)
{
	COORD cart = {0, 0};
    cart.X = x;
	cart.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cart);
}

int dec (int bin) {
	int d = 0, dois = 1;
	while(bin>0) {
		d += dois*(bin%10);
		bin /= 10;
		dois *= 2;
	}
	return d;
}

char gene (int index) {
	char x64[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+-";
	return x64[index%64];
}
int genValue (char gen) {
	int c, v = -1;
	for(c=0; c<64; c++) {
		if(gene(c)==gen) {
			v = c;
			c = 64;
		}
	}
	return v;
}

#define LADO 27
#define FITA 10

struct cell {
	int vida;
	int exp;
	int tRep;
	int chOc;
	int chMut;
	int disp;
	char dna[FITA];
};

struct cell cultura[LADO][LADO];

int dnaValue (int x, int y, int bit0, int bitf) {
	int bin = 0; // valor binário entre os bit O e F
	int c, i, b;
	char dna2[6*strlen(cultura[x%LADO][y%LADO].dna)];
	for(c=0; c<strlen(cultura[x%LADO][y%LADO].dna); c++) {
		b = genValue(cultura[x%LADO][y%LADO].dna[c]); // valor decimal de um gene x64
		for(i=0; i<6; i++) {
			dna2[c+i] = 48 + (b%2);
			b /= 2;
		}
	}
	for(i=1, c=bit0%strlen(dna2); c<bitf%strlen(dna2); c++) {
		bin += i*(dna2[c]-48);
		i *= 10;
	}
	return bin;
}

void zero () {
	int x, y, c;
	for(x=0; x<LADO; x++) {
		for(y=0; y<LADO; y++) {
			cultura[x][y].vida = 0;
			cultura[x][y].disp = 1;
			for(c=0; c<FITA; c++) {
				cultura[x][y].dna[c] = gene(0);
			}
		}
	}
}

void ones (int n, int seed) {
	int c, i, x, y;
	srand(seed);
	for(c=0; c<n; c++) {
		srand(seed + rand() + c + x + y);
		do {
			x = rand()%LADO;
			y = rand()%LADO;
		} while(cultura[x][y].vida!=0);
		cultura[x][y].vida = 1;
		do {
			for(i=0; i<FITA; i++) {
				cultura[x][y].dna[i] = gene(rand()+i+c);
			}
		} while(dnaValue(x,y,0,FITA)==0);
	}
}

void registrar () {
	int x, y;
	for(x=0; x<LADO; x++) {
		for(y=0; y<LADO; y++) {
			if(cultura[x][y].vida>0) {
				cultura[x][y].tRep = dec(dnaValue(x,y,4,13));
				cultura[x][y].chOc = dec(dnaValue(x,y,16,26));
				cultura[x][y].chMut = dec(dnaValue(x,y,26,32));
				cultura[x][y].exp = dec(dnaValue(x,y,42,48));
			}
		}
	}
}

int censo () {
	int n=0, x, y;
	for(x=0; x<LADO; x++) {
		for(y=0; y<LADO; y++) {
			if(cultura[x][y].vida>0)
				n++;
		}
	}
	return n;
}

void newDna (int x, int y, int seed, int x0, int y0) {
	cultura[x][y].vida = 1;
	int c;
	for(c=0; c<FITA; c++) {
		srand(seed+c+rand());
		cultura[x][y].dna[c] = (rand()%64<cultura[x0][y0].chMut)?gene(rand()):cultura[x0][y0].dna[c];
	}
}

void reproduzir (int x, int y, int seed) {
	
	int d = 0;
	
	while(d<4) {
		
		switch (seed%4) {
			
			case 0:
				if(y>0)
					if(cultura[x][y-1].vida==0) {
						newDna(x,y-1,seed+d,x,y);
						d = 4;
					}
				break;
			
			case 1:
				if(x<LADO-1)
					if(cultura[x+1][y].vida==0) {
						newDna(x+1,y,seed+d,x,y);
						d = 4;
					}
				break;
			
			case 2:
				if(y<LADO-1)
					if(cultura[x][y+1].vida==0) {
						newDna(x,y+1,seed+d,x,y);
						d = 4;
					}
				break;
			
			case 3:
				if(x>0)
					if(cultura[x-1][y].vida==0) {
						newDna(x-1,y,seed+d,x,y);
						d = 4;
					}
				break;
			
		}
		
		seed++;
		d++;
	}
}

void principal () {
	
	system("cls");
	system("color 0F");
	
	printf("    Seed do Experimento: ");
	int seed;
	scanf("%d",&seed);
	if(seed<1)
		seed = time(NULL);
	
	srand(seed);
	
	printf("    Quantidade de Individuos: ");
	int populacaoInicial;
	scanf("%d",&populacaoInicial);
	if(populacaoInicial<1)
		populacaoInicial = 1 + (rand()%(LADO*LADO));
	
	system("cls");
	
	char rna[FITA];
	int c = 0, pop, x, y;
	zero(); // reset das instâncias globais
	ones(populacaoInicial, seed); // posicionamento dos primeiros indivíduos
	srand(seed);
	
	do {
		
		pop = censo(); // contagem dos indivíduos vivos
		srand(seed+rand()+c+pop); // randomização
		gotoxy(0,0);
		color(15);
		printf(" Seed: %d | %do | %03d ind | %d Ciclos \n ",seed,populacaoInicial,pop,c);
		
		for(x=0; x<LADO; x++) {
			printf("-");
		}
		printf("\n");
		
		for(y=0; y<LADO; y++) {
			
			color(15);
			printf("|");
			
			for(x=0; x<LADO; x++) {
				if(cultura[x][y].vida==0) {
					color(0);
					printf(" ");
				} else {
					color((17*dec(dnaValue(x,y,0,4)))-1);
					printf("%c",cultura[x][y].dna[1]);
					strcpy(rna, cultura[x][y].dna);
				}
			}
			color(15);
			printf("| %s \n",rna);
		}
		
		printf(" ");
		for(x=0; x<LADO; x++) {
			printf("-");
		}
		
		registrar(); // registro nas variáveis de caracterização
		
		for(x=0; x<LADO; x++) {
			
			srand(seed+rand()+c+pop+x);
			
			for(y=0; y<LADO; y++) {
				
				if(cultura[x][y].vida!=0) {
					
					if(cultura[x][y].vida%(cultura[x][y].tRep+1)) {
						// reprodução
						reproduzir(x,y,rand());
					}
					
					cultura[x][y].vida++; // aniversário
					
					if(cultura[x][y].vida>cultura[x][y].exp && rand()%1024<cultura[x][y].chOc)
						cultura[x][y].vida = -1; // morrer
					
				}
				
			}
		}
		
		c++; // incremento
		
		if(kbhit()) {
			if(getch()==27) {
				system("color F0");
				printf("\n    CONFIRMAR FUGA: enter \n");
				if(getch()==13) {
					pop = 0;
				} else {
					system("cls");
					system("color 0F");
				}
			}
		}
		
		//Sleep(42);
		
	} while(pop>0);
	
}

int stay () {
	color(16*12);
	printf("\n\a    ESC para SAIR \n");
	return (getch()==27)?0:1;
}

int main () {
	do {
		principal();
	} while(stay());
	return 0;
}
