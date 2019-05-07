#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>

void gotoxy (int x, int y) {
    COORD coord = {0, 0};
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void color (int cor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, cor);
}

void printC (int c) {
	if(c<5)
	{
		char cursor[] = "^>v<+";
		printf("%c",cursor[c]);
	}
}

int abs (int x) {
	return (x<0)?-x:x;
}

int bin () {
	int ans;
	do {
		ans = getch();
		printf("\a");
		if(ans==27 || ans==48 || ans==79 || ans==111)
			ans = 0;
		if(ans==13 || ans==49 || ans==73 || ans==105)
			ans = 1;
	} while(ans<0 || ans>1);
	return ans;
}

int stay (int c) {
	color(c);
	printf("\n\aS.T.A.Y.");
	return bin();
}

int bg[777][777]; // matriz de fundo
int en[111][4]; // matriz de inimigos: ESTADO, X, Y, ALVO;
int al[110][4]; // matriz de aliados: ESTADO, X, Y, ALVO;
int ten[111][3]; // matriz de torpedos inimigos: SENTIDO, X, Y;
int tal[111][3]; // matriz de torpedos aliados: SENTIDO, X, Y;
int plx, ply, pls, plv; // variáveis do player: X, Y, Estado-Vida;

void generateBackGround () {
	srand(time(NULL));
	plx = 660;
	ply = 299;
	pls = 3;
	plv = 5;
	int x, y, c;
	for(x=0; x<777; x++) {
		for(y=0; y<777; y++) {
			srand(time(NULL)+x+y+rand());
			bg[x][y] = (rand()%5) + (100*((8*(rand()%2))+(7*(rand()%2))))*(rand()%2);
		}
	}
	for(c=0; c<111; c++) {
		srand(time(NULL)+x+y+rand());
		en[c][0] = 1;
		en[c][1] = 111 + rand()%55;
		en[c][2] = 300 + rand()%101;
		en[c][3] = rand()%111;
		if(c<110) {
			al[c][0] = 3;
			al[c][1] = 666 + rand()%55;
			al[c][2] = 300 + rand()%101;
			al[c][3] = rand()%111;
		}
	}
}

void printBackGround () {
	srand(time(NULL));
	char sp[] = ",.:;'^>v<|-+";
	/*
		0-4 (,.:;') == BackGround
		5-8 (^>v<) == cursor
		9-10 (|-) == laser
		11 (+) == Torpedo
	*/
	int x, y;
	for(y=ply-10; y<=ply+10; y++) {
		if(y>=0 && y<777)
			for(x=plx-40; x<=plx+40; x++) {
				if(x>=0 && x<777) {
					color(bg[x][y]/100);
					printf("%c",sp[bg[x][y]%100]);
				}
			}
		printf("\n    ");
	}
}

void cleanBackGround (int cicle) {
	srand(time(NULL)+cicle);
	int x, y;
	for(x=0; x<777; x++) {
		for(y=0; y<777; y++) {
			if(bg[x][y]%100>4 && bg[x][y]%100<9)
				bg[x][y] -= 800;
			if(rand()%11==0 || ((bg[x][y]%100)%11>4 && rand()%3==0))
				bg[x][y] = (rand()%5) + (100*((8*(rand()%2))+(7*(rand()%2))))*(rand()%2);
		}
	}
}

void shoot (int cor, int c, int x, int y) {
	srand(time(NULL)+cor+c+x+y);
	int i;
	for(i=0; i<22+(cor*10); i++) {
		if(x>=0 && x<777 && y>=0 && y<777) {
			if(bg[x][y]%100>4 && i>0) {
				if(rand()%(3+i)==0) {
					for(i=0; i<111; i++) {
						if(i<110) {
							if(al[i][1]==x && al[i][2]==y && (cor==12 || rand()%3==0)) {
								al[i][0] = 4;
								printf("\a");
								break;
							}
						}
						if(en[i][1]==x && en[i][2]==y && (cor==11 || cor==10 || rand()%4==0)) {
							en[i][0] = 4;
							printf("\a");
							break;
						}
					}
					i = cor*10;
				}
			}
			switch (c) {
				case 0: y--; break;
				case 1: x++; break;
				case 2: y++; break;
				case 3: x--; break;
			}
			bg[x][y] = ((cor - (8*(rand()%2)))*100) + 9 + c%2;
		} else break;
	}
}

void middle () {
	int c, i = 0;
	for(c=0; c<110; c++) {
		if(al[c][0]<4) {
			plx += al[c][1];
			ply += al[c][2];
			i++;
		}
	}
	plx /= i;
	ply /= i;
}

void newEnemy (int c) {
	int alvo = 0, d = 5555, i;
	for(i=0; i<111; i++) {
		if(en[i][0]<4)
			if(abs(en[i][1]-al[c][1]) + abs(en[i][2]-al[c][2])<d) {
				d = abs(en[i][1]-al[c][1]) + abs(en[i][2]-al[c][2]);
				alvo = i;
			}
	}
	al[c][3] = alvo;
}

void war () {
	int c, i=0;
	for(c=0; c<110; c++) {
		if(en[c][0]<4) {
			plx += en[c][1];
			ply += en[c][2];
			i++;
		}
	}
	plx /= i;
	ply /= i;
	srand(time(NULL)+i+plx+ply+rand());
	for(c=0; c<110; c++) {
		srand(time(NULL)+i+plx+ply+rand()+c);
		if(al[c][0]<4) {
			al[c][1] = plx + ((rand()%13)*(rand()%2)) - ((rand()%13)*(rand()%2));
			al[c][2] = ply + ((rand()%13)*(rand()%2)) - ((rand()%13)*(rand()%2));
			if(rand()%(1+(rand()%4))==0)
				newEnemy(c);
		}
	}
	middle();
}

void spGame () {
	
	do {
		generateBackGround(); // organiza o plano de fundo
		middle(); // posiciona o player no centro do esquadrão
		int t = time(NULL), h, m, s, clc=0, c, i, temp, enem;
		al[110][0] = 4;
		system("cls");
		do {
			temp = time(NULL);
			srand(time(NULL)+clc+rand()+enem);
			gotoxy(0,0);
			if((time(NULL)%66==0 || (time(NULL)-t)%66==0 || rand()%66==0) && rand()%11==0 )
				system("cls");
			
			color(11);
			printC(pls);
			for(c=0; c<110; c++) {
				if(al[c][0]==4)
					color(15);
				else
					color(10);
				printC(al[c][0]);
			}
			printf("\n");
			enem = 0;
			for(c=0; c<111; c++) {
				if(en[c][0]==4) {
					color(15);
				} else {
					color(12);
					enem++;
				}
				printC(en[c][0]);
			}
			
			h = (time(NULL)-t)/3600;
			m = ((time(NULL)-t)%3600)/60;
			s = (time(NULL)-t)%60;
			color(14);
			printf("\n    TIME: ");
			if(h>0)
				printf("%d hrs, ",h);
			if(m+h>0)
				printf("%02d min, ",m);
			printf("%02d sec",s);
			if(m+h>0)
				printf(" (%d s)",time(NULL)-t);
			printf(" [%d cicles] |",clc);
			
			color(13);
			printf("| POSITION: %4dx %4dy |",388-plx,388-ply);
			color(11);
			printf("| %d LIFES                       \n    ",plv);
			printBackGround();
			cleanBackGround(clc);
			color(12);
			printf("\n  %03d",enem);
			
			do {
				if(kbhit()) {
					i = 0;
					c = getch();
					if(c==224)
						i = getch();
					if(i==72 || c==87 || c==119) // para cima
					{
						pls = (pls+2)%4;
						break;
					}
					if(i==80 || c==83 || c==115) // para baixo
					{
						temp--;
						break;
					}
					if(i==75 || c==65 || c==97) // para esquerda
					{
						pls = (pls+3)%4;
						break;
					}
					if(i==77 || c==68 || c==100) // para direita
					{
						pls = (pls+1)%4;
						break;
					}
					if(c==32 || c==13) // atirar
					{
						shoot(11, pls, plx, ply);
						if(rand()%2==0)
							temp--;
						break;
					}
					if(c==81 || c==113) // dobra
					{
						switch (pls) {
							case 0: ply-=2+(rand()%13); break;
							case 1: plx+=2+(rand()%13); break;
							case 2: ply+=2+(rand()%13); break;
							case 3: plx-=2+(rand()%13); break;
						}
						break;
					}
					if(c==80 || c==112) // pause
					{
						gotoxy(39,12);
						color(11);
						printf("\aPAUSE");
						t = time(NULL) - t;
						do {
							c = getch();
						} while(c!=80 && c!=112);
						t = time(NULL) - t;
						printf("\a");
						clc--;
						break;
					}
					if(c==111 || c==79) // centro
						middle();
					if(c==99 || c==67) // combate
						war();
					if(c==27) // esc
					{
						plv = 0;
						break;
					}
				}
			} while(time(NULL)==temp);
			
			if(time(NULL)-temp>0)
				switch (pls) {
					case 0: ply--; break;
					case 1: plx++; break;
					case 2: ply++; break;
					case 3: plx--; break;
				}
			
			for(c=0; c<111; c++) {
				int boosta = 1, booste = 1;
				srand(time(NULL)+c+temp+rand());
				
				if(c<110 && rand()%5==0) {
					boosta = 1;
					if(abs(en[al[c][3]][1]-al[c][1]) + abs(en[al[c][3]][2]-al[c][2])>55)
						boosta += (rand()%11);
					if(en[al[c][3]][1]>al[c][1] && rand()%3>0)
						al[c][0] = 1;
					if(en[al[c][3]][1]<al[c][1] && rand()%3>0)
						al[c][0] = 3;
					if(en[al[c][3]][2]>al[c][2] && rand()%3>0)
						al[c][0] = 2;
					if(en[al[c][3]][2]<al[c][2] && rand()%3>0)
						al[c][0] = 0;
					if((en[al[c][3]][1]==al[c][1] || en[al[c][3]][2]==al[c][2]) && rand()%5==0)
						if(boosta<10)
							shoot(10, al[c][0], al[c][1], al[c][2]);
					if(en[al[c][3]][0]==4)
						newEnemy(c);
				}
				
				if(time(NULL)-temp==1 && rand()%2==0) {
					switch (al[c][0]) {
						case 0: al[c][2]-=boosta; break;
						case 1: al[c][1]+=boosta; break;
						case 2: al[c][2]+=boosta; break;
						case 3: al[c][1]-=boosta; break;
					}
					switch (en[c][0]) {
						case 0: en[c][2]--; break;
						case 1: en[c][1]++; break;
						case 2: en[c][2]++; break;
						case 3: en[c][1]--; break;
					}
				}
				
				if(en[c][1]<0)
					en[c][1] = 0;
				if(en[c][1]>=777)
					en[c][1] = 776;
				if(en[c][2]<0)
					en[c][2] = 0;
				if(en[c][2]>=777)
					en[c][2] = 776;
				
				if(al[c][1]<0)
					al[c][1] = 0;
				if(al[c][1]>=777)
					al[c][1] = 776;
				if(al[c][2]<0)
					al[c][2] = 0;
				if(al[c][2]>=777)
					al[c][2] = 776;
				
				if(al[c][0]<4)
					bg[al[c][1]][al[c][2]] = 1005 + al[c][0];
				if(en[c][0]<4)
					bg[en[c][1]][en[c][2]] = 1205 + en[c][0];
			}
			
			if(plx<0)
				plx = 0;
			if(plx>=777)
				plx = 776;
			if(ply<0)
				ply = 0;
			if(ply>=777)
				ply = 776;
			al[110][1] = plx;
			al[110][2] = ply;
			bg[plx][ply] = 1105 + pls;
			clc++;
		} while(plv>0 && enem>0);
	} while(stay(10));
}

void start () {
	system("cls");
	// MENU
	spGame();
}
int main () {
	int c, i;
	do {
		start();
	} while(stay(15));
	return 0;
}
