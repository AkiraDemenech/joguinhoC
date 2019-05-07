#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#include<math.h>

void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void collor (int cor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, cor);
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
void curso (int c) {
	switch (c) {
		case 0: printf("^"); break;
		case 1: printf(">"); break;
		case 2: printf("v"); break;
		case 3: printf("<"); break;
	}
}
int h2o (int r) {
	srand(r+time(NULL));
	r = 1 + ((rand()%2)*2) + ((rand()%2)*8);
	return (r);
}
void water (int r) {
	srand(r+time(NULL));
	collor(h2o(rand()));
	switch (rand()%5) {
		case 0: printf("."); break;
		case 1: printf(","); break;
		case 2: printf(";"); break;
		case 3: printf(":"); break;
		case 4: printf("'"); break;
	}
}
int grey (int r) {
	srand(r+time(NULL));
	r = 7;
	if(rand()%3>0) {
		if(rand()%2==0) {
			r++;
		} else {
			r+=8;
		}
	}
	return (r);
}
int f(int x) {
	int y = 50 + (x*x*0.00566);
	srand(time(NULL)-y+x);
	if(rand()%3>0) {
		if(rand()%2==0) {
			y-=sin(x)*((rand()%13)+1);
		} else {
			y+=sin(x)*((rand()%13)+1);
		}
	}
	if(rand()%3>0) {
		if(rand()%2==0) {
			y-=cos(x)*((rand()%13)+1);
		} else {
			y+=cos(x)*((rand()%13)+1);
		}
	}
	return (y);
}
void ojogo () {
	/* AMBIENTE */ int sp[666][666], xpr[1369], ypr[1369], cpr[1369], xar[37], yar[37], oar[37];
	/* PLAYER */ int plx, ply, plc, plv, plo, bbx, bby, plp[11];
	/* PROCESSAMENTO */ int c, i, p, x, y, t, ti, to, h, m, s, cl, mk;
	char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	do {
		system("cls"); srand(time(NULL));
		// GERAÇÃO DO AMBIENTE
		for(x=0; x<666; x++) {
			for(y=0; y<666; y++) {
				sp[x][y] = 0;
			}
		}
		for(x=0; x<=333; x++) {
			for(y=f(x); y<666; y++) {
				do {
					sp[x][y] = (200+((rand()%5)*100)) + (rand()%26) + 26;
				} while(sp[x][y]/100==3);
			}
			srand(time(NULL)+x+y);
		}
		for(x=0; x<666; x++) {
			srand(time(NULL)-x);
			for(y=600; y<666; y++) {
				if(rand()%3==0 && y>=600+tan(rand())) {
					sp[x][y] = (grey(rand())*100) + (rand()%26);
				}
			}
		}
		for(i=0; i<=(rand()%3); i++) {
			for(x=0; x<666; x++) {
				for(y=0; y<666; y++) {
					srand((x*y)+rand());
					if(rand()%4==0 && sp[x][y]==0) {
						if(x>0) {
							if(sp[x-1][y]>=100 && sp[x-1][y]<700) {
								do {
									sp[x][y] = (200+((rand()%5)*100)) + (rand()%26) + 26;
								} while(sp[x][y]/100==3);
							}
							if(sp[x-1][y]>=700) {
								sp[x][y] = (grey(rand())*100) + (rand()%26);
							}
						}
						if(x<665) {
							if(sp[x+1][y]>=100 && sp[x+1][y]<700) {
								do {
									sp[x][y] = (200+((rand()%5)*100)) + (rand()%26) + 26;
								} while(sp[x][y]/100==3);
							}
							if(sp[x+1][y]>=700) {
								sp[x][y] = (grey(rand())*100) + (rand()%26);
							}
						}
						if(y>0) {
							if(sp[x][y-1]>=100 && sp[x][y-1]<700) {
								do {
									sp[x][y] = (200+((rand()%5)*100)) + (rand()%26) + 26;
								} while(sp[x][y]/100==3);
							}
							if(sp[x][y-1]>=700) {
								sp[x][y] = (grey(rand())*100) + (rand()%26);
							}
						}
						if(y<665) {
							if(sp[x][y+1]>=100 && sp[x][y+1]<700) {
								do {
									sp[x][y] = (200+((rand()%5)*100)) + (rand()%26) + 26;
								} while(sp[x][y]/100==3);
							}
							if(sp[x][y+1]>=700) {
								sp[x][y] = (grey(rand())*100) + (rand()%26);
							}
						}
					}
				}
			}
		}
		srand(time(NULL));
		for(c=0; c<1369; c++) {
			cpr[c] = rand()%4;
			xpr[c] = 11+(rand()%655);
			ypr[c] = 50+(rand()%616);
			if(sp[xpr[c]][ypr[c]]>0) { c--; }
			for(i=c-1; i>=0; i--) {
				if(xpr[i]==xpr[c] && ypr[i]==ypr[c]) {
					i = 0; c--;
				}
			}
		}
		for(c=0; c<37; c++) {
			oar[c] = 100;
			yar[c] = 0;
			xar[c] = 11+(rand()%655);
			for(i=c-1; i>=0; i--) {
				if(xar[i]==xar[c]) {
					i = 0; c--;
				}
			}
		}
		for(c=0; c<11; c++) {
			plp[c] = 0;
		}
		plx = 0; ply = 0; plc = 0;
		bby = 42 + (rand()%36); bbx = 333 + (rand()%333);
		// CÓDIGO DO JOGO
		t = time(NULL); cl = 0; plv = 5; plo = 100;
		do {
			s = time(NULL) - t;
			for(m=0; s>=60; m++) { s-=60; }
			for(h=0; m>=60; h++) { m-=60; }
			mk = time(NULL) - ti;
			ti = time(NULL);
			// CÁLCULO DO TEMPO
			gotoxy(0,0); collor(15); printf("\n    TEMPO: ");
			if(h>0) { printf("%d hrs, ",h); }
			if(m>0) { printf("%d min, ",m); }
			printf("%d sec",s);
			if(h+m>0) { printf(" (%d s)",time(NULL)-t); }
			printf("  ||  %d CICLO",cl); if(cl!=1) { printf("S"); }
			printf("  ||  %d VIDA",plv); if(plv>1) { printf("S"); }
			printf(": "); collor(12);
			for(c=0; c<5; c++) {
				if(c<plv) {
					printf("<3");
				} else {
					printf("  ");
				}
				printf(" ");
			}
			collor(15);
			printf("      \n    PROFUNDIDADE: %d m (%d m da Costa)  |",ply,plx);
			if(plo<33) {
				c = 12;
			} else {
				if(plo<66) {
					c = 14;
				} else {
					c = 10;
				}
			}
			collor(c); printf("|  O2: ");
			if(plo<10) { printf("0"); }
			printf("%d %%       \n    ",plo);
			collor(13);
			for(c=0; c<11; c++) {
				if(plp[c]<100) {
					printf("0");
					if(plp[c]<10) {
						printf("0");
					}
				}
				printf("%d ",plp[c]);
			}
			if(plv==1 && plc!=1) {
				printf(" # %d %d",bbx,bby);
			}
			for(c=0; c<99; c++) {
				if(c%33==0) {
					printf("\n    ");
				}
				if(c<plo) {
					if(rand()%2==0) {
						i = grey(rand());
					} else {
						i = h2o(rand());
					}
				} else {
					i = 0;
				}
				collor(i);
				printf("O");
			}
			for(y=ply-11; y<ply+11; y++) {
				printf("\n    "); srand(x*y+time(NULL));
				for(x=plx-16; x<=plx+16; x++) {
					if(x<0 || x>=666 || y<0 || y>=666) {
						collor((rand()%2)*13);
						printf("*");
					} else {
						if(sp[x][y]>=100) {
							collor(sp[x][y]/100);
							printf("%c",abc[sp[x][y]%100]);
						} else {
							if(sp[x][y]==0) {
								water(rand());
							} else {
								if(sp[x][y]<0) {
									collor(15);
									curso(cpr[-sp[x][y]]%4);
								} else {
									if(sp[x][y]>2) {
										collor(14);
										printf("%d",(oar[sp[x][y]-3]%100)/10);
									} else {
										if(sp[x][y]==1) {
											collor(12);
											printf("#");
										} else {
											collor(10);
											printf("@");
										}
									}
								}
							}
						}
					}
				}
			}
			if(plc>0) {
				printf("\n    ");
				if(plc==1) {
					collor(12);
					printf("CAIXA-PRETA ENCONTRADA: LEVE-A ATE A MARGEM");
					if(plx+ply==0) {
						plv = -42;
					}
				} else {
					collor(14);
					printf("TANQUE %d: ",plc-2);
					if(oar[plc-3]<100) {
						printf("0");
						if(oar[plc-3]<10) {
							printf("0");
						}
					}
					printf("%d %% :: Q = USAR",oar[plc-3]);
				}
			}
			for(x=0; x<666; x++) {
				for(y=0; y<666; y++) {
					if(sp[x][y]<100) {
						sp[x][y] = 0;
					}
				}
			}
			// PRINT DA TELA
			to = time(NULL);
			do {
				c = time(NULL) - to;
				if(kbhit()) {
					c = getch();
					if(c==224) {
						i = getch();
					}
					if(c==119 || c==87 || i==72) {
						if(ply>0) {
							if(sp[plx][ply-1]<100) {
								ply--;
							}
						}
					}
					if(c==115 || c==83 || i==80) {
						if(ply<665) {
							if(sp[plx][ply+1]<100) {
								if(plc==0) {
									ply++;
								} else {
									if(ply<664) {
										if(sp[plx][ply+2]<100) {
											ply++;
										}
									}
								}
							}
						}
					}
					if(c==97 || c==65 || i==75) {
						if(plx>0) {
							if(sp[plx-1][ply]<100) {
								if(plc==0) {
									plx--;
								} else {
									if(ply<665) {
										if(sp[plx-1][ply+1]<100) {
											plx--;
										}
									}
								}
							}
						}
					}
					if(c==100 || c==68 || i==77) {
						if(plx<665) {
							if(sp[plx+1][ply]<100) {
								if(plc==0) {
									plx++;
								} else {
									if(ply<665) {
										if(sp[plx+1][ply+1]<100) {
											plx++;
										}
									}
								}
							}
						}
					}
					if(c==13 || c==32) {
						if(plx==bbx && ply==bby) {
							plc = 1;
						} else {
							for(c=0; c<37; c++) {
								if(xar[c]==plx && yar[c]==ply) {
									plc = c + 3; c = 37;
								}
							}
						}
					}
					if(c==113 || c==81) {
						if(plc>0) {
							if(plc>1) {
								while(oar[plc-3]>plo) {
									oar[plc-3]--;
									plo++;
								}
							}
							plc = 0;
							system("cls");
						}
					}
					if(c==82 || c==114) {
						plo--;
						for(c=0; c<9; c++) {
							plp[c] = ply;
						}
					}
					if(c==112 || c==80) {
						to = time(NULL) - t;
						gotoxy(30,11);
						collor(10);
						printf("  JOGO  ");
						gotoxy(30,12);
						printf("PAUSADO ");
						do {
							c = 0;
							i = getch();
							if(i==48 || i==79 || i==111 || i==112 || i==80) {
								t+=to; c = 1;
								if(i==48 || i==79 || i==111) {
									plv = 0;
								}
							}
						} while(c==0);
					}
				}
				if(plx<0) { plx = 0; }
				if(plx>=666) { plx = 665; }
				if(ply<0) { ply = 0; }
				if(ply>=666) { ply = 665; }
			} while(c==0);
			for(i=10; i>0; i--) {
				plp[i] = plp[i-1];
			}
			if(plp[0]<plp[10]-8) {
				plv--; plc = 0; plx = 0; ply = 0;
				for(c=0; c<11; c++) {
					plp[c] = 0;
				}
			}
			plp[0] = ply;
			cl++;
			if(mk>0) {
				if(s%6==0) {
					if(plo>0) {
						if(ply>0) {
							plo--;
						} else {
							if(plo<100) {
								plo++;
							}
						}
					} else {
						plv--; plc = 0; plx = 0; ply = 0; plo = plv*25;
					}
				}
				if(ply<665 && time(NULL)-to>0) {
					if(sp[plx][ply+1]<100) {
						if(plc==0) {
							ply++;
						} else {
							if(ply<664) {
								if(sp[plx][ply+2]<100) {
									ply++;
								}
							}
						}
					}
				}
				if(bby<665) {
					if(sp[bbx][bby+1]<100) {
						bby++;
					}
				}
				for(c=0; c<37; c++) {
					if(oar[c]<100) { oar[c]++; }
					if(yar[c]<665 && c!=plc-3) {
						if(sp[xar[c]][yar[c]+1]<100) {
							yar[c]++;
						}
					}
				}
			}
			if(plc>0) {
				if(plc==1) {
					bbx = plx;
					bby = ply + 1;
				} else {
					xar[plc-3] = plx;
					yar[plc-3] = ply + 1;
				}
			}
			sp[plx][ply] = 2;
			// INÍCIO DAS IAS
			if(mk>0 || rand()%5==0) {
				for(c=0; c<1369; c++) {
					if(rand()%3>0) {
						if(cpr[c]>=4) {
							if(rand()%3>0) {
								if(cpr[c]%2==1) {
									if(xpr[c]<plx) { xpr[c]++; cpr[c]=5; }
									if(xpr[c]>plx) { xpr[c]--; cpr[c]=7; }
								} else {
									if(ypr[c]<ply) { ypr[c]++; cpr[c]=6; }
									if(ypr[c]>ply) { ypr[c]--; cpr[c]=4; }
								}
							} else {
								if(rand()%2==0) {
									cpr[c]++;
								} else {
									cpr[c]--;
								}
								cpr[c] = 4+(cpr[c]%4);
							}
							if(plx==xpr[c] && ply==ypr[c]) {
								if(rand()%2==0) {
									plv--; plc = 0; plx = 0; ply = 0;
								}
							}
						} else {
							mk = cpr[c];
							for(p=1; p<3; p++) {
								x = xpr[c]; y = ypr[c];
								switch(cpr[c]) {
									case 0: y-=p; break;
									case 1: x+=p; break;
									case 2: y+=p; break;
									case 3: x-=p; break;
								}
								if(x>=0 && x<666 && y>=0 && y<666) {
									if(sp[x][y]!=0) {
										if(rand()%2==0) {
											cpr[c]++;
										} else {
											cpr[c]--;
										}
										cpr[c] = cpr[c]%4;
									}
								} else {
									if(rand()%2==0) {
										cpr[c]++;
									} else {
										cpr[c]--;
									}
									cpr[c] = cpr[c]%4;
								}
								if(y==ply && plx==x) {
									if(rand()%2==0) {
										cpr[c]++;
									} else {
										cpr[c]--;
									}
									cpr[c] = cpr[c]%4;
								}
								for(i=0; i<1369; i++) {
									if(i<37) {
										if(y==yar[i] && xar[i]==x) {
											if(rand()%2==0) {
												cpr[c]++;
											} else {
												cpr[c]--;
											}
											cpr[c] = cpr[c]%4;
											i = 1368;
										}
									}
									if(y==ypr[i] && x==xpr[i]) {
										if(rand()%2==0) {
											cpr[c]++;
										} else {
											cpr[c]--;
										}
										cpr[c] = cpr[c]%4;
										i = 1369;
									}
								}
							}
							if(plx==xpr[c] && ply==ypr[c] && rand()%2==0) {
								cpr[c]+=4;
							}
							if(cpr[c]==mk) {
								x = xpr[c]; y = ypr[c];
								switch(cpr[c]) {
									case 0: y--; break;
									case 1: x++; break;
									case 2: y++; break;
									case 3: x--; break;
								}
								xpr[c] = x; ypr[c] = y;
							}
						}
					}
					if(xpr[c]<0) { xpr[c] = 0; cpr[c]=rand()%4; }
					if(ypr[c]<0) { ypr[c] = 0; cpr[c]=rand()%4; }
					if(xpr[c]>=666) { xpr[c] = 665; cpr[c]=rand()%4; }
					if(ypr[c]>=666) { ypr[c] = 665; cpr[c]=rand()%4; }
				}
			}
			// FIM DAS IAS
			for(c=0; c<1369; c++) {
				if(xpr[c]==plx && ypr[c]==ply && rand()%4==0 && cpr[c]<4) {
					cpr[c]+=4;
				}
				sp[xpr[c]][ypr[c]] = -c;
			}
			for(c=0; c<37; c++) {
				sp[xar[c]][yar[c]] = c + 3;
			}
			sp[bbx][bby] = 1;
		} while(plv>0);
		c = 0;
		while(c<3) {
			system("cls");
			collor(12+(rand()%4));
			printf("\n\n    ");
			if(plv==-42) {
				printf("DADOS DE VOO RESGATADOS");
			} else {
				printf("VOCE FOI MORTO ");
				if(plo<=0) {
					printf("PELA ASFIXIA");
				} else {
					printf("PELOS PERIGOS DO MAR");
				}
			}
			printf("\n\n");
			switch (c) {
				case 0: printf("\n\n    JOGAR   SAIR \n"); break;
				case 1: printf("   _______ \n  |       | \n  | JOGAR | SAIR \n  |_______|"); break;
				case 2: printf("           ______ \n          |      | \n    JOGAR | SAIR | \n          |______|"); break;
			}
			do {
				t = getch();
			} while(t==224);
			if(t==49 || t==65 || t==97 || t==75) {
				c = 1;
			}
			if(t==48 || t==68 || t==100 || t==77) {
				c = 2;
			}
			if(t==32 || t==13) {
				if(c>0) {
					c++; c++;
				}
			}
		}
		if(c==3) {
			c = 1;
		}
	} while(c==1);
}
void proc () {
	srand(time(NULL));
	collor(h2o(rand()));
	sleep(1);
	if(kbhit()) {
		getch();
	}
	printf("\n    ");
}
void open () {
	// INTRO DO JOGO ---- INÍCIO
	system("cls");
	proc();
	printf("UMA AERONAVE CAIU: O");
	collor(15); printf(" ALBATROZ");
	proc();
	printf("NAO SE SABE A CAUSA DA QUEDA \n");
	proc();
	printf("PARA QUE AS INVESTIGACOES DESCUBRAM A CAUSA DO TERRIVEL ACIDENTE");
	proc();
	printf("E NECESSARIO O RESGATE DOS DADOS DE VOO NA CAIXA-PRETA DA AERONAVE ");
	collor(15); printf("# \n\a");
	proc();
	printf("POREM, \n    ");
	collor(15); printf("O ALBATROZ");
	proc();
	printf("CAIU NO MAR \a\n\n");
	proc();
	printf("VOCE E UM DOS MERGULHADORES:");
	collor(10); printf(" @");
	proc();
	printf("E DEVE ENCONTRAR A CAIXA-PRETA DO ");
	collor(15); printf("ALBATROZ");
	proc();
	printf("CUIDADO COM OS PEIXES PREDADORES: ");
	collor(15); curso(rand()%4);
	proc();
	printf("SE REABASTECA DE OXIGENIO NOS TANQUES QUE JOGAMOS: ");
	collor(14); printf("0");
	proc();
	printf("NAO SUBA MUITO RAPIDO PARA NAO SOFRER DE EMBOLIA \n\n    ");
	collor(10); sleep(1);
	printf("WASD ou <^v> \n    ");
	collor(11); sleep(1);
	printf("ESPACO ou ENTER = PEGAR \n    ");
	collor(12); sleep(1);
	printf("Q = USAR & LARGAR \n    ");
	collor(13); sleep(1);
	printf("R = ESTABILIZAR PRESSAO ATMOSFERICA \n\a\n    ");
	collor(14); sleep(1);
	printf("APERTE QUALQUER TECLA PARA INICIAR");
	getch();
	// INTRO DO JOGO ---- FIM
	ojogo();
}
int main () {
	int c, t, x, y, cr[120][29];
	char an[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	do {
		srand(time(NULL));
		system("cls");
		for(x=0; x<120; x++) {
			for(y=0; y<29; y++) {
				if(rand()%111==0) {
					cr[x][y] = 100 + ((rand()%8)*100) + (rand()%62);
				} else {
					cr[x][y] = 0;
				}
			}
		}
		do {
			gotoxy(0,0);
			for(y=0; y<29; y++) {
				for(x=0; x<120; x++) {
					collor(cr[x][y]/100);
					printf("%c",an[cr[x][y]%100]);
				}
				printf("\n");
			}
			gotoxy(50+(rand()%21),1+rand()%6);
			collor(10+(rand()%6));
			printf("  APERTE QUALQUER TECLA PARA INICIAR  ");
			for(y=0, c=0; y<30; y++) {
				for(x=0; x<120; x++) {
					if(rand()%3==0 && cr[x][y]==0) {
						if(x>0) {
							if(cr[x-1][y]>1) {
								cr[x][y]=1; c++;
							}
						}
						if(y>0) {
							if(cr[x][y-1]>1) {
								cr[x][y]=1; c++;
							}
						}
						if(x<119) {
							if(cr[x+1][y]>1) {
								cr[x][y]=1; c++;
							}
						}
						if(y<29) {
							if(cr[x][y+1]>1) {
								cr[x][y]=1; c++;
							}
						}
					}
				}
			}
			if(c==0) {
				for(x=0; x<120; x++) {
					for(y=0; y<29; y++) {
						if(rand()%111==0) {
							cr[x][y] = 100 + ((rand()%8)*100) + (rand()%62);
						} else {
							cr[x][y] = 0;
						}
					}
				}
			} else {
				srand(time(NULL)*c);
				for(y=0; y<30; y++) {
					for(x=0; x<120; x++) {
						if(cr[x][y]==1) {
							cr[x][y] = 100 + ((rand()%8)*100) + (rand()%62);
							c--;
						}
						if(c<=0) {
							y = 30;
						}
					}
				}
			}
			t = time(NULL);
			while(time(NULL)-t<1) {
				c = 0;
				if(kbhit()) {
					c = getch();
					if(c==224) {
						getch();
					}
					c = 42;
					t--;
				}
			}
		} while(c==0);
		c = 0;
		while(c<3) {
			system("cls");
			collor(15);
			printf("\n\n    ALBATROZ CAIDO \n\n");
			srand(t+c+time(NULL));
			collor(h2o(rand()));
			switch (c) {
				case 0: printf("\n\n    JOGAR   SAIR \n"); break;
				case 1: printf("   _______ \n  |       | \n  | JOGAR | SAIR \n  |_______|"); break;
				case 2: printf("           ______ \n          |      | \n    JOGAR | SAIR | \n          |______|"); break;
			}
			do {
				t = getch();
			} while(t==224);
			if(t==49 || t==65 || t==97 || t==75) {
				c = 1;
			}
			if(t==48 || t==68 || t==100 || t==77) {
				c = 2;
			}
			if(t==32 || t==13) {
				if(c>0) {
					c++; c++;
				}
			}
		}
		if(c==3) {
			open();
		}
	} while(c!=4);
	return 0;
}
