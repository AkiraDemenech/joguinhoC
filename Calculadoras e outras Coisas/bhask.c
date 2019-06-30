#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
/*

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute (hConsole, COR);

fflush(stdin);

168 X 44
120 X 30

*/

void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main () {
	int d=1, c, i, x, y, n=1, xv, yv, m;
	float e[3];
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	for(c=0; c<3; c++) {
		e[c] = rand()%(3+c);
		if(rand()%2==0) { e[c] = -e[c]; }
	}
	do {
		gotoxy(0,0);
		SetConsoleTextAttribute (hConsole, 14);
		printf("   ESC SAIR | < SELECIONAR > | ^ v INCREMENTAR | 0-9 ATRIBUIR | - INVERTER |");
		c = 10; if(n==1) { c++; c++; }
		SetConsoleTextAttribute (hConsole, c);
		printf("|  %d.x^2 ",e[0]);
		c = 10; if(n==2) { c++; c++; }
		SetConsoleTextAttribute (hConsole, c);
		if(e[1]>=0) { printf("+ "); }
		printf("%d.x ",e[1]);
		c = 10; if(n==3) { c++; c++; }
		SetConsoleTextAttribute (hConsole, c);
		if(e[2]>=0) { printf("+ "); }
		printf("%d \n",e[2]);
		if(d==1) {
			if(e[0]==0) {
				yv = 0;
				if(e[1]==0) {
					xv = 0;
				} else {
					xv = -(e[2])/(e[1]);
				}
			} else {
				d = (e[1]*e[1]) - (4*e[0]*e[2]);
				xv = -(e[1])/(2*e[0]);
				yv = (-d)/(4*e[0]);
				if(d>0) { yv=yv/2; }
			}
			srand(time(NULL)+xv+yv+d+n);
			for(y=yv+42; y>yv-42; y-=2) {
				for(x=xv-83; x<=xv+83; x++) {
					c = (e[0]*x*x) + (e[1]*x) + e[2];
					if(c%2==1) { c++; }
					if(c==y) {
						SetConsoleTextAttribute (hConsole, 15);
						printf("*");
					} else {
						if(x==0 || y==0) {
							SetConsoleTextAttribute (hConsole, 11);
							if(x==0 && y==0) {
								printf("+");
							} else {
								if(x==0) { printf("|"); }
								if(y==0) { printf("-"); }
							}
						} else {
							if(e[0]==0) {
								printf(" ");
							} else {
								if(e[0]>0) {
									if(y>c) {
										SetConsoleTextAttribute (hConsole, 15);
										printf(".");
									} else {
										printf(" ");
									}
								} else {
									if(y<c) {
										SetConsoleTextAttribute (hConsole, 15);
										printf(".");
									} else {
										printf(" ");
									}
								}
							}
						}
					}
				}
				printf("\n");
				fflush(stdin);
				if(kbhit()) {
					getch();
				}
				fflush(stdin);
			}
		}
		do {
			c = getch(); d = 0;
			if(c==224) { i = getch(); } else { i = 0; }
			if(c==68 || c==100 || i==77) { n++; d=2; }
			if(c==65 || c==97 || i==75) { n--; d=2; }
			if(n==4) { n = 1; } if(n==0) { n = 3; }
			if(c==87 || c==119 || i==72) { e[n-1]++; d++; }
			if(c==83 || c==115 || i==80) { e[n-1]--; d++; }
			if(c==43) { e[n-1]+=0.1; d++; }
			if(c==45) { e[n-1]-=0.1; d++; }
			if(c==48 || c==49) {
				m = e[n-1];
				e[n-1] = m + c - 48;
				d++;
			}
			if(c==79 || c==111) { e[n-1] = 0; d++; }
			if(c==73 || c==105) { e[n-1] = 1; d++; }
			if(c>49 && c<58) { e[n-1]+=c-48; d++; }
			if(c==45) { e[n-1] = -e[n-1]; d++; }
			if(c==27) { n = 0; d++; }
		} while(d==0);
	} while(n>0);
	return 0;
}
