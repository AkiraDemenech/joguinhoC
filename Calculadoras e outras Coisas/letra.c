#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<ctype.h>
void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main () {
	srand(time(NULL));
	int i=rand(), p, alfa[26], c=rand(), b=-1; system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, 15);
	printf("\n    O SOLETRADOR \n\n        Aperte QUALQUER tecla para Continuar. \n    Aperte 0 (zero) para SAIR \n    Aperte 1 para Reiniciar \n    Aperte P para sortear letras do Alfabeto Portugues");
	do {
		fflush(stdin);
		p = getch()-48; gotoxy(0,0);
		char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		SetConsoleTextAttribute (hConsole, 14+(rand()%2));
		do { i = rand()%26; if(rand()%4==0) { srand(rand()+i+p); } } while((p==32 || p==64) && (i==10 || i==22 || i==24));
		printf("\a     ");
		SetConsoleTextAttribute (hConsole, 1+(time(NULL)%15));
		for(c=0; c<53; c++) { printf("_"); }
		printf("\n    | ");
		for(c=0; c<52; c++) { printf(" "); }
		printf("| \n    | ");
		for(c=0; c<260; c++) {
			if(rand()%2==0) { if(i>26) { i-=26; } } else { if(i<26) { i+=26; } }
			if(rand()%13==0) { srand(time(NULL)+rand()+c+i); }
			SetConsoleTextAttribute (hConsole, 1+(rand()%15));
			printf("%c ",abc[i]);
			SetConsoleTextAttribute (hConsole, 1+(time(NULL)%15));
			if(c%26==25) { printf("| \n    |");
			if(c<259) { printf(" "); } }
			if(kbhit()) {
				getch();
			}
		}
		for(c=0; c<53; c++) { printf("_"); } printf("| \n\n      ");
		b++; if(b==26 || p==1) { b=0; }
		if(b>0) {
			do {
				if(i>25) { i = rand()%26; }
				for(c=b-1; c>=0; c--) {
					if(rand()%4==0) { srand(time(NULL)+rand()); }
					if(i==alfa[c]) { i=26; c=0; }
				}
			} while(i>25);
		}
		if(i>26) { i-=26; }
		alfa[b] = i;
		SetConsoleTextAttribute (hConsole, 14+(rand()%2));
		for(c=b-1; c>=0; c--) { printf("%c ",abc[alfa[c]]); }
		printf("- \n     ");
		SetConsoleTextAttribute (hConsole, 1+((time(NULL)+i)%15));
		for(c=0; c<53; c++) { printf("_"); }
		printf("\n    | ");
		for(c=0; c<52; c++) { printf(" "); }
		printf("| \n    | "); 
		for(c=0; c<260; c++) {
			if(rand()%13==0) { srand(time(NULL)+rand()+c+i); }
			SetConsoleTextAttribute (hConsole, 1+(rand()%15));
			if(rand()%2==0) { if(i<26) { i+=26; } }
			printf("%c ",abc[i]);
			if(i>26) { i-=26; }
			SetConsoleTextAttribute (hConsole, 1+((time(NULL)+i)%15));
			if(c%26==25) { printf("| \n    |");
			if(c<259) { printf(" "); } }
			if(kbhit()) {
				getch();
			}
		}
		for(c=0; c<53; c++) { printf("_"); } printf("|");
		sleep(1);
	} while(p!=0);
	return 0;
}
