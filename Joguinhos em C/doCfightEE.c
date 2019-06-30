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
void under (int p, int r) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int c; srand(r+p+time(NULL));
	for(c=0; c<p; c++) {
		r=0;
		if(rand()%2==0) {
			switch (rand()%3) {
				case 0: r=7; break;
				case 1: r=8; break;
				case 2: r=15; break;
			}
		}
		SetConsoleTextAttribute (hConsole, r);
		printf(".");
	}
}
void print (int c) {
	switch (c) {
		case 0: printf("^"); break;
		case 1: printf(">"); break;
		case 2: printf("v"); break;
		case 3: printf("<"); break;
		case 4: printf(" "); break;
	}
}
int mod (int n) {
	if(n<0) { n = -n; }
	return (n);
}
void clean () {
	int c, p;
	for(c=0; c<3; c++) {
		fflush(stdin);
		if(kbhit()) {
			p = getch();
		}
		fflush(stdin);
	}
}
void game () {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/* NUM     */ int c, p, i, n, x, y, t, h, m, s, to, cl;
	/* PLAYER  */ int xp, yp, cp, lp, dx, dy, sp[666][666];
	/* NPCs    */ int fx[101], fy[101], fc[101], ex[100], ey[100], ec[100], fa[100], ea[100];
	do {
		srand(time(NULL));
		xp=332; yp=333; lp=1; cp=3; cl=0;
		for(c=0; c<100; c++) {
			ea[c] = rand()%101;
			ec[c] = rand()%4;
			do {
				ex[c] = 327-(rand()%66);
				ey[c] = 322+(rand()%33);
				for(i=c-1; i>=0; i--) {
					if(ex[c]==ex[i] && ey[c]==ey[i]) { ex[c] = 0; }
				}
			} while(ex[c]==0);
			fa[c] = rand()%100;
			fc[c] = rand()%4;
			do {
				fx[c] = 327+(rand()%66);
				fy[c] = 322+(rand()%33);
				for(i=c-1; i>=0; i--) {
					if(fx[c]==fx[i] && fy[c]==fy[i]) { fx[c] = 0; }
				}
			} while(fx[c]==0);
		}
		srand(time(NULL)+fx[100]+fy[100]);
		for(y=0; y<666; y++) {
			for(x=0; x<666; x++) {
				sp[y][x] = rand()%4;
				if(rand()%3>0) { sp[y][x] = 0; }
			}
		}
		t = time(NULL); system("cls");
		do {
			srand((time(NULL)+xp+yp)*lp);
			gotoxy(0,0); s=time(NULL)-t;
			for(m=0; s>=60; m++) { s-=60; }
			for(h=0; m>=60; h++) { m-=60; }
			SetConsoleTextAttribute (hConsole, 14);
			printf("\n\n      %d Hrs %d Min %d sec (%d s) |",h,m,s,time(NULL)-t);
			SetConsoleTextAttribute (hConsole, 15);
			printf("| %d CICLES |",cl);
			SetConsoleTextAttribute (hConsole, 15);
			printf("| POSITION: %d %d |",xp,yp);
			SetConsoleTextAttribute (hConsole, 9);
			printf("| %do CHANCE              ",lp);
			SetConsoleTextAttribute (hConsole, 12);
			for(c=0, i=0; c<100; c++) { if(ec[c]<4) { i++; } }
			printf("\n      %d",i);
			SetConsoleTextAttribute (hConsole, 14); printf(" x ");
			SetConsoleTextAttribute (hConsole, 10);
			for(c=0, i=0; c<100; c++) { if(fc[c]<4) { i++; } }
			printf("%d     \n\n    ",i);
			for(y=yp-11; y<=yp+11; y++) {
				for(x=xp-33; x<=xp+33; x++) {
					srand(time(NULL)+x+y);
					if(x<0 || x>665 || y<0 || y>665) {
						i = rand()%4;
						if(rand()%3>0) { i = 0; }
						switch (i) {
							case 0: i=0; break;
							case 1: i=8; break;
							case 2: i=7; break;
							case 3: i=15; break;
						}
						SetConsoleTextAttribute (hConsole, i);
						printf(".");
					} else {
						if(sp[y][x]>=0) {
							if(sp[y][x]<4) {
								switch (sp[y][x]) {
									case 0: i=0; break;
									case 1: i=8; break;
									case 2: i=7; break;
									case 3: i=15; break;
								}
								SetConsoleTextAttribute (hConsole, i);
								printf(".");
								if(rand()%4<sp[y][x] && rand()%2==0) { sp[y][x]--; }
								if(rand()%3==0) { sp[y][x] = rand()%4; }
							} else {
								i = (sp[y][x]-4)/2;
								switch (i) {
									case 0: c=3+((rand()%2)*8); break;
									case 1: c=2+((rand()%2)*8); break;
									case 2: c=4+((rand()%2)*8); break;
								}
								SetConsoleTextAttribute (hConsole, c);
								if(sp[y][x]%2==0) {
									printf("-");
								} else {
									printf("|");
								}
							}
						} else {
							switch (sp[y][x]) {
								case -1:
									for(c=0, i=100; i==100 && c<100; c++) {
										if(ex[c]==x && ey[c]==y) { i = c; }
									}
									SetConsoleTextAttribute (hConsole, 12);
									print(ec[i]);
								break;
								case -2:
									for(c=0, i=100; i==100 && c<100; c++) {
										if(fx[c]==x && fy[c]==y) { i = c; }
									}
									SetConsoleTextAttribute (hConsole, 10);
									print(fc[i]);
								break;
								case -3:
									SetConsoleTextAttribute (hConsole, 11);
									print(cp);
								break;
							}
							sp[y][x] = rand()%4;
							if(rand()%2==0) { sp[y][x] = 0; }
						}
					}
				}
				printf("\n    ");
				clean();
			}
			for(y=0; y<666; y++) {
				for(x=0; x<666; x++) {
					if(sp[y][x]>4) {
						if(rand()%5>0) {
							sp[y][x] = rand()%4;
							if(rand()%3==0) {
								sp[y][x] = 0;
							}
						}
					} 
				}
			}
			to = time(NULL);
			while(time(NULL)-to<1) {
				fflush(stdin);
				if(cp%2) {
					dy = 0;
					if(cp==1) {
						dx = 1;
					} else {
						dx = -1;
					}
				} else {
					dx = 0;
					if(cp==2) {
						dy = 1;
					} else {
						dy = -1;
					}
				}
				if(kbhit()) {
					c = getch(); i = 0;
					if(c==224) { i = getch(); }
					if(i==80 || c==83 || c==115) { to--; xp+=dx; yp+=dy; }
					if(i==77 || c==68 || c==100) { to--; cp=(cp+1)%4; }
					if(i==72 || c==87 || c==119) { to--; cp=(cp+2)%4; }
					if(i==75 || c==65 || c==97) { to--; cp=(cp+3)%4; }
					if(c==73 || c==105) {
						for(c=0, xp=0, yp=0, n=0; c<100; c++) {
							if(ec[c]<4) {
								n++;
								xp+=ex[c];
								yp+=ey[c];
							}
							if(fc[c]<4) {
								n++;
								xp+=fx[c];
								yp+=fy[c];
							}
						}
						xp=xp/n;
						yp=yp/n;
					}
					if(c==80 || c==112) {
						int ti = time(NULL)-t;
						gotoxy(20,14);
						SetConsoleTextAttribute (hConsole, 14);
						printf("GAME PAUSED");
						sleep(1);
						gotoxy(18,16);
						printf("PRESS P TO UNPAUSE");
						gotoxy(18,17);
						printf("PRESS 0 (or O) TO RESET THE GAME");
						gotoxy(18,18);
						printf("PRESS T TO ENTER TELEPORT COORDINATES");
						do {
							c = getch();
							if(c==111 || c==79) { c = 48; }
							if(c==112 || c==80) { c = 49; }
							if(c==116 || c==84) { c = 50; }
						} while(c<48 && c>50);
						if(c==48) {
							gotoxy(20,20);
							SetConsoleTextAttribute (hConsole, 12);
							printf(" GAME "); sleep(1); printf("OVER ");
							lp = 0; sleep(1);
						} else {
							to--;
							if(c==50) {
								gotoxy(20,20);
								SetConsoleTextAttribute (hConsole, 12);
								printf("INSERT THE XY COORDINATES (0-666): ");
								gotoxy(20,22); printf("000 000");
								gotoxy(20,22); SetConsoleTextAttribute (hConsole, 15);
								scanf("%d %d",&xp,&yp);
								if(xp==666) {
									for(c=0, i=0, n=0; c<100; c++) {
										if(ec[c]<4) {
											n++;
											i+=ex[c];
										}
									}
									xp = i/n;
								}
								if(yp==666) {
									for(c=0, i=0, n=0; c<100; c++) {
										if(ec[c]<4) {
											n++;
											i+=ey[c];
										}
									}
									yp = i/n;
								}
								if(xp==777) {
									for(c=0, i=0, n=0; c<100; c++) {
										if(fc[c]<4) {
											n++;
											i+=fx[c];
										}
									}
									xp = i/n;
								}
								if(yp==777) {
									for(c=0, i=0, n=0; c<100; c++) {
										if(fc[c]<4) {
											n++;
											i+=fy[c];
										}
									}
									yp = i/n;
								}
								if(xp>666 || xp<0) { xp = rand()%666; }
								if(yp>666 || yp<0) { yp = rand()%666; }
							}
						}
						t = time(NULL)-ti;
					}
					if(cp%2) {
						dy = 0;
						if(cp==1) {
							dx = 1;
						} else {
							dx = -1;
						}
					} else {
						dx = 0;
						if(cp==2) {
							dy = 1;
						} else {
							dy = -1;
						}
					}
					if(c==32 || c==13) {
						x = xp; y = yp; to--; printf("\a");
						do {
							y+=dy; x+=dx;
							for(c=0, i=100; c<100 && i==100; c++) {
								if(ex[c]==x && ey[c]==y) { i = c; }
								if(fx[c]==x && fy[c]==y) { i = 101; }
							}
							if(i<100 && rand()%2==0) { ec[i] = 4; c = 0; }
							if(x<xp-33 || x>xp+33 || y<yp-11 || y>yp+11 || c==0) {
								c = 0;
							} else { c = 1; }
							sp[y][x] = 4; if(dy!=0) { sp[y][x]++; }
						} while(c==1);
					}
					if(c==48 || c==79 || c==111) { xp=333; yp=333; }
				}
				fflush(stdin);
			}
			cl++; fx[100] = xp; fy[100] = yp;
			if(xp>665) { xp = 665; }
			if(yp>665) { yp = 665; }
			if(xp<0) { xp = 0; }
			if(yp<0) { yp = 0; }
			for(c=0; c<100; c++) {
				srand(time(NULL)+c+ec[c]+fc[c]);
				if(ex[c]>665) { ex[c] = 665; }
				if(ey[c]>665) { ey[c] = 665; }
				if(ex[c]<0) { ex[c] = 0; }
				if(ey[c]<0) { ey[c] = 0; }
				if(fx[c]>665) { fx[c] = 665; }
				if(fy[c]>665) { fy[c] = 665; }
				if(fx[c]<0) { fx[c] = 0; }
				if(fy[c]<0) { fy[c] = 0; }
				if(ec[c]<4 && rand()%2==0) {
					if((fx[ea[c]]<ex[c]-67 || fx[ea[c]]>ex[c]+67 || fy[ea[c]]<ey[c]-23 || fy[ea[c]]>ey[c]+23 || fc[ea[c]]>=4) && (fc[ea[c]]==4 || rand()%2==0)) {
						for(i=0; i<100; i++) {
							if(fx[i]<ex[c]+33 && fx[i]>ex[c]-33 && fy[i]<ey[c]+11 && fy[i]>ey[c]-11) {
								ea[c] = i; i = 100;
							}
						}
						if(rand()%4==0) {
							if((xp==ex[c]) || (yp==ey[c])) {
								ea[c] = 100;
							}
						}
					} else {
						if(rand()%2==0) {
							if(fx[ea[c]]>ex[c]) { ex[c]++; ec[c]=1; }
							if(fx[ea[c]]<ex[c]) { ex[c]--; ec[c]=3; }
						}
						if(rand()%2==0) {
							if(fy[ea[c]]>ey[c]) { ey[c]++; ec[c]=2; }
							if(fy[ea[c]]<ey[c]) { ey[c]--; ec[c]=0; }
						}
						if(rand()%3>0) {
							if(ec[c]%2==0) {
								dx = 0;
								if(ec[c]==0) {
									dy = -1;
								} else {
									dy = 1;
								}
							} else {
								dy = 0;
								if(ec[c]==3) {
									dx = -1;
								} else {
									dx = 1;
								}
							}
							if((fx[ea[c]]==ex[c] && ec[c]%2==0) || (fy[ea[c]]==ey[c] && ec[c]%2==1)) {
								x = ex[c]; y = ey[c]; i = 1;
								do {
									y+=dy; x+=dx;
									i = mod(fx[ea[c]]-ex[c]+fy[ea[c]]-ey[c])+1;
									for(i=0; i<100; i++) {
										if(x==fx[i] && y==fy[i]) {
											if(rand()%(mod(fx[i]-ex[c]+fy[i]-ey[c])+1)==0) {
												fc[i] = 4; i = 100;  printf("\a");
											}
										}
									}
									if(i==100) {
										i = 1;
										if(x==xp && y==yp) {
											if(rand()%(mod(xp-ex[c]+yp-ey[c])+1)==0) {
												lp++; i++;  printf("\a");
											}
										}
									}
									if(x<ex[c]-67 || x>ex[c]+67 || y<ey[c]-23 || y>ey[c]+23) {
										i = 0;
									} else {
										if((sp[y][x]!=4 && sp[y][x]!=5) || rand()%3==0) {
											sp[y][x] = 8; if(dy!=0) { sp[y][x]++; }
										}
									}
								} while(i==1);
							}
						}
					}
				}
				if(fc[c]<4 && rand()%2==0) {
					if((ex[fa[c]]<fx[c]-67 || ex[fa[c]]>fx[c]+67 || ey[fa[c]]<fy[c]-23 || ey[fa[c]]>fy[c]+23 || ec[fa[c]]>=4) && (ec[fa[c]]==4 || rand()%2==0)) {
						for(i=0; i<100; i++) {
							if(ex[i]<fx[c]+33 && ex[i]>fx[c]-33 && ey[i]<fy[c]+11 && ey[i]>fy[c]-11) {
								fa[c] = i; i = 100;
							}
						}
					} else {
						if(rand()%2==0) {
							if(ex[fa[c]]>fx[c]) { fx[c]++; fc[c]=1; }
							if(ex[fa[c]]<fx[c]) { fx[c]--; fc[c]=3; }
						}
						if(rand()%2==0) {
							if(ey[fa[c]]>fy[c]) { fy[c]++; fc[c]=2; }
							if(ey[fa[c]]<fy[c]) { fy[c]--; fc[c]=0; }
						}
						if(rand()%3>0) {
							if(fc[c]%2==0) {
								dx = 0;
								if(fc[c]==0) {
									dy = -1;
								} else {
									dy = 1;
								}
							} else {
								dy = 0;
								if(fc[c]==3) {
									dx = -1;
								} else {
									dx = 1;
								}
							}
							if((ex[fa[c]]==fx[c] && fc[c]%2==0) || (ey[fa[c]]==fy[c] && fc[c]%2==1)) {
								x = fx[c]; y = fy[c]; i = 1;
								do {
									y+=dy; x+=dx;
									for(i=0; i<100; i++) {
										if(x==ex[i] && y==ey[i]) {
											if(rand()%(mod(fx[c]-ex[i]+fy[c]-ey[i])+2)==0) {
												ec[i] = 4; i = 100; printf("\a");
											}
										}
									}
									if(i==100) { i = 1; }
									if(x<fx[c]-67 || x>fx[c]+67 || y<fy[c]-23 || y>fy[c]+23) {
										i = 0;
									} else {
										if((sp[y][x]!=4 && sp[y][x]!=5) || rand()%3==0) {
											sp[y][x] = 6; if(dy!=0) { sp[y][x]++; }
										}
									}
								} while(i==1);
							}
						}
					}
				}
			}
			for(c=0; c<100; c++) {
				if(ec[c]<4) { sp[ey[c]][ex[c]] = -1; }
				if(fc[c]<4) { sp[fy[c]][fx[c]] = -2; }
			}
			sp[yp][xp] = -3;
		} while(lp>0);
		system("cls"); sleep(1);
		SetConsoleTextAttribute (hConsole, 15);
		printf("\n\n\a              GAME OVER \n              ");
		sleep(1);
		SetConsoleTextAttribute (hConsole, 10);
		printf("\n\n\n       PRESS 1 (one) TO PLAY AGAIN");
		SetConsoleTextAttribute (hConsole, 12);
		printf("\n\n\a       PRESS 0 (zero) TO QUIT TO MAIN MENU");
		do { c = getch() - 48; } while(c<0 || c>1);
	} while(c==1);
}
void intro () {
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	sleep(1); SetConsoleTextAttribute (hConsole, 14);
	printf("\n\n\n          PRESS ANY KEY TO START THE GAME \n\n");
	getch(); game();
}
int main () {
	int c, i, p, t;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do {
		system("cls");
		i = 0; p = 1;
		do {
			srand(time(NULL));
			gotoxy(0,0);
			for(c=0; c<8; c++) { under(110, rand()*c); printf("\n"); }
			under(45, rand());
			SetConsoleTextAttribute (hConsole, 9+(rand()%7));
			printf("    DELTA  PILOTS ");
			under(48, rand()); printf("\n"); under(45, rand());
			SetConsoleTextAttribute (hConsole, 1+(rand()%15));
			printf("__________________");
			under(48, rand()); printf("\n"); under(45, rand());
			printf("                  "); under(48, rand());
			printf("\n"); under(45, rand());
			SetConsoleTextAttribute (hConsole, 9+(rand()%7));
			printf("   VACUUM DOGFIGHT");
			under(48, rand()); printf("\n"); under(110, rand());
			printf("\n"); p = 9+(rand()%7);
			switch (i) {
				case 0:
					under(45, rand()); printf("                  "); under(48, rand()); printf("\n");
					under(45, rand()); printf("                  "); under(48, rand()); printf("\n");
					under(45, rand());
					SetConsoleTextAttribute (hConsole, p);
					printf("   START   QUIT   ");
					under(48, rand()); printf("\n");
					under(45, rand()); printf("                  "); under(48, rand()); printf("\n");
					under(45, rand()); printf("                  "); under(48, rand()); printf("\n");
					under(45, rand()); printf("                  "); under(48, rand()); printf("\n");
				break;
				case 1:
					under(45, rand());
					SetConsoleTextAttribute (hConsole, p);
					printf("  _______         ");
					under(48, rand()); printf("\n");
					SetConsoleTextAttribute (hConsole, p);
					under(45, rand());
					SetConsoleTextAttribute (hConsole, p); printf(" |       |        ");
					under(48, rand()); printf("\n");
					under(45, rand());
					SetConsoleTextAttribute (hConsole, p); printf(" | START | QUIT   ");
					under(48, rand()); printf("\n");
					under(45, rand());
					SetConsoleTextAttribute (hConsole, p); printf(" |_______|        ");
					under(48, rand()); printf("\n");
					under(45, rand()); printf("                  "); under(48, rand()); printf("\n");
					under(45, rand());
					SetConsoleTextAttribute (hConsole, 9+(rand()%7)); printf(" ENTER TO CONTINUE");
					under(48, rand()); printf("\n");
				break;
				case 2:
					under(45, rand());
					SetConsoleTextAttribute (hConsole, p); printf("          ______  ");
					under(48, rand()); printf("\n");
					under(45, rand());
					SetConsoleTextAttribute (hConsole, p); printf("         |      | ");
					under(48, rand()); printf("\n");
					under(45, rand());
					SetConsoleTextAttribute (hConsole, p); printf("   START | QUIT | ");
					under(48, rand()); printf("\n");
					under(45, rand());
					SetConsoleTextAttribute (hConsole, p); printf("         |______| ");
					under(48, rand()); printf("\n");
					under(45, rand()); printf("                  "); under(48, rand()); printf("\n");
					under(45, rand());
					SetConsoleTextAttribute (hConsole, 9+(rand()%7)); printf(" ENTER TO CONTINUE");
					under(48, rand()); printf("\n");
				break;
			}
			for(c=0; c<10; c++) { under(110, rand()*c); printf("\n"); }
			p = time(NULL);
			while(time(NULL)-p<1) {
				if(kbhit()) {
					c = getch();
					if(c==224) {
						c = getch();
						switch (c) {
							case 75: i = 1; p--; break;
							case 77: i = 2; p--; break;
						}
					}
					if(c==13 && i>0) { i++; i++; p--; }
				}
			}
		} while(i<3);
		if(i!=3) { c = 0; } else { c = 1; intro(); }
	} while(c==1);
	return 0;
}
