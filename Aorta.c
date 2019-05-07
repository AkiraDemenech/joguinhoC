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
	system("cls"); srand(time(NULL));
	system("cls"); srand(time(NULL));
	SetConsoleTextAttribute (hConsole, collor(rand()));
	printf("\n\n    Voce ("); srand(time(NULL));
	SetConsoleTextAttribute (hConsole, 15); printf("@");
	SetConsoleTextAttribute (hConsole, collor(rand()));
	printf(") esta numa ilha quadrada num grupo.");
	sleep(1);
	SetConsoleTextAttribute (hConsole, collor(rand()));
	printf("\n    ESTA MUITO ESCURO, E O SECO MATO DESSA MISTERIOSA ILHA NAO PERMITE SE VER AO LONGE."); sleep(1);
	SetConsoleTextAttribute (hConsole, collor(rand()));
	printf("\n\n    Estranhos sons de grunhidos, aparentemente humanos."); sleep(1);
	SetConsoleTextAttribute (hConsole, collor(rand()));
	printf("\n    GRITOS E TERROR NO GRUPO DISPERSO."); sleep(1);
	SetConsoleTextAttribute (hConsole, collor(rand()));
	printf("\n\n    Um a um, os nativos mortos-vivos dessa ilhota os atacam e assimilam a sua raca: "); sleep(1);
	SetConsoleTextAttribute (hConsole, collor(rand())); printf("ELES SAO ZUMBIS ");
	SetConsoleTextAttribute (hConsole, 8); printf("&");
	sleep(1);
	SetConsoleTextAttribute (hConsole, 12);
	printf("\n\n    DESTRUA AS COVAS E SALVE OS SEUS AMIGOS. ");
	SetConsoleTextAttribute (hConsole, 7); printf("0 ");
	SetConsoleTextAttribute (hConsole, 14); printf("%%");
	SetConsoleTextAttribute (hConsole, 12);
	sleep(1); printf("\n    O NUMERO NA COVA (de 0 a 9) INDICA A QUANTIDADE DE DANO RECEBIDO. ");
	SetConsoleTextAttribute (hConsole, 15);
	sleep(1); printf("\n\n    USE WASD PARA SE MOVER, BARRA DE ESPACO PARA GOLPEAR E P PARA PAUSAR O JOGO. ");
	sleep(1); printf("\n\n    BOA SORTE. APERTE QUALQUER TECLA PARA COMECAR"); 
	// FIM DO TUTORIAL INTRODUTÓRIO-IMERSIVO
	int x, y, c, i, a, b, g, v, z, k=0, cl=0, t, to, h, m, s, so, mu, plx, ply, plv, plc, npx[100], npy[100], nps[100], npc[100], cvx[10], cvy[10], cv[10], sp[111][111];
	int hd=0, hax=0, hin=0, tax=0, tin=0, sax=0, sin=0, max=0, min=0, cax=0, cin=0, con=0;
	i = getch(); fflush(stdin);
	/*
	ESTADOS POSICIONAIS DO CURSOR **c[*]:
	0 = ACIMA
	1 = A DIREITA
	2 = ABAIXO
	3 = A ESQUERDA
	
	ESTADOS DE VIDA nps[n]:
	0 = VIVO
	1 = MORTO
	2 = ZUMBI
	
	ESTADOS DE AMBIENTE sp[y][x]:
	0 = MATO EM PÉ
	1 = MATO PISADO
	
	ESTADO DE DEGRADAÇÃO DA COVA cv[n]:
	0-9 de Destruição
	*/
	do {
		hd=0; plx=((rand()%2)*109)+(rand()%2); ply=((rand()%2)*109)+(rand()%2); plv=3; plc=2; s=0; m=0; h=0;
		srand(time(NULL));
		for(y=0; y<111; y++) { for(x=0; x<111; x++) { sp[y][x]=0; } }
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
			if(rand()%100<=20+(rand()%6)) { nps[c]=1; npx[c]=0; npy[c]=0; }
		}
		do {
			g=rand()%100;
		} while(nps[g]>0);
		t=time(NULL); to=t;
		// FIM DO POSICIONAMENTO, INÍCIO DO JOGO
		do {
			s=time(NULL)-t; for(m=0; s>=60; m++) { s-=60; } for(h=0; m>=60; h++) { m-=60; }
			if(s==so) { mu=0; } else { mu=1; so=s; }
			// CÁLCULO DO TEMPO
			
			if((plx<2 && ply<2) || time(NULL)%11==0 || s%11==0 || (time(NULL)-t)%11==0 || rand()%11==0) {
				system("cls");
			}
			gotoxy(0,0);
			// LIMPEZA DA TELA ou POSICIONAMENTO EM 0x0
			
			switch (plv) {
				case 3: i=10; break;
				case 2: i=14; break;
				case 1: i=12; break;
				case 0: i=15; break;
			}
			SetConsoleTextAttribute (hConsole, i);
			printf("\n    TEMPO: ");
			if(h>0) { printf("%d hrs ",h); }
			if(h+m>0) { printf("%d min ",m); }
			printf("%d sec",s);
			if(m+h>0) { printf(" (%d s)",time(NULL)-t); }
			printf("\n    %d VIDAS: ",plv);
			SetConsoleTextAttribute (hConsole, 12); for(c=0; c<plv; c++) { printf(" <3"); }
			printf("\n    HORDA ATUAL: %d \n    COVAS: ",hd);
			for(c=0; c<10; c++) {
				if(cv[c]<10) {
					SetConsoleTextAttribute (hConsole, 7);
					printf("%d",cv[c]);
				} else {
					SetConsoleTextAttribute (hConsole, 8);
					printf("+");
				}
			}
			for(c=0, v=0, z=0, i=0; c<100; c++) { if(nps[c]==0) { v++; } if(nps[c]==1) { z++; } }
			SetConsoleTextAttribute (hConsole, 15); printf("\n    SEUS AMIGOS: %d%%, %dX e %d& \n    ",v,z,100-z-v);
			for(c=0; c<100; c++) {
				if(nps[c]>2) { printf(" "); } else {
					switch (nps[c]) {
						case 0: SetConsoleTextAttribute (hConsole, 14); printf("%%"); break;
						case 1: SetConsoleTextAttribute (hConsole, 12); printf("X"); break;
						case 2: SetConsoleTextAttribute (hConsole, 7); printf("&"); break;
					}
				}
				if(c%50==49) { printf("\n    "); }
			}
			srand(time(NULL)+z+v);
			// PRINT DO PAINEL DE INFORMAÇÕES
			char min[]="qwertyuiopasdfghjklzxcvbnm";
			for(y=ply-9; y<=ply+9; y++) {
				for(x=plx-20; x<=plx+20; x++) {
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
						for(c=0, i=100; c<100; c++) {
							if(nps[c]!=1) {
								if(npx[c]==x && npy[c]==y) { i=c; c=99; } else {
									if((npx[c]==x || npy[c]==y) && (nps[c]==0 || plx!=x || ply!=y)) {
										if(npx[c]==x && npc[c]%2==0) {
											if(npc[c]==0 && npy[c]-1==y) { i=c; c=99; }
											if(npc[c]==2 && npy[c]+1==y) { i=c; c=99; }
										}
										if(npy[c]==y && npc[c]%2==1) {
											if(npc[c]==1 && npx[c]+1==x) { i=c; c=99; }
											if(npc[c]==3 && npx[c]-1==x) { i=c; c=99; }
										}
									}
								}
							}
						}
						if(i<100) {
							if(nps[i]==0) { c=14; } else { c=8; }
							SetConsoleTextAttribute (hConsole, c);
							if(npx[i]==x && npy[i]==y) {
								if(nps[i]==0) { printf("%%"); } else { printf("&"); }
							} else {
								if(npx[i]==x) { printf("|"); } else { printf("-"); }
							}
						} else {
							for(c=0, i=10; c<10; c++) { if(cvx[c]==x && cvy[c]==y && cv[c]<10) { i=c; c=10; } }
							if(i<10) {
								SetConsoleTextAttribute (hConsole, 7);
								printf("%d",cv[i]);
							} else {
								SetConsoleTextAttribute (hConsole, 15);
								if(plx==x && ply==y) {
									printf("@");
								} else {
									if(plx==x) {
										if((y==ply-1 && plc==0) || (y==ply+1 && plc==2)) {
											printf("|");
										} else {
											mato(sp[y][x]);
										}
									} else {
										if(ply==y) {
											if((x==plx-1 && plc==3) || (x==plx+1 && plc==1)) {
												printf("-");
											} else {
												mato(sp[y][x]);
											}
										} else {
											mato(sp[y][x]);
										}
									}
								}
							}
						}
					}
				}
				printf("\n    ");
			}
			// FIM DO PRINT DA TELA
			to=time(NULL);
			do {
				fflush(stdin);
				if(time(NULL)-to<1) { c=0; } else { c++; }
				if(kbhit()) {
					int k=getch();
					if(k==32) {
						int px[3], py[3];
						switch (plc) {
							case 0: for(c=0; c<3; c++) { py[c]=ply-1; px[c]=plx-1+c; } break;
							case 1: for(c=0; c<3; c++) { px[c]=plx+1; py[c]=ply-1+c; } break;
							case 2: for(c=0; c<3; c++) { py[c]=ply+1; px[c]=plx-1+c; } break;
							case 3: for(c=0; c<3; c++) { px[c]=plx-1; py[c]=ply-1+c; } break;
						}
						for(c=0; c<100; c++) {
							if(c<10) {
								if(c<3) { sp[py[c]][px[c]]=1; }
								for(i=0; i<3; i++) {
									if(cvx[c]==px[i] && cvy[c]==py[i]) {
										cv[c]++;
										if(cv[c]<=10) {
											if(cv[c]==10) {
												cl++;
											}
											c=99;
										}
									}
								}
							}
							if(nps[c]>1) { for(i=0; i<3; i++) { if(npx[c]==px[i] && npy[c]==py[i]) { nps[c]=1; k++; c=99; } } }
						}
					}
					if((k==87 || k==119) && ply>0) { plc=0; ply--; c++; } //SUBIR
					if((k==83 || k==115) && ply<110) { plc=2; ply++; c++; } //DESCER
					if((k==68 || k==100) && plx<110) { plc=1; plx++; c++; } //DIREITA
					if((k==65 || k==97) && plx>0) { plc=3; plx--; c++; } //ESQUERDA
					if(plx>110) { plx=110; } //MANTER-SE NA ILHA
					if(ply>110) { ply=110; } //MANTER-SE NA ILHA
					if(plx<0) { plx=0; } //MANTER-SE NA ILHA
					if(ply<0) { ply=0; } //MANTER-SE NA ILHA
					if(k==80 || k==112) { //PAUSA
						to = time(NULL)-t;
						gotoxy(0,0);
						printf("\n\n\n\n\n\n\n\n\n             PAUSA         ");
						do {
							fflush(stdin);
							k = getch();
							fflush(stdin);
							if(k==48 || k==79 || k==111) { //FINALIZAR PARTIDA
								k=112;
								plv=0;
								printf("\n\n\n\n\n\n\n\n\n             ZERADO         ");
								sleep(1); system("cls");
							}
						} while(k!=80 && k!=112);
						t = time(NULL)-to;
						c++;
					}
				}
				fflush(stdin);
				sp[ply][plx]=1; // MATO ESMAGADO
			} while(c==0);
			if(mu==1) { // SE O SEGUNDO TIVER MUDADO...
				if(s==6) { // NOVA HORDA
					hd++; printf("\a");
					for(c=0; c<10; c++) {
						if(cv[c]<10) { c=9; }
						if(cv[c]>9 && rand()%3>0) {
							do {
								cv[c]=hd%9;
								cvx[c]=1+(rand()%109);
								cvy[c]=1+(rand()%109);
								for(i=c-1; i>=0; i--) {
									if(cvx[c]==cvx[i] && cvy[c]==cvy[i]) { i=0; cv[c]++; }
								}
							} while(cv[c]!=hd%9);
						}
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
				} else {
					for(c=0; c<100; c++) {
						sp[npy[c]][npx[c]]=1; //ESMAGAR MATO
						while(nps[g]>0) {
							g=rand()%100;
							if(g<=v && rand()%4>0) { g++; }
						}
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
									case 0: if(npy[c]>0) { if(sp[npy[c]-1][npx[c]]==1 || rand()%4==0) { npy[c]--; } else { npc[c]=4; } } break;
									case 2: if(npy[c]<110) { if(sp[npy[c]+1][npx[c]]==1 || rand()%4==0) { npy[c]++; } else { npc[c]=4; } } break;
									case 3: if(npx[c]>0) { if(sp[npy[c]][npx[c]-1]==1 || rand()%4==0) { npx[c]--; } else { npc[c]=4; } } break;
									case 1: if(npx[c]<110) { if(sp[npy[c]][npx[c]+1]==1 || rand()%4==0) { npx[c]++; } else { npc[c]=4; } } break;
								}
							} while(npc[c]>3);
						}
						if(nps[c]==2) {
							for(i=0; i<100; i++) {
								if(npx[i]==npx[c] && npy[i]==npy[c]) {
									if(nps[i]==0) { nps[i]=1; }
								}
							}
							if(npx[c]==plx && npy[c]==ply && rand()%2==0) {
								plv--; plx=((rand()%2)*109)+(rand()%2); ply=((rand()%2)*109)+(rand()%2);
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
					}
				}
			}
		} while(plv>0);
		to = time(NULL) - t; con++;
		gotoxy(0,0); printf("\n\n\n        FIM        \n        DE        \n        JOGO        \a"); sleep(1);
		for(c=0, v=0; c<100; c++) { if(nps[c]==0) { v++; } }
		if(v>sax || con<2) { sax=v; }
		if(v<sin || con<2) { sin=v; }
		if(k>max || con<2) { max=k; }
		if(k<min || con<2) { min=k; }
		if(cl>cax || con<2) { cax=cl; }
		if(cl<cin || con<2) { cin=cl; }
		if(to>tax || con<2) { tax=to; }
		if(to<tin || con<2) { tin=to; }
		if(hd>hax || con<2) { hax=hd; }
		if(hd<hin || con<2) { hin=hd; }
		do {
			gotoxy(0,0); if(c>0 || c!=i) { system("cls"); }
			i = c; SetConsoleTextAttribute (hConsole, 14+(rand()%2));
			printf("\n\n\n        FIM        \n        DE        \n        JOGO        \n\n Voce sobreviveu a %d hordas por ",hd);
			if(h>0) {
				printf("%d hrs",h);
				if(m>0 && s>0) { printf(", "); } else {
					if(m>0 || s>0) { printf(" e "); }
				}
			}
			if(m>0) { printf("%d min e ",m); }
			printf("%d sec",s);
			if(m+h>0) { printf(" (%d s)",to); }
			printf("\n Houve %d sobreviventes, %d mortes acumuladas de zumbis e %d covas destruídas",v,k,cl);
			printf("\n    RECORDS: \n\n  Maximo de Hordas: %d",hax);
			if(hax>hin) { printf("\n  Minimo de Hordas: %d",hin); } else { printf("\n"); }
			printf("\n\n  Maximo de Sobreviventes: %d",sax);
			if(sax>sin) { printf("\n  Minimo de Sobreviventes: %d",sin); } else { printf("\n"); }
			printf("\n\n  Maximo de Mortes: %d",max);
			if(max>min) { printf("\n  Minimo de Mortes: %d",min); } else { printf("\n"); }
			printf("\n\n  Maximo de ex-Covas: %d",cax);
			if(cax>cin) { printf("\n  Minimo de ex-Covas: %d",cin); } else { printf("\n"); }
			printf("\n\n  Tempo Maximo: %d s",tax);
			if(tax>tin) { printf("\n  Tempo Minimo: %d s",tin); } else { printf("\n"); }
			printf("\n");
			switch (c) {
				case 0: printf("\n\n    JOGAR   SAIR \n"); break;
				case 1: printf("   _______ \n  |       | \n  | JOGAR | SAIR \n  |_______|"); break;
				case 2: printf("           ______ \n          |      | \n    JOGAR | SAIR | \n          |______|"); break;
			}
			printf("\n\n    UTILIZE AS SETAS PARA POSICIONAR O CURSOR");
			if(c>0) { printf("\n    UTILIZE A BARRA DE ESPACO PARA SELECIONAR E CONTINUAR"); }
			do {
				fflush(stdin); t = getch();
				if(t==49) { c = 1; }
				if(t==48) { c = 2; }
				if(t==32 && c>0) { c++; c++; }
				if(t==224) {
					t = getch();
					if(t==77) { c = 2; }
					if(t==75) { c = 1; }
				}
				fflush(stdin);
			} while(c==i);
		} while(c<3);
		if(c==3) { c=1; }
		sleep(c);
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
				if(kbhit()) { i=2; }
				fflush(stdin);
			} while(i==1);
			if(i==2) { i=1; }
		}
		// FIM DA ESPERA PELO USUÁRIO, INÍCIO DA BREVE ABERTURA COM O TÍTULO DO JOGO
		for(c=5; c>0; c--) {
			system("cls");
			srand(time(NULL)+rand());
			switch (rand()%4) {
				case 3: t=2; break;
				case 2: t=3; break;
				case 1: t=6; break;
				case 0: t=10; break;
			}
			SetConsoleTextAttribute (hConsole, t);
			printf("\n\n\a         AA ");
			switch (c) {
				case 5: printf("\n        AaaA \n       aA  Aa \n      aAaaaAaa \n     AaAA  aAAa \n    aAaa    AaAa"); break;
				case 4: printf("\n        AaaA        0O0OO0O0 \n       aA  Aa      oO00  Oo0o \n      aAaaaAaa    oO0O    O0oo \n     AaAA  aAAa    oO00  Oo0o \n    aAaa    AaAa    0O0OO0O0"); break;
				case 3: printf("\n        AaaA        0O0OO0O0    r  rRrRrrRr \n       aA  Aa      oO00  Oo0o   RrRRrr \n      aAaaaAaa    oO0O    O0oo  rRrRr \n     AaAA  aAAa    oO00  Oo0o   RRrR \n    aAaa    AaAa    0O0OO0O0    rRrRr"); break;
				case 2: printf("\n        AaaA        0O0OO0O0    r  rRrRrrRr  ttTttttT \n       aA  Aa      oO00  Oo0o   RrRRrr          Tt \n      aAaaaAaa    oO0O    O0oo  rRrRr           tt \n     AaAA  aAAa    oO00  Oo0o   RRrR            TT \n    aAaa    AaAa    0O0OO0O0    rRrRr           tT"); break;
				case 1: printf("                                                AA \n        AaaA        0O0OO0O0    r  rRrRrrRr  ttTttttT      AaaA \n       aA  Aa      oO00  Oo0o   RrRRrr          Tt        aA  Aa \n      aAaaaAaa    oO0O    O0oo  rRrRr           tt       aAaaaAaa \n     AaAA  aAAa    oO00  Oo0o   RRrR            TT      AaAA  aAAa \n    aAaa    AaAa    0O0OO0O0    rRrRr           tT     aAaa    AaAa"); break;
			}
			sleep(1);
		}
		printf("\n\n  ");
		for(i=0; i<69; i++) {
			char perd[] = "NAO DEIXE SUA AORTA SER ARRANCADA, NEM QUE A HORDA DESTRUA SUA HORTA.";
			printf("%c",perd[i]); if(perd[i]==',' || perd[i]=='.') { sleep(1); }
		}
		sleep(1); int cor = t;
		// FIM DA BREVE ABERTURA COM O TÍTULO DO JOGO, INÍCIO DOS MENUS INTERATIVOS
		do {
			gotoxy(0,0); if(c>0 || c!=i) { system("cls"); }
			i = c; SetConsoleTextAttribute (hConsole, cor);
			printf("\n\n         AA                                                 AA \n        AaaA        0O0OO0O0    r  rRrRrrRr  ttTttttT      AaaA \n       aA  Aa      oO00  Oo0o   RrRRrr          Tt        aA  Aa \n      aAaaaAaa    oO0O    O0oo  rRrRr           tt       aAaaaAaa \n     AaAA  aAAa    oO00  Oo0o   RRrR            TT      AaAA  aAAa \n    aAaa    AaAa    0O0OO0O0    rRrRr           tT     aAaa    AaAa \n\n  NAO DEIXE SUA AORTA SER ARRANCADA, NEM QUE A HORDA DESTRUA SUA HORTA. \n\n\n");
			switch (c) {
				case 0: printf("\n\n    JOGAR   SAIR \n"); break;
				case 1: printf("   _______ \n  |       | \n  | JOGAR | SAIR \n  |_______|"); break;
				case 2: printf("           ______ \n          |      | \n    JOGAR | SAIR | \n          |______|"); break;
			}
			printf("\n\n    UTILIZE AS SETAS PARA POSICIONAR O CURSOR");
			if(c>0) { printf("\n    UTILIZE A BARRA DE ESPACO PARA SELECIONAR E CONTINUAR"); }
			do {
				fflush(stdin); t = getch();
				if(t==49 || t==65 || t==97) { c = 1; }
				if(t==48 || t==68 || t==100) { c = 2; }
				if(t==32 && c>0) { c++; c++; }
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
