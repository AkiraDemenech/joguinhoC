#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main () {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int c, f, s;
	do {
		srand(time(NULL));
		do {
			system("cls");
			SetConsoleTextAttribute (hConsole, 9+(rand()%7));
			printf("\n\n    NUM. FACES DO DADO: ");
			SetConsoleTextAttribute (hConsole, 9+(rand()%7));
			scanf("%d",&f);
		} while(f<2);
		sleep(1);
		SetConsoleTextAttribute (hConsole, 9+(rand()%7));
		printf("\n\n\a    TECLE 0 (ZERO) PARA PULAR O DADO \n    E QUALQUER OUTRO DIGITO PARA JOGAR \n");
		for(c=1, s=0; c<=f; c=c*10) { s++; }
		srand(time(NULL));
		do {
			int b=0, n=0, l=0, i;
			c = getch() - 48;
			if(c!=0) {
				if(kbhit()) {
					getch();
				}
				b = 1 + (rand()%7);
				n = b + 8;
				l = 1 + (rand()%f);
				gotoxy(0,7);
				printf("\n     ");
				SetConsoleTextAttribute (hConsole, b);
				for(c=0; c<s+4; c++) { printf("_"); }
				printf("\n    |");
				for(c=0; c<s+4; c++) { printf(" "); }
				printf("| \n    |  ");
				SetConsoleTextAttribute (hConsole, n);
				for(c=0, i=1; i<=l; i=i*10) { c++; }
				for(i=0; i<s-c; i++) { printf("0"); }
				printf("%d",l);
				SetConsoleTextAttribute (hConsole, b);
				printf("  | \n    |");
				for(c=0; c<s+4; c++) { printf("_"); }
				printf("| \n\n "); sleep(1);
			}
		} while(c!=0);
		SetConsoleTextAttribute (hConsole, 9+(rand()%7));
		printf("\n\n\n    1/0 ? ");
		do { c = getch() - 48; } while(c!=0 && c!=1);
	} while(c>0);
	return 0;
}
