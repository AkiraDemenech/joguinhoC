#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>

int main () {
	int x, y, z, p, c, i;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do {
		SetConsoleTextAttribute (hConsole, 15);
		do {
			system("cls");
			printf("\n\n    TAMANHO (x,y) (1=random): ");
			scanf("%d %d",&x,&y);
			srand(time(NULL));
			if(x<2) { x=2+(rand()%110); }
			if(y<2) { y=2+(rand()%25); }
		} while(x<2 || y<2);
		int pix[y][x];
		printf("\n\n    COLORIDO? \n  0) Preto e Branco \n  1) Escala de Cinza \n  2) Colorido");
		do {
			p = getch() - 48;
		} while(p<0 || p>2);
		printf("\n\n    SEED (0=random): ");
		scanf("%d",&c);
		if(c<0) { c=-c; } if(c==0) { c=time(NULL)+rand(); }
		printf("\n    %d x %d , SEED %d \n\n     ",x,y,c);
		srand(c); sleep(1);
		for(c=0; c<x+2; c++) { printf("_"); }
		printf("\n    | ");
		for(c=0; c<x; c++) { printf(" "); }
		printf(" | \n    | ");
		for(c=0; c<y; c++) {
			for(i=0; i<x; i++) {
				pix[c][i]=rand()%4;
				switch (p) {
					case 0: SetConsoleTextAttribute (hConsole, (rand()%2)*15); break;
					case 1:
						switch (rand()%4) {
							case 0: p=0; break;
							case 1: p=8; break;
							case 2: p=7; break;
							case 3: p=15; break;
						}
						SetConsoleTextAttribute (hConsole, p);
						p=1;
					break;
					case 2: SetConsoleTextAttribute (hConsole, rand()%16); break;
				}
				printf("#");
			}
			SetConsoleTextAttribute (hConsole, 15);
			printf(" | \n    |"); if(c<y-1) { printf(" "); }
		}
		for(c=0; c<x+2; c++) {
			printf("_");
		}
		printf("| \n    ");
		sleep(1);
		printf("\n\n        1/0? ");
		do {
			fflush(stdin);
			z=getch()-48;
			fflush(stdin);
		} while(z!=0 && z!=1);
		sleep(z);
	} while(z==1);
	return 0;
}
