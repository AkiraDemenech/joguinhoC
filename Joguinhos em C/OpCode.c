#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>

#define CINZA 8
#define VERDE 10
#define AZUL 11
#define VERMELHO 12
#define AMARELO 14
#define BRANCO 15

void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void gmg () {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char abc[] = " 0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
	int c, t=time(NULL), k, i, plp, ag[3], psh[10], nbl, bnl, gun, ash[6], ct[9], sp[2420], ht, zkl, vic=0, v1=0, def=0, d1=0, tv=0, td=0, tvm=0, tdm=0;
	SetConsoleTextAttribute (hConsole, VERDE); system("cls");
	printf("\n\n    SPACE BAR - SHOOT"); sleep(1);
	printf("\n    Q - RESET BULLETS"); sleep(1);
	printf("\n    E - KICK / PUNCH"); sleep(1);
	printf("\n    P - PAUSE THE GAME"); sleep(1);
	printf("\n\n             W - UP"); sleep(1);
	printf("\n   A-LEFT"); sleep(1);
	printf("    S-DOWN"); sleep(1);
	printf("   D-RIGHT"); sleep(2);
	printf("\n\n    YOU ARE THIS BLUE CARACTER --> "); sleep(1);
	SetConsoleTextAttribute (hConsole, AZUL);  printf("&"); SetConsoleTextAttribute (hConsole, VERDE);
	sleep(1); printf(" --> WITH THIS GUN --> "); sleep(1);
	SetConsoleTextAttribute (hConsole, AZUL);  printf("|");
	SetConsoleTextAttribute (hConsole, VERDE); printf(" or ");
	SetConsoleTextAttribute (hConsole, AZUL);  printf("-");
	SetConsoleTextAttribute (hConsole, VERDE);
	sleep(1); printf("\n    KILL THESE WHITE AGENTS  -->   "); sleep(1);
	SetConsoleTextAttribute (hConsole, BRANCO);  printf("@"); SetConsoleTextAttribute (hConsole, VERDE);
	sleep(1); printf("\n    THIS IS A SHOOTED BULLET -->   "); sleep(1);
	SetConsoleTextAttribute (hConsole, VERMELHO);  printf("*"); SetConsoleTextAttribute (hConsole, VERDE);
	sleep(1); printf("\n    AND CITIZENS CAN \n    BE ASSIMILATED BY AGENTS  -->  "); sleep(1);
	SetConsoleTextAttribute (hConsole, AMARELO);  printf("#"); SetConsoleTextAttribute (hConsole, VERDE);
	sleep(2); printf("\n\n\n    ARE YOU READY ???? \n"); sleep(1); printf("    PRESS ANY KEY TO START THE GAME");
	fflush(stdin); k = getch(); fflush(stdin); system("cls");
	do {
		int lx, ly, a, ai;
		srand(time(NULL)); sp[0]=0; sp[1]=1+(rand()%62);
		if(rand()%11==0) { do { zkl=1+(rand()%62); } while(sp[zkl]==0); } else { zkl=0; }
		for(c=2; c<2420; c++) {
			do {
				if(rand()%(11+(rand()%32))==0) { srand(rand()+c); }
				lx=3+(rand()%42); ly=3+(rand()%53);
				a=lx*ly; ai=(lx-2)*(ly-2);
				if(lx*ly<(2*(lx+ly))-1 && rand()%4>0) { i=1; } else { i=0; }
			} while(i==1);
			if(rand()%a>ai) { sp[c]=0; } else { sp[c]=rand()%63; }
			if(c>56 && (rand()%(lx+ly-1)>1 || rand()%((2*(lx+ly))-4)>3)) {
				if(((sp[c-1]==0 && rand()%lx>0) || (sp[c-55]==0 && rand()%ly>0)) && sp[c-56]>0) { sp[c]=0; }
			}
			if(c<56 || c>2364 || c%55==0 || c%55==54) { sp[c]=0; }
			if(c%55==1 || c%55==53 || c<110 || c>2364) { sp[c]=1+(rand()%62); }
		}
		ht=5; plp=1; gun=2; srand(t+time(NULL)); t = time(NULL); int m, s, clock=0, tt, stp;
		for(c=0; c<9; c++) {
			if(c<5) { psh[c]=0; }
			if(c<3) { ash[c]=0; do {
				ag[c] = rand()%2420;
				if(ag[c]<550 && rand()%5>0) { ag[c]=0; }
				if(ag[c]<1100 && rand()%3>0) { ag[c]=0; }
				for(i=c-1; i>=0; i--) {
					if(ag[c]==ag[i]) { ag[c]=0; i=0; }
					if(ag[c]==ct[i]) { ag[c]=0; i=0; }
				}
			} while(sp[ag[c]]==0 || ag[c]==0); }
			do {
				ct[c] = rand()%2420;
				if(ct[c]<226 && ct[c]%55<7) { ct[c]=0; }
				for(i=c-1; i>=0; i--) {
					if(ct[c]==ag[i] && c<3) { ct[c]=0; i=0; }
					if(ct[c]==ct[i]) { ct[c]=0; i=0; }
				}
			} while(sp[ct[c]]<10 || ct[c]==0);
		}
	while(plp>0) {
		s = time(NULL)-t; for(m=0; s>=60; m++) { s=s-60; } for(c=0, nbl=0, bnl=-1; c<5; c++) { if(psh[c]==0) { nbl++; bnl=c; } }
		stp = plp-550; if(plp<550) { stp=0; } if(plp>=1869) { stp=1265; } while(stp%55>0) { stp--; }
		if((time(NULL)-t)%11==0 || time(NULL)%11==0 || rand()%11==0 || plp==1) { system("cls"); }
		gotoxy(0,0); SetConsoleTextAttribute (hConsole, VERDE);
		printf("\n\n    TIME: %d min %d sec (%d s) || CICLES: %d || %d BULLETS: ",m,s,time(NULL)-t,clock,nbl);
		SetConsoleTextAttribute (hConsole, VERMELHO);
		for(c=0; c<nbl; c++) { printf("*"); }
		SetConsoleTextAttribute (hConsole, VERDE);
		printf(" || %d LIFES: ",ht);
		SetConsoleTextAttribute (hConsole, VERMELHO);
		for(c=0; c<ht; c++) { printf("<3 "); }
		SetConsoleTextAttribute (hConsole, AZUL);
		printf(" || POSITION: %d, %d (%d) \n\n    ",plp%55,plp/55,plp);
		for(c=stp, i=1; c<=stp+1100; c++, i++) {
			if(c==0) { SetConsoleTextAttribute (hConsole, VERDE); printf("%c",abc[sp[0]]); c++; }
			if(c==ag[0] || c==ag[1] || c==ag[2]) { SetConsoleTextAttribute (hConsole, BRANCO); printf("@"); } else {
				if(c==ash[0] || c==ash[1] || c==ash[2]) { SetConsoleTextAttribute (hConsole, VERMELHO); printf("*"); } else {
					if(c==ct[0] || c==ct[1] || c==ct[2] || c==ct[3] || c==ct[4] || c==ct[5] || c==ct[6] || c==ct[7] || c==ct[8]) {
						SetConsoleTextAttribute (hConsole, AMARELO); printf("#"); } else {
						if(c==psh[0] || c==psh[1] || c==psh[2] || c==psh[3] || c==psh[4]) { SetConsoleTextAttribute (hConsole, VERMELHO); printf("*"); } else {
							if(c==plp) { SetConsoleTextAttribute (hConsole, AZUL); printf("&"); } else {
								if((c==plp-55 && gun==0) || (c==plp+55 && gun==2)) { SetConsoleTextAttribute (hConsole, AZUL); printf("|"); } else {
									if((c==plp+1 && gun==1) || (c==plp-1 && gun==3)) { SetConsoleTextAttribute (hConsole, AZUL); printf("-"); } else {
										if(c==zkl) {
											if(rand()%4>0) { SetConsoleTextAttribute (hConsole, CINZA); } else {
												if(rand()%3>0) { SetConsoleTextAttribute (hConsole, VERDE); } else {
													int cor=rand()%6;
													if(cor==0) { cor=8; }
													if(cor==1) { cor=10; }
													if(cor==2) { cor=11; }
													if(cor==3) { cor=12; }
													if(cor==4) { cor=14; }
													if(cor==5) { cor=15; }
													SetConsoleTextAttribute (hConsole, cor);
												}
											}
											printf("%%");
										} else {
											SetConsoleTextAttribute (hConsole, VERDE);
											printf("%c",abc[sp[c]]);
										}
									}
			} } } } } }
			if(c%55==54) { printf("\n    "); }
		}
		SetConsoleTextAttribute (hConsole, BRANCO);
		printf("    ");
		switch (gun) {
			case 0: printf("UP   "); break;
			case 1: printf("RIGHT"); break;
			case 2: printf("DOWN "); break;
			case 3: printf("LEFT "); break;
		}
		SetConsoleTextAttribute (hConsole, VERDE);
		printf("\n    KILL ALL THE AGENTS \n    Agents Alive");
		for(c=0, i=0; c<3; c++) { if(ag[c]>0) { i++; } } printf(" (%d): ",i); if(i==0) { plp=-121; }
		for(c=0; c<3; c++) {
			if(ag[c]==0) { SetConsoleTextAttribute (hConsole, AMARELO); printf("0"); } else {
				if(ag[c]>=stp && ag[c]<=stp+1100) { SetConsoleTextAttribute (hConsole, VERMELHO); }
				if(ag[c]<stp || ag[c]>stp+1100) { SetConsoleTextAttribute (hConsole, BRANCO); }
				printf("A");
			}
			printf(" ");
		}
		SetConsoleTextAttribute (hConsole, VERDE);
		printf("\n    Citizens Alive");
		for(c=0, i=0; c<9; c++) { if(ct[c]>0) { i++; } } printf(" (%d): ",i);
		for(c=0; c<9; c++) {
			if(ct[c]==0) {
				SetConsoleTextAttribute (hConsole, VERMELHO); printf("X");
			} else { SetConsoleTextAttribute (hConsole, BRANCO); printf("C"); }
			printf(" ");
		}
		tt = time(NULL); i = clock; while(i==clock) {
			fflush(stdin);
			if(time(NULL)-tt>=1) { clock++; }
			if(kbhit()) { k = getch();
				if(k==32 && nbl>0) { psh[bnl] = plp; clock++;
					switch (gun) {
						case 0: psh[bnl+5] = plp+55; break;
						case 1: psh[bnl+5] = plp-1; break;
						case 2: psh[bnl+5] = plp-55; break;
						case 3: psh[bnl+5] = plp+1; break;
					}
				} else {
					if(k==80 || k==112) {
						SetConsoleTextAttribute (hConsole, VERDE);
						printf("PAUSE == Press O to FINISH THE GAME");
						do { fflush(stdin); k=0;
							if(kbhit()) { k=getch();
								if(k==48) { plp=0; ht=0; k=112; }
								if(k==79 || k==111) { plp=0; ht=0; k++; }
								if(k!=80 && k!=112) { k=0; }
							}
							fflush(stdin);
						} while(k==0);
						system("cls");
					}
					if(k==81 || k==113) { for(c=0; c<5; c++) { if(psh[c]==0) { c++; } else { psh[c]=0; if(i==clock) { clock++; } } } }
					if(k==65 || k==97) { gun=3; clock++; if(sp[plp-1]>0 && plp%55>0) { plp--; } }
					if(k==68 || k==100) { gun=1; clock++; if(sp[plp+1]>0 && plp%55<54) { plp++; } }
					if(k==83 || k==115) { gun=2; clock++; if(sp[plp+55]>0 && plp<2364) { plp=plp+55; } }
					if(k==87 || k==119) { gun=0; clock++; if(sp[plp-55]>0 && plp>55) { plp=plp-55; } }
					if(k==69 || k==101) {
						if(zkl==plp+1 || zkl==plp-1 || zkl==plp+55 || zkl==plp-55) {
							clock++; if(rand()%5==0) { zkl=1; if(rand()%2==0) { zkl--; } }
						}
						for(c=0; c<9; c++) {
							if(ct[c]==plp) { ct[c]=0; c=9; clock++; }
							if(ct[c]==plp+1 || ct[c]==plp-1 || ct[c]==plp+55 || ct[c]==plp-55) {
								if(rand()%5>0) { ct[c]=0; c=9; clock++; }
							}
							if(c<3) {
								if(ash[c]==plp+1 || ash[c]==plp-1 || ash[c]==plp+55 || ash[c]==plp-55) {
									if(rand()%5==0) { ash[c]=0; c=9; clock++; }
								}
								if(ag[c]==plp+56 || ag[c]==plp-56 || ag[c]==plp+54 || ag[c]==plp-54) {
									if(rand()%5>2) { ag[c]=0; c=9; clock++; }
								}
								if(ag[c]==plp+1 || ag[c]==plp-1 || ag[c]==plp+55 || ag[c]==plp-55) {
									if(rand()%5>1) { ag[c]=0; c=9; clock++; }
								}
								if(ag[c]==plp) { ag[c]=0; c=9; clock++; }
							}
						}
					}
				}
			}
			fflush(stdin);
		}
		sp[plp]=1+(rand()%62);
		for(c=0; c<5; c++) {
			i=psh[c]; if(sp[i]==0) { psh[c]=0; } sp[i]=1+(rand()%62);
			if(psh[c]>0) {
				if(psh[c]%55>0 && psh[c]%55<54 && psh[c]>55 && psh[c]<2364) {
					i=psh[c]; psh[c]=(2*psh[c])-psh[c+5]; psh[c+5]=i;
				} else { psh[c]=0; }
				for(i=0; i<9; i++) { if(ct[i]==psh[c] && rand()%5>0) { ct[i]=0; psh[c]=0; i=9; } }
				for(i=0; i<3; i++) {
					if(psh[c]==ag[i] && rand()%3>0) { ag[i]=0; psh[c]=0; i=3; }
					if(psh[c]==ash[i] && rand()%2==0) { ash[i]=0; psh[c]=0; i=3; }
				}
			} else { psh[c]=0; }
			if(c<3) {
				i=ash[c]; if(sp[i]==0) { ash[c]=0; } sp[i]=1+(rand()%62);
				if(ash[c]>0) {
					if(ash[c]%55>0 && ash[c]%55<54 && ash[c]>55 && ash[c]<2364) {
						i=ash[c]; ash[c]=(2*ash[c])-ash[c+3]; ash[c+3]=i;
					} else { ash[c]=0; }
					for(i=0; i<9; i++) { if(ct[i]==ash[c] && rand()%5==0) { ct[i]=0; ash[c]=0; i=9; } }
					for(i=0; i<5; i++) { if(ash[c]==psh[i] && rand()%3>0) { psh[i]=0; ash[c]=0; i=5; } }
					if(ash[c]==plp) { ht--; plp=1; }
				} else { ash[c]=0; }
				if(ag[c]>0) {
					if(rand()%3==0) {
						if(ag[c]%55<plp%55 && ag[c]%55<54 && ag[c]<2419) { if(sp[ag[c]+1]>0) { ag[c]++; } }
						if(ag[c]%55>plp%55 && ag[c]%55>0 && ag[c]>0) { if(sp[ag[c]-1]>0) { ag[c]--; } }
						if(rand()%2==0) {
							if(rand()%2==0) {
								if(ag[c]<plp && ag[c]<2364) { if(sp[ag[c]+55]>0) { ag[c]=ag[c]+55; } }
								if(ag[c]>plp && ag[c]>55) { if(sp[ag[c]-55]>0) { ag[c]=ag[c]-55; } }
							} else {
								if(ag[c]>plp && ag[c]>55) { if(sp[ag[c]-55]>0) { ag[c]=ag[c]-55; } }
								if(ag[c]<plp && ag[c]<2364) { if(sp[ag[c]+55]>0) { ag[c]=ag[c]+55; } }
							}
						}
					}
					if(ag[c]==plp && rand()%3>0) { ht--; plp=1; }
					if(rand()%3==0 && ash[c]==0) {
						ash[c+3]=ag[c];
						if(ag[c]%55==plp%55) {
							if(ag[c]<plp) { ash[c]=ag[c]+55; }
							if(ag[c]>plp) { ash[c]=ag[c]-55; }
						} else {
							if(ag[c]%55<plp%55 && ((ag[c]>plp-55 && ag[c]<plp) || rand()%(2+(rand()%3))==0)) {
								ash[c]=ag[c]+1;
							}
							if(ag[c]%55>plp%55 && ((ag[c]<plp+55 && ag[c]>plp) || rand()%(2+(rand()%3))==0)) {
								ash[c]=ag[c]-1;
							}
						}
					}
					if(rand()%9==0 && (ag[c]<stp || ag[c]>stp+1100)) {
						for(i=0; i<9; i++) { if(ct[i]>0 && ct[i]>=plp-550 && ct[i]<=plp+550) { int d=ag[c]; ag[c]=ct[i]; ct[i]=d; i=9; } }
						if(i==10) { for(i=stp; i<stp+1100; i++) { if(sp[i]>0 || rand()%(13+(rand()%11))==0 || rand()%63==0) { sp[i]=rand()%63; } } }
					}
				} else {
					for(i=0; i<9; i++) { if(ct[i]>stp && ct[i]<stp+1100 && rand()%4==0 && ct[i]>0) { ag[c]=ct[i]; ct[i]=0; i=9; } }
					if(i==10) { for(i=stp; i<stp+1100; i++) { if(sp[i]>0 || rand()%(13+(rand()%11))==0 || rand()%63==0) { sp[i]=rand()%63; } } }
				}
			}
		}
		for(c=0; c<9; c++) {
			sp[ct[c]]=1+(rand()%62);
			if(((ct[c]>stp && ct[c]<stp+1100) || rand()%4>0) && ct[c]>0) { do {
			if(rand()%2==0) {
				if(ct[c]>1) { if(sp[ct[c]-1]>0) { ct[c]--; } }
			} else { if(ct[c]<2419) { if(sp[ct[c]+1]>0) { ct[c]++; } } }
			if(rand()%2==0) {
				if(rand()%2==0) {
					if(ct[c]>55) { if(sp[ct[c]-55]>0) { ct[c]=ct[c]-55; } }
				} else { if(ct[c]<2364) { if(sp[ct[c]+55]>0) { ct[c]=ct[c]+55; } } }
			}
		} while(rand()%3==0); } }
		if(rand()%9==0) { srand(t+time(NULL));
			if(zkl==plp && rand()%3==0 && ht<5) { ht++; }
			if(rand()%4==0 && ht<5) {
				if(zkl==plp-55 && gun==0) { ht++; }
				if(zkl==plp+1 && gun==1) { ht++; }
				if(zkl==plp+55 && gun==2) { ht++; }
				if(zkl==plp-1 && gun==3) { ht++; }
			}
			if(zkl>55 && rand()%4==0) { zkl=zkl-55; }
			if(zkl>1 && rand()%4==0) { zkl--; }
			if(zkl<2364 && rand()%4==0) { zkl=zkl+55; }
			if(zkl<2419 && rand()%4==0) { zkl++; }
			for(c=0; c<3; c++) { if(ash[c]==zkl) { ash[c]=0; } }
			for(c=0, i=0; c<9; c++) { if(ag[c]>0) { i=1; } }
			for(c=0; c<9 && i==0; c++) {
				if(rand()%9==0) {
					do { ct[c]=1+(rand()%2419);
						if(ct[c]<plp-550 || ct[c]>plp+550) { ct[c]=0; }
					} while(ct[c]==0 || sp[ct[c]]==0);
					if(rand()%9>0) { c=9; }
				}
			}
			if(rand()%5==0) {
				switch(rand()%4) {
					case 0: zkl++; break;
					case 1: zkl--; break;
					case 2: zkl=zkl+55; break;
					case 3: zkl=zkl-55; break;
				}
				for(c=0; c<9; c++) { if(ct[c]>0 || rand()%9==0) { do { ct[c]=1+(rand()%2419); } while(sp[ct[c]]==0); } }
				sp[0]=0; sp[1]=1+(rand()%62);
				for(c=2; c<2420; c++) {
					do {
						if(rand()%(11+(rand()%32))==0) { srand(rand()+c); }
						lx=3+(rand()%42); ly=3+(rand()%53);
						a=lx*ly; ai=(lx-2)*(ly-2);
						if(lx*ly<(2*(lx+ly))-1 && rand()%4>0) { i=1; } else { i=0; }
					} while(i==1);
					if(rand()%a>ai) { sp[c]=0; } else { sp[c]=rand()%63; }
					if(c>56 && rand()%((2*(lx+ly))-4)>0) { if((sp[c-1]==0 || sp[c-55]==0) && sp[c-56]>0) { sp[c]=0; } }
					if(c<56 || c>2364 || c%55==0 || c%55==54) { sp[c]=0; }
					if(c%55==1 || c%55==53 || c<110 || c>2364) { sp[c]=1+(rand()%62); }
				}
			}
		}
		if(ht<1) { plp=0; sleep(1); } if(ht>0 && plp==0) { plp=1; }
		if(ag[0]==0 && ag[1]==0 && ag[2]==0 && ht>0) { sleep(1); plp=0; }
	}
		t=time(NULL)-t; if(ht>0) { vic++; v1++; d1=0; } else { def++; d1++; v1=0; }
		if((t<tv || vic==1) && ht>0) { tv=t; } if((t<td || def==1) && ht<1) { td=t; }
		if((t>tvm || vic==1) && ht>0) { tvm=t; } if((t>tdm || def==1) && ht<1) { tdm=t; }
		SetConsoleTextAttribute (hConsole, VERDE);
		system("cls"); printf("\n\n\a  GAME OVER \n"); sleep(1); i=0; c=1;
		do {
			if(c!=i) {
				system("cls"); printf("\n\n  GAME OVER \n");
				if(ht>0) { printf("  ALL AGENTS KILLED \n"); }
				printf("\n  %d seconds running THE GAME \n\n  Record Time: \n  ",t);
				if(tv>0) {
					if(ht>0) { printf("VICTORY"); } else { printf("victory"); }
					printf(": %d secs (smaller)",tv); if(tv==t && ht>0) { printf(" <-- (this ROUND)"); }
					if(tvm!=tv) { printf(" / %d secs (bigger)",tvm); if(tvm==t && ht>0) { printf(" <-- (this ROUND)"); } }
				}
				printf("\n  ");
				if(td>0) {
					if(ht==0) { printf("DEFEAT"); } else { printf("defeat"); }
					printf(": %d secs (smaller)",td); if(td==t && ht==0) { printf(" <-- (this ROUND)"); }
					if(tdm!=td) { printf(" / %d secs (bigger)",tdm); if(tdm==t && ht==0) { printf(" <-- (this ROUND)"); } }
				}
				printf("\n\n  VICTORIES: %d",vic);
				if(v1>0) {
					printf(" (%d",v1);
					if(v1>3) { printf("th"); } else {
						if(v1==1) { printf("st"); }
						if(v1==2) { printf("nd"); }
						if(v1==3) { printf("rd"); }
					}
					printf(" in the Sequence)");
				}
				printf("\n  DEFEATS: %d",def);
				if(d1>0) {
					printf(" (%d",d1);
					if(d1>3) { printf("th"); } else {
						if(d1==1) { printf("st"); }
						if(d1==2) { printf("nd"); }
						if(d1==3) { printf("rd"); }
					}
					printf(" in the Sequence)");
				}
				printf("\n\n  PLAY AGAIN? \n");
				if(i==0) { printf("\n\n   Yes   No \n"); }
				if(i==1) { printf("        ____ \n       |    | \n   Yes | No | \n       |____|"); }
				if(i==2) { printf("  _____ \n |     | \n | Yes | No \n |_____|"); }
				printf("\n\n  PRESS RIGHT AND LEFT TO SELECT \n");
				if(i>0) { printf("  PRESS SPACE TO CONTINUE \n"); }
			}
			fflush(stdin); c=i; if(kbhit()) { k = getch();
					if(k==49 || k==89 || k==121) { i = 2; }
					if(k==48 || k==78 || k==110) { i = 1; }
					if(k==32 && i>0) { i=i+2; }
					if(k==224) { k = getch(); fflush(stdin); if(k==77) { i = 1; } if(k==75) { i = 2; } }
				}
			fflush(stdin);
		} while(i<3);
		if(i==4) { plp=1; } if(i==3) { plp=0; }
	} while(plp>0);
}
int main () { int k = 1, c, p, t; while(k==1) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, VERDE);
	for(c=0, k=0; k==0; c++) {
		system("cls"); printf("\n\n    PRESS ANY KEY TO CONTINUE ");
		for(k=0; k<c%4; k++) { printf("."); } k = 0; printf(" %d",c);
		t = time(NULL); while(k==0) { if(time(NULL)-t>=1) { k = 1; } if(kbhit()) { k = 2; } }
		if(k==1) { k = 0; } fflush(stdin);
	}
	k = 0; c = 1; p = 0;
	while(p<3) {
		if(c!=p) { system("cls");
			if(p==0) { printf("\n\n   START GAME     QUIT \n"); }
			if(p==1) { printf("  ____________ \n |            | \n | START GAME |   QUIT \n |____________| "); }
			if(p==2) { printf("                 ______ \n                |      | \n   START GAME   | QUIT | \n                |______| "); }
			printf("\n\n  PRESS RIGHT AND LEFT TO SELECT \n"); if(k>0) { printf("  PRESS SPACE TO CONTINUE \n"); }
		}
		c = p; if(kbhit()) { k = getch();
			if(k!=224) {
				if(k==32 && p>0) { p = p + 2; } else {
					p = c;
					if(k==65 || k==97) { p = 1; }
					if(k==68 || k==100) { p = 2; }
				}
			} else {
				k = getch();
				if(k==75) { p = 1; }
				if(k==77) { p = 2; }
			}
		}
		fflush(stdin);
	}
	if(p==3) { gmg(); } else { p = 0; c = 1;
		while(p<3) {
			if(p!=c) {
				system("cls"); printf("\n\n\n\n\n\n\n\n\n\n  Really Quit ? \n");
				if(p==0) { printf("\n\n   Yes   No \n"); }
				if(p==1) { printf("        ____ \n       |    | \n   Yes | No | \n       |____|"); }
				if(p==2) { printf("  _____ \n |     | \n | Yes | No \n |_____|"); }
				printf("\n\n  1/0, Y/N, S/N, A/N, P/N ... \n  PRESS RIGHT AND LEFT TO SELECT \n");
				if(p>0) { printf("  PRESS SPACE TO CONTINUE \n"); }
			}
			fflush(stdin); c=p;
			if(kbhit()) { k = getch();
				if(k==49 || k==83 || k==89 || k==115 || k==121) { p = 4; }
				if(k==48 || k==78 || k==110) { p = 3; } if(k==32 && p>0) { p=p+2; }
				if(k==224) { k = getch(); fflush(stdin); if(k==77) { p = 1; } if(k==75) { p = 2; } }
			}
			fflush(stdin);
		}
	}
	if(k==1) { k = 2; } if(p==3) { k = 1; }
	sleep(1); system("cls");
	SetConsoleTextAttribute (hConsole, VERDE);
} printf("\n\n    GAME OVER"); sleep(1); return 0; }
