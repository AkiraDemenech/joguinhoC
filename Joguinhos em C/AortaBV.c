#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>

/*
0    Preto
1    Azul
2    Verde
3    Verde-Água
4    Vermelho
5    Roxo
6    Amarelo
7    Branco
8    Cinza
9    Azul-Claro
10   Verde-Claro
11   Verde-Água-Claro
12   Vermelho-Claro
13   Lilás
14   Amarelo-Claro
15   Branco-Brilhante

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute (hConsole, COR);

fflush(stdin);

*/

void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int collor (int r) {
	srand(r);
	switch (rand()%4) {
		case 3: r=2; break;
		case 2: r=3; break;
		case 1: r=6; break;
		case 0: r=10; break;
	}
	return r;
}
int pot (int n, int m) {
	int res = (n*n) + (m*m);
	return (res);
}
int mod (int n) { if(n<0) { n=-n; } return (n); }
void mato (int n) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if(n==0) {
		SetConsoleTextAttribute (hConsole, 2);
		if(rand()%3==0) {
			printf("W");
		} else {
			if(rand()%2==0) {
				printf("M");
			} else {
				printf("N");
			}
		}
	} else {
		SetConsoleTextAttribute (hConsole, 10);
		printf("#");
	}
}
void ojogo () {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y, c, i, a, b, g, v, z, t, ti, tt, to, t1, tv, ta, t2, tg, h, m, s, hd, pb, plx, ply, npx[100], npy[100], nps[100], npc[100], cvx[10], cvy[10], cv[10], sp[111][111];
	do {
		system("cls");
		SetConsoleTextAttribute (hConsole, 11);
		printf("\n\n     CHAVE DE GERACAO (0 para Aleatoria): ");
		SetConsoleTextAttribute (hConsole, 12); scanf("%d",&ti);
		if(ti<=0) { ti = time(NULL); } if(ti<0) { ti = -ti; }
		SetConsoleTextAttribute (hConsole, 11);
		printf("     POPULACAO INICIAL DE ZUMBIS (%%) (0 para Padrao): ");
		SetConsoleTextAttribute (hConsole, 12); scanf("%d",&pb);
	} while(ti<0);
	do {
		to = time(NULL); tv = 1;
		srand(ti); t = 0; if(pb<=0) { pb=20+rand()%6; }
		for(c=0; c<10; c++) {
			do {
				cv[c]=0;
				cvx[c]=1+(rand()%109);
				cvy[c]=1+(rand()%109);
				for(i=c-1; i>=0; i--) {
					if(cvx[c]==cvx[i] && cvy[c]==cvy[i]) { i=0; cv[c]++; }
				}
			} while(cv[c]>0);
		}
		srand(ti); hd=0; s=0; m=0; h=0; plx=rand()%111; ply=rand()%111;
		for(y=0; y<111; y++) { for(x=0; x<111; x++) { sp[y][x]=0; } }
		for(c=0; c<100; c++) {
			do {
				nps[c]=0;
				npx[c]=1+(rand()%109);
				npy[c]=1+(rand()%109);
				x=npx[c]; y=npy[c];
				npc[c]=rand()%4;
				do {
					sp[y][x]=1;
					if(rand()%2==0) {
						i=npc[c];
						do {
							npc[c]=rand()%4;
						} while(npc[c]==(i+2)%4);
					}
					if(x>0 && x<110 && y>0 && y<110) {
						switch (npc[c]) {
							case 0: y--; break;
							case 1: x++; break;
							case 2: y++; break;
							case 3: x--; break;
						}
					} else { sp[y][x]=1; }
				} while(sp[y][x]==0);
				for(i=c-1; i>=0; i--) {
					if(npx[i]==npx[c] && npy[i]==npy[c] && rand()%3>0) { nps[c]++; i=0; }
				}
			} while(nps[c]>0);
		}
		nps[0] = 1;
		for(c=0, v=99; c<100 && v>100-pb; c++) {
			if(rand()%100<pb && nps[c]!=1) { nps[c] = 1; v--; }
			if(v>100-pb && c==99) { c = 1; }
		}
		for(i=99, v=0; i>=0; i--) { if(nps[i]==0) { v++; g=i; } }
		// FIM DO POSICIONAMENTO, INÍCIO DO JOGO
		do {
			s=t; for(m=0; s>=60; m++) { s-=60; } for(h=0; m>=60; h++) { m-=60; }
			if(t2<time(NULL)) { ta = (t-tg)/(time(NULL)-t2); tg = t; } t2 = time(NULL);
			// CÁLCULO DO TEMPO
			
			if(s%11==0 || rand()%11==0) { system("cls"); }
			gotoxy(0,0);
			// LIMPEZA DA TELA ou POSICIONAMENTO EM 0x0
			SetConsoleTextAttribute (hConsole, 15);
			printf("\n    TEMPO: ");
			if(h>0) { printf("%d hrs ",h); }
			if(h+m>0) { printf("%d min ",m); }
			printf("%d sec",s);
			if(m+h>0) { printf(" (%d s)",t); }
			printf("  ||  %d : %d : %d (%d) x%d",(time(NULL)-to)/3600,((time(NULL)-to)%3600)/60,((time(NULL)-to)%3600)%60,time(NULL)-to,ta);
			SetConsoleTextAttribute (hConsole, 10);
			printf("\n    POSICAO [%d]: %d %d",g+1,npx[g]+1,npy[g]+1);
			SetConsoleTextAttribute (hConsole, 11);
			for(c=0, v=0, z=0, i=0; c<100; c++) { if(nps[c]==0) { v++; } if(nps[c]==1) { z++; } }
			printf("\n    HORDA ATUAL: %d  ||  PESSOAS:  ",hd);
			SetConsoleTextAttribute (hConsole, 14); printf("%d%%, ",v);
			SetConsoleTextAttribute (hConsole, 12); printf("%dX ",z);
			SetConsoleTextAttribute (hConsole, 11); printf("e");
			SetConsoleTextAttribute (hConsole, 8); printf(" %d& \n    ",100-v-z);
			SetConsoleTextAttribute (hConsole, 15);
			for(c=0; c<100; c++) {
				if(c==g) {
					printf("v");
				} else {
					if(c==v-z) {
						printf("|");
					} else {
						if(c==v) {
							printf("/");
						} else {
							printf(" ");
						}
					}
				}
			}
			printf("\n    ");
			for(c=0; c<100; c++) {
				switch (nps[c]) {
					case 0: i=14; break;
					case 1: i=12; break;
					case 2: i=7; break;
				}
				SetConsoleTextAttribute (hConsole, i);
				switch (nps[c]) {
					case 0: printf("%%"); break;
					case 1: printf("X"); break;
					case 2: printf("&"); break;
				}
			}
			// PRINT DO PAINEL DE INFORMAÇÕES
			printf("\n    ");
			if(tv==1) {
				char min[]="qwertyuiopasdfghjklzxcvbnm";
				for(y=npy[g]-9; y<=npy[g]+9; y++) {
					for(x=npx[g]-50; x<npx[g]+50; x++) {
						if(x<0 || y<0 || x>110 || y>110) {
							switch (rand()%4) {
								case 0: i=1; break;
								case 1: i=3; break;
								case 2: i=9; break;
								case 3: i=11; break;
							}
							SetConsoleTextAttribute (hConsole, i);
							printf("%c",min[rand()%26]);
						} else {
							if(sp[y][x]>=0) {
								SetConsoleTextAttribute (hConsole, 2 + (sp[y][x]*8));
								mato(sp[y][x]);
							} else {
								if(sp[y][x]==-1) {
									SetConsoleTextAttribute (hConsole, 7);
									printf("0");
								} else {
									if(sp[y][x]==-2) {
										for(c=0; c<100; c++) {
											if(nps[c]!=1) {
												if(x==npx[c] && y==npy[c]) {
													if(nps[c]==0) {
														SetConsoleTextAttribute (hConsole, 14);
														printf("%%");
													} else {
														SetConsoleTextAttribute (hConsole, 8);
														printf("&");
													}
													c = 100;
												}
											}
										}
										if(c==100 && x==plx && y==ply) {
											SetConsoleTextAttribute (hConsole, 15);
											printf("@");
										}
									}
								}
							}
						}
					}
					printf("\n    ");
				}
				for(y=0; y<111; y++) {
					for(x=0; x<111; x++) {
						if(sp[y][x]==-2) {
							sp[y][x] = 1;
						}
					}
				}
				for(c=0; c<10; c++) { sp[cvy[c]][cvx[c]] = -1; }
			}
			srand(ti+t+z+v);
			// FIM DO PRINT DA TELA
			t++;
			switch(rand()%4) {
				case 0: plx++; break;
				case 1: plx--; break;
				case 2: ply++; break;
				case 3: ply--; break;
			}
			if(plx>110) { plx = 110; }
			if(plx<0) { plx = 0; }
			if(ply>110) { ply = 110; }
			if(ply<0) { ply = 0; }
			if(kbhit()) {
				c = getch();
				if(c==111 || c==79) { c = 48; }
				if(c==105 || c==73) { c = 49; }
				if(c==48 || c==49) {
					tv = c - 48;
				}
				if(c==112 || c==80) {
					SetConsoleTextAttribute (hConsole, 15);
					gotoxy(0,0); printf("    PAUSE --> P para CONTINUAR");
					do {
						c = getch();
						if(c==112 || c==80) { c = 0; }
					} while(c!=0);
					system("cls");
				}
			}
			if(s==6) { // NOVA HORDA
				hd++; printf("\a");
				for(c=0; c<100; c++) {
					if(nps[c]==1) {
						do {
							do {
								i=rand()%10;
							} while(rand()%(cv[i]+1)>0);
						} while(cv[i]>9);
						do {
							sp[npy[c]][npx[c]]=0;
							if(rand()%2==0) {
								if(npx[c]<cvx[i]) { npx[c]++; }
								if(npx[c]>cvx[i]) { npx[c]--; }
							} else {
								if(npy[c]<cvy[i]) { npy[c]++; }
								if(npy[c]>cvy[i]) { npy[c]--; }
							}
						} while(npx[c]!=cvx[i] || npy[c]!=cvy[i]);
						nps[c]=2;
					}
				}
			} else {
				for(c=0; c<100; c++) {
					if(nps[g]>0) { for(i=99, v=0; i>=0; i--) { if(nps[i]==0) { v++; g=i; } } }
					if(nps[c]==0) {
						if(npx[c]==110 || npx[c]==0 || npy[c]==110 || npy[c]==0) {
							npc[c]=rand()%4;
						}
						if(npx[c]==110) { npx[c]--; }
						if(npy[c]==110) { npy[c]--; }
						if(npx[c]==0) { npx[c]++; }
						if(npy[c]==0) { npy[c]++; }
						do {
							if(npc[c]==4) { npc[c]=rand()%4; }
							switch (npc[c]) {
								case 0: if(npy[c]>0) { if(sp[npy[c]-1][npx[c]]!=0 || rand()%4==0) { npy[c]--; } else { npc[c]=4; } } break;
								case 2: if(npy[c]<110) { if(sp[npy[c]+1][npx[c]]!=0 || rand()%4==0) { npy[c]++; } else { npc[c]=4; } } break;
								case 3: if(npx[c]>0) { if(sp[npy[c]][npx[c]-1]!=0 || rand()%4==0) { npx[c]--; } else { npc[c]=4; } } break;
								case 1: if(npx[c]<110) { if(sp[npy[c]][npx[c]+1]!=0 || rand()%4==0) { npx[c]++; } else { npc[c]=4; } } break;
							}
						} while(npc[c]>3);
					}
					if(nps[c]==2) {
						for(i=0; i<100; i++) {
							if(npx[i]==npx[c] && npy[i]==npy[c]) {
								if(nps[i]==0) { nps[i]=1; }
							}
						}
						if(c<v-z) {
							if(rand()%2==0) {
								if(npx[g]>npx[c]) { npx[c]++; }
								if(npx[g]<npx[c]) { npx[c]--; }
							} else {
								if(npy[g]>npy[c]) { npy[c]++; }
								if(npy[g]<npy[c]) { npy[c]--; }
							}
							if(rand()%3==0) { npc[c]=rand()%4; }
						} else {
							if(rand()%2==0) {
								if(plx>npx[c]) { npx[c]++; }
								if(plx<npx[c]) { npx[c]--; }
							} else {
								if(ply>npy[c]) { npy[c]++; }
								if(ply<npy[c]) { npy[c]--; }
							}
							if(rand()%2==0) { npc[c]=rand()%4; }
						}
					}
					if(nps[c]!=1) { sp[npy[c]][npx[c]] = -2; }
				}
			}
		} while(v>0);
		int hor[2*hd+11], zb[2*hd+11];
		hd=0; s=0; m=0; h=0;
		for(y=0; y<111; y++) { for(x=0; x<111; x++) { sp[y][x]=0; } }
		for(c=0; c<100; c++) {
			do {
				nps[c]=0;
				npx[c]=1+(rand()%109);
				npy[c]=1+(rand()%109);
				x=npx[c]; y=npy[c];
				npc[c]=rand()%4;
				do {
					sp[y][x]=1;
					if(rand()%2==0) {
						i=npc[c];
						do {
							npc[c]=rand()%4;
						} while(npc[c]==(i+2)%4);
					}
					if(x>0 && x<110 && y>0 && y<110) {
						switch (npc[c]) {
							case 0: y--; break;
							case 1: x++; break;
							case 2: y++; break;
							case 3: x--; break;
						}
					} else { sp[y][x]=1; }
				} while(sp[y][x]==0);
				for(i=c-1; i>=0; i--) {
					if(npx[i]==npx[c] && npy[i]==npy[c] && rand()%3>0) { nps[c]++; i=0; }
				}
			} while(nps[c]>0);
		}
		nps[0] = 1;
		for(c=0, v=99; c<100 && v>100-pb; c++) {
			if(rand()%100<pb && nps[c]!=1) { nps[c] = 1; v--; }
			if(v>100-pb && c==99) { c = 1; }
		}
		for(i=99, v=0; i>=0; i--) { if(nps[i]==0) { v++; g=i; } }
		// FIM DO POSICIONAMENTO, INÍCIO DO JOGO
		do {
			s=t; for(m=0; s>=60; m++) { s-=60; } for(h=0; m>=60; h++) { m-=60; }
			if(t2<time(NULL)) { ta = (t-tg)/(time(NULL)-t2); tg = t; } t2 = time(NULL);
			// CÁLCULO DO TEMPO
			
			if(s%11==0 || rand()%11==0) { system("cls"); }
			gotoxy(0,0);
			// LIMPEZA DA TELA ou POSICIONAMENTO EM 0x0
			SetConsoleTextAttribute (hConsole, 15);
			printf("\n    TEMPO: ");
			if(h>0) { printf("%d hrs ",h); }
			if(h+m>0) { printf("%d min ",m); }
			printf("%d sec",s);
			if(m+h>0) { printf(" (%d s)",t); }
			printf("  ||  %d : %d (%d) || %d : %d (%d) x%d",((time(NULL)-to)%3600)/60,((time(NULL)-to)%3600)%60,time(NULL)-to,((time(NULL)-t1)%3600)/60,((time(NULL)-t1)%3600)%60,time(NULL)-t1,ta);
			SetConsoleTextAttribute (hConsole, 10);
			printf("\n    POSICAO [%d]: %d %d",g+1,npx[g]+1,npy[g]+1);
			SetConsoleTextAttribute (hConsole, 11);
			for(c=0, v=0, z=0, i=0; c<100; c++) { if(nps[c]==0) { v++; } if(nps[c]==1) { z++; } }
			printf("\n    HORDA ATUAL: %d  ||  PESSOAS:  ",hd);
			SetConsoleTextAttribute (hConsole, 14); printf("%d%%, ",v);
			SetConsoleTextAttribute (hConsole, 12); printf("%dX ",z);
			SetConsoleTextAttribute (hConsole, 11); printf("e");
			SetConsoleTextAttribute (hConsole, 8); printf(" %d& \n    ",100-v-z);
			SetConsoleTextAttribute (hConsole, 15);
			for(c=0; c<100; c++) {
				if(c==g) {
					printf("v");
				} else {
					if(c==v-z) {
						printf("|");
					} else {
						if(c==v) {
							printf("/");
						} else {
							printf(" ");
						}
					}
				}
			}
			printf("\n    ");
			for(c=0; c<100; c++) {
				switch (nps[c]) {
					case 0: i=14; break;
					case 1: i=12; break;
					case 2: i=7; break;
				}
				SetConsoleTextAttribute (hConsole, i);
				switch (nps[c]) {
					case 0: printf("%%"); break;
					case 1: printf("X"); break;
					case 2: printf("&"); break;
				}
			}
			// PRINT DO PAINEL DE INFORMAÇÕES
			printf("\n    ");
			if(tv==1) {
				char min[]="qwertyuiopasdfghjklzxcvbnm";
				for(y=npy[g]-9; y<=npy[g]+9; y++) {
					for(x=npx[g]-50; x<npx[g]+50; x++) {
						if(x<0 || y<0 || x>110 || y>110) {
							switch (rand()%4) {
								case 0: i=1; break;
								case 1: i=3; break;
								case 2: i=9; break;
								case 3: i=11; break;
							}
							SetConsoleTextAttribute (hConsole, i);
							printf("%c",min[rand()%26]);
						} else {
							if(sp[y][x]>=0) {
								SetConsoleTextAttribute (hConsole, 2 + (sp[y][x]*8));
								mato(sp[y][x]);
							} else {
								if(sp[y][x]==-1) {
									SetConsoleTextAttribute (hConsole, 7);
									printf("0");
								} else {
									if(sp[y][x]==-2) {
										for(c=0; c<100; c++) {
											if(nps[c]!=1) {
												if(x==npx[c] && y==npy[c]) {
													if(nps[c]==0) {
														SetConsoleTextAttribute (hConsole, 14);
														printf("%%");
													} else {
														SetConsoleTextAttribute (hConsole, 8);
														printf("&");
													}
													c = 100;
												}
											}
										}
										if(c==100 && x==plx && y==ply) {
											SetConsoleTextAttribute (hConsole, 15);
											printf("@");
										}
									}
								}
							}
						}
					}
					printf("\n    ");
				}
				for(y=0; y<111; y++) {
					for(x=0; x<111; x++) {
						if(sp[y][x]==-2) {
							sp[y][x] = 1;
						}
					}
				}
				for(c=0; c<10; c++) { sp[cvy[c]][cvx[c]] = -1; }
			}
			srand(ti+t+z+v); t++;
			// FIM DO PRINT DA TELA
			SetConsoleTextAttribute (hConsole, 15);
			for(c=0; c<100*t/tt; c++) { printf("#"); }
			printf("\n    ");
			printf("GRAVANDO  ||  ");
			switch(rand()%4) {
				case 0: plx++; break;
				case 1: plx--; break;
				case 2: ply++; break;
				case 3: ply--; break;
			}
			if(plx>110) { plx = 110; }
			if(plx<0) { plx = 0; }
			if(ply>110) { ply = 110; }
			if(ply<0) { ply = 0; }
			if(kbhit()) {
				c = getch();
				if(c==111 || c==79) { c = 48; }
				if(c==105 || c==73) { c = 49; }
				if(c==48 || c==49) {
					tv = c - 48;
				}
				if(c==112 || c==80) {
					SetConsoleTextAttribute (hConsole, 15);
					gotoxy(0,0); printf("    PAUSE --> P para CONTINUAR");
					do {
						c = getch();
						if(c==112 || c==80) { c = 0; }
					} while(c!=0);
					system("cls");
				}
			}
			if(10*t/tt<1) { printf("0"); }
			printf("%d %% (%d s)",100*t/tt,tt);
			if(s==6) { // NOVA HORDA
				printf("\a");
				for(c=0, hor[hd]=0, zb[hd]=0; c<100; c++) {
					if(nps[c]==2) { zb[hd]++; }
					if(nps[c]==1) { hor[hd]++; }
				}
				for(c=0; c<100; c++) {
					if(nps[c]==1) {
						do {
							do {
								i=rand()%10;
							} while(rand()%(cv[i]+1)>0);
						} while(cv[i]>9);
						do {
							sp[npy[c]][npx[c]]=0;
							if(rand()%2==0) {
								if(npx[c]<cvx[i]) { npx[c]++; }
								if(npx[c]>cvx[i]) { npx[c]--; }
							} else {
								if(npy[c]<cvy[i]) { npy[c]++; }
								if(npy[c]>cvy[i]) { npy[c]--; }
							}
						} while(npx[c]!=cvx[i] || npy[c]!=cvy[i]);
						nps[c]=2;
					}
				}
				hd++;
			} else {
				for(c=0; c<100; c++) {
					if(nps[g]>0) { for(i=99, v=0; i>=0; i--) { if(nps[i]==0) { v++; g=i; } } }
					if(nps[c]==0) {
						if(npx[c]==110 || npx[c]==0 || npy[c]==110 || npy[c]==0) {
							npc[c]=rand()%4;
						}
						if(npx[c]==110) { npx[c]--; }
						if(npy[c]==110) { npy[c]--; }
						if(npx[c]==0) { npx[c]++; }
						if(npy[c]==0) { npy[c]++; }
						do {
							if(npc[c]==4) { npc[c]=rand()%4; }
							switch (npc[c]) {
								case 0: if(npy[c]>0) { if(sp[npy[c]-1][npx[c]]!=0 || rand()%4==0) { npy[c]--; } else { npc[c]=4; } } break;
								case 2: if(npy[c]<110) { if(sp[npy[c]+1][npx[c]]!=0 || rand()%4==0) { npy[c]++; } else { npc[c]=4; } } break;
								case 3: if(npx[c]>0) { if(sp[npy[c]][npx[c]-1]!=0 || rand()%4==0) { npx[c]--; } else { npc[c]=4; } } break;
								case 1: if(npx[c]<110) { if(sp[npy[c]][npx[c]+1]!=0 || rand()%4==0) { npx[c]++; } else { npc[c]=4; } } break;
							}
						} while(npc[c]>3);
					}
					if(nps[c]==2) {
						for(i=0; i<100; i++) {
							if(npx[i]==npx[c] && npy[i]==npy[c]) {
								if(nps[i]==0) { nps[i]=1; }
							}
						}
						if(c<v-z) {
							if(rand()%2==0) {
								if(npx[g]>npx[c]) { npx[c]++; }
								if(npx[g]<npx[c]) { npx[c]--; }
							} else {
								if(npy[g]>npy[c]) { npy[c]++; }
								if(npy[g]<npy[c]) { npy[c]--; }
							}
							if(rand()%3==0) { npc[c]=rand()%4; }
						} else {
							if(rand()%2==0) {
								if(plx>npx[c]) { npx[c]++; }
								if(plx<npx[c]) { npx[c]--; }
							} else {
								if(ply>npy[c]) { npy[c]++; }
								if(ply<npy[c]) { npy[c]--; }
							}
							if(rand()%2==0) { npc[c]=rand()%4; }
						}
					}
					if(nps[c]!=1) { sp[npy[c]][npx[c]] = -2; }
				}
			}
		} while(v>0);
		SetConsoleTextAttribute (hConsole, 12); for(c=0; c<4; c++) { sleep(1); printf("\a ."); }
		sleep(1); printf("\a\n\n    ANALISE CONCLUIDA: %d Hordas \n    %d : %d : %d (x%d)\n",hd,h,m,s,2*t/(time(NULL)-to-4));
		SetConsoleTextAttribute (hConsole, 14);
		printf("\n    Num  |  Kn  |  Z0 ");
		SetConsoleTextAttribute (hConsole, 15);
		for(c=0; c<hd; c++) {
			printf("\n    ");
			if(c<100) {
				printf("0");
				if(c<10) {
					printf("0");
				}
			}
			printf("%d  |  ",c);
			if(hor[c]<10) {
				printf("0");
			}
			printf("%d  |  ",hor[c]);
			if(zb[c]<10) {
				printf("0");
			}
			printf("%d",zb[c]);
		}
		printf("\a");
		sleep(1); printf("\a\n\n    GRAFICO (1/0) ? ");
		do { c = getch() - 48; } while(c!=0 && c!=1);
		if(c==1) {
			printf("\a"); sleep(1); printf("\n");
			for(c=0; c<hd; c++) {
				SetConsoleTextAttribute (hConsole, 15);
				printf("\n  ");
				if(c<100) {
					printf("0");
					if(c<10) {
						printf("0");
					}
				}
				printf("%d  |",c);
				for(i=0; i<100; i++) {
					if(i<100-hor[c]-zb[c]) {
						SetConsoleTextAttribute (hConsole, 14);
						printf("%%");
					} else {
						if(i<100-zb[c]) {
							SetConsoleTextAttribute (hConsole, 12);
							printf("X");
						} else {
							SetConsoleTextAttribute (hConsole, 8);
							printf("&");
						}
					}
				}
			}
		}
		SetConsoleTextAttribute (hConsole, 15);
		sleep(1); printf("\a\n\n    RECALCULAR (1/0) ? ");
		do { c = getch() - 48; } while(c!=0 && c!=1); printf("\a"); sleep(1);
	} while(c==1);
}
int main () {
	int c, i, t; char abc[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do {
		srand(time(NULL)); system("cls"); sleep(1);
		for(c=0, i=0; i==0; c++) {
			gotoxy(0,0); SetConsoleTextAttribute (hConsole, 15);
			printf("\n\n\n      APERTE QUALQUER TECLA PARA INICIALIZAR ");
			for(i=0; i<c%5; i++) { printf("."); } printf(" %d      ",c);
			for(i=1; i<=c; i=i*10) { printf(" "); } printf("\n\n\n    ");
			for(i=0, t=0; i<520; i++) {
				int cor;
				do {
					cor=rand()%16;
					if(cor==t && rand()%13>rand()%5) { cor=0; }
					if(rand()%13==0) { srand(rand()); }
					if(rand()%26==0) { srand(rand()+time(NULL)); }
					if(rand()%52==0) { srand(time(NULL)); }
				} while(cor==0);
				SetConsoleTextAttribute (hConsole, cor); t=cor;
				if(rand()%2==0) { printf("%d",rand()%10); } else { printf("%c",abc[rand()%52]); }
				if(rand()%2==0) { printf("%d",rand()%10); } else { printf("%c",abc[rand()%52]); }
				printf("  ");
				if(i%26==25) { printf("\n    "); }
			}
			SetConsoleTextAttribute (hConsole, 1+(rand()%15));
			t = time(NULL);
			do {
				i=1; fflush(stdin);
				if(time(NULL)-t>=1) { i=0; }
				if(kbhit()) {
					i = getch() + 1;
					c = -1;
				}
				fflush(stdin);
			} while(i==1);
		}
		// FIM DA ESPERA PELO USUÁRIO, INÍCIO DA BREVE ABERTURA COM O TÍTULO DO JOGO
		do {
			gotoxy(0,0); if(c>0 || c!=i) { system("cls"); }
			i = c; SetConsoleTextAttribute (hConsole, 2);
			printf("\n\n         AA                                                 AA \n        AaaA        0O0OO0O0    r  rRrRrrRr  ttTttttT      AaaA \n       aA  Aa      oO00  Oo0o   RrRRrr          Tt        aA  Aa \n      aAaaaAaa    oO0O    O0oo  rRrRr           tt       aAaaaAaa \n     AaAA  aAAa    oO00  Oo0o   RRrR            TT      AaAA  aAAa \n    aAaa    AaAa    0O0OO0O0    rRrRr           tT     aAaa    AaAa");
			SetConsoleTextAttribute (hConsole, 10);
			printf("\n\n  NAO DEIXE SUA AORTA SER ARRANCADA, NEM QUE A HORDA DESTRUA SUA HORTA. \n\n\n");
			SetConsoleTextAttribute (hConsole, 11);
			switch (c) {
				case 0: printf("\n\n    JOGAR   SAIR \n"); break;
				case 1: printf("   _______ \n  |       | \n  | JOGAR | SAIR \n  |_______|"); break;
				case 2: printf("           ______ \n          |      | \n    JOGAR | SAIR | \n          |______|"); break;
			}
			do {
				fflush(stdin); t = getch();
				if(t==49 || t==65 || t==97) { c = 1; }
				if(t==48 || t==68 || t==100) { c = 2; }
				if((t==32 || t==13) && c>0) { c++; c++; }
				if(t==224) {
					t = getch();
					if(t==77) { c = 2; }
					if(t==75) { c = 1; }
				}
				fflush(stdin);
			} while(c==i);
		} while(c<3);
		if(c==3) { ojogo(); c=1; }
	} while(c==1);
	return 0;
}
