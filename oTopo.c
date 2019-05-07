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
void clean () {
	int c;
	for(c=0; c<3; c++) {
		fflush(stdin);
		if(kbhit()) {
			c = getch()%2;
		}
		fflush(stdin);
	}
}
void pcolor(int cor) {
	int c = 0;
	switch (cor) {
		case 15: c=15; break;
		case 14: c= 7; break;
		case 13: c= 8; break;
		case 12: c= 5; break;
		case 11: c=13; break;
		case 10: c=12; break;
		case 9 : c= 4; break;
		case 8 : c=14; break;
		case 7 : c= 6; break;
		case 6 : c=10; break;
		case 5 : c= 2; break;
		case 4 : c= 3; break;
		case 3 : c=11; break;
		case 2 : c= 9; break;
		case 1 : c= 1; break;
	}
	color(c);
}
void color (int cor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, cor);
}
int scan () {
	int num;
	color(11);
	scanf("%d",&num);
	color(10);
	return (num);
}
int main () {
	int sp[167][42], sd, c, b, n, i, x, y, m;
	do {
		system("cls");
		color(10);
		printf("\n\n    SEED (0=random): ");
		sd = scan();
		if(sd<=0) { sd = time(NULL); }
		srand(sd);
		printf("\n\n    BASES (0=random): ");
		b = scan(); system("cls");
		if(b<=0) { b = 1 + (rand()%7014); }
		for(y=0; y<42; y++) {
			for(x=0; x<167; x++) {
				sp[x][y] = 0;
			}
		}
		for(c=0; c<b; c++) {
			printf(" . ");
			do {
				x = rand()%167;
				y = rand()%42;
			} while(sp[x][y]==1);
			sp[x][y] = 1;
		}
		srand(sd);
		for(c=2, n=1; n>0; c++) {
			srand(sd+rand());
			printf("\n    %d",c);
			for(x=0, n=0; x<167; x++) {
				for(y=0; y<42; y++) {
					if(sp[x][y]==0) {
						n++;
						if(rand()%4==0) {
							if(rand()%2==0) {
								if(x<166) {
									if(sp[x+1][y]>0 && sp[x+1][y]<c) {
										sp[x][y] = c;
									}
								}
								if(y<41) {
									if(sp[x][y+1]>0 && sp[x][y+1]<c) {
										sp[x][y] = c;
									}
								}
							} else {
								if(x>0) {
									if(sp[x-1][y]>0 && sp[x-1][y]<c) {
										sp[x][y] = c;
									}
								}
								if(y>0) {
									if(sp[x][y-1]>0 && sp[x][y-1]<c) {
										sp[x][y] = c;
									}
								}
							}
							if(rand()%3==0) {
								if(x<165) {
									if(sp[x+2][y]>0 && sp[x+2][y]<c) {
										sp[x][y] = c;
									}
								}
								if(y<40) {
									if(sp[x][y+2]>0 && sp[x][y+2]<c) {
										sp[x][y] = c;
									}
								}
								if(x>1) {
									if(sp[x-2][y]>0 && sp[x-2][y]<c) {
										sp[x][y] = c;
									}
								}
								if(y>1) {
									if(sp[x][y-2]>0 && sp[x][y-2]<c) {
										sp[x][y] = c;
									}
								}
							}
						}
					}
				}
			}
		}
		n = c + 1; m = n; system("cls"); printf("\a");
		char nab[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		do {
			gotoxy(0,0);
			c = m/15; if(c>62) { c=62; }
			for(y=0; y<=41; y++) {
				for(x=0; x<=166; x++) {
					if(sp[x][y]<=n) {
						pcolor(15-((sp[x][y]/c)%15));
						printf("%c",nab[(sp[x][y]-1)%c]);
					} else {
						printf(" ");
					}
				}
				printf("\n");
			}
			color(15);
			printf("\n  N %d / %d  ||  BASES: %d",n,m,b);
			do {
				c = 0; y = 0;
				x = getch();
				if(x==224 || x==55) {
					y = getch();
				}
				if(x==65 || x==97 || y==75 || x==45 || x==115 || x==83 || y==80) {
					if(n>1) {
						n--; c++;
					}
				}
				if(x==68 || x==100 || y==77 || x==43 || x==119 || x==87 || y==72) {
					if(n<m) {
						n++; c++;
					}
				}
				if((x>48 && x<58) || (y>48 && y<58)) {
					if(x==55) {
						n+=(y-48);
					} else {
						n+=(x-48);
					}
					c++;
				}
				if(x==13 || x==32) {
					n+=10; c++;
				}
				if(x==8) {
					n-=10; c++;
					if(n<0) {
						n = 1;
					}
				}
				if(n>m) {
					n = m;
				}
				if(x==110 || x==78) {
					color(15);
					printf("  -->  ");
					n = scan();
					if(n<=0) {
						n = 1;
					}
					system("cls");
					c++;
				}
				if(x==109 || x==77) {
					n = m; c++;
				}
				if(y==48 || x==48 || x==79 || x==111 || x==27) {
					n = 0; if(x==27) { n-=42; } c++;
				}
				if(x==105 || x==73) {
					n = 1; c++;
				}
			} while(c==0);
		} while(n>0);
	} while(n==0);
	return 0;
}
