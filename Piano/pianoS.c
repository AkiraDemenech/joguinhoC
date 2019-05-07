#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<sys/time.h>

void gotoxy (int x, int y) {
    COORD coord = {0, 0};
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void color (int cor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, cor);
}

float freq (int nota) {
	switch (nota) {
		case 1: return 261.63; break; // A
		case 2: return 277.18; break; // W
		case 3: return 293.66; break; // S
		case 4: return 311.13; break; // E
		case 5: return 329.63; break; // D
		case 6: return 349.23; break; // F
		case 7: return 369.99; break; // T
		case 8: return 392; break; // G
		case 9: return 415.3; break; // Y
		case 10: return 440; break; // H
		case 11: return 466.16; break; // U
		case 12: return 493.88; break; // J
		case 13: return 523.25; break; // K
		case 14: return 554.37; break; // O
		case 15: return 587.33; break; // L
		case 16: return 622.25; break; // P
		case 17: return 659.26; break; // Ç
	}
	return 0;
}

int musical (int tecla) {
	
	if(tecla>90) {
		tecla -= 7;
		if(tecla < 128)
			tecla -= 25;
	}
		
	switch (tecla) {
		case 'A': return 1; break;
		case 'W': return 2; break;
		case 'S': return 3; break;
		case 'E': return 4; break;
		case 'D': return 5; break;
		case 'F': return 6; break;
		case 'T': return 7; break;
		case 'G': return 8; break;
		case 'Y': return 9; break;
		case 'H': return 10; break;
		case 'U': return 11; break;
		case 'J': return 12; break;
		case 'K': return 13; break;
		case 'O': return 14; break;
		case 'L': return 15; break;
		case 'P': return 16; break;
		case 'Ç': return 17; break;
	}
	
	return 0;
}

void parti (int n) {
	switch (n) {
		case 1: printf("D"); break;
		case 2: printf("D#"); break;
		case 3: printf("R"); break;
		case 4: printf("R#"); break;
		case 5: printf("M"); break;
		case 6: printf("F"); break;
		case 7: printf("F#"); break;
		case 8: printf("S"); break;
		case 9: printf("S#"); break;
		case 10: printf("L"); break;
		case 11: printf("L#"); break;
		case 12: printf("s"); break;
		case 13: printf("d"); break;
		case 14: printf("d#"); break;
		case 15: printf("r"); break;
		case 16: printf("r#"); break;
		case 17: printf("m"); break;
	}
}

void music (int opmode) {
	
	FILE *musica;
	char arq[] = "Track00.mus";
	char hex[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	if(opmode==3) {
		
		int narq;
		
		do {
			
			system("color F9");
			printf("\n    Numero do Arquivo: ");
			scanf("%d",&narq);
			
			if(narq<0)
				narq = -narq;
			
			arq[6] = hex[narq%16];
			arq[5] = hex[narq/16];
			
			musica = fopen(arq, "r");
			
			if(musica==NULL) {
				system("color C0");
				printf("\a\n  NUMERO INVALIDO");
			}
			
		} while(musica==NULL);
		
	} else {
		
		if(opmode==2) {
			int c = 1;
			do {
				
				arq[6] = hex[c%16];
				arq[5] = hex[c/16];
				musica = fopen(arq, "r");
			
			} while(musica!=NULL);
		}
		
		musica = fopen(arq, "w");
		
	}
	
	int nota, st = 1;
	float tempo;
	struct timeval antes, depois;
	
	system("cls");
	printf("\n\a    Piano - %s \n",arq);
	
	do {
		
		printf("\n    ");
		
		if(opmode==3) {
			
			if(kbhit()) {
				nota = getch();
				if(nota==8 || nota==27 || nota==48)
					st = 0;
			}
			
			tempo = 150;
			nota = fgetc(musica);
			if(nota<=32)
				nota = fgetc(musica);
			
			if(nota=='~' || nota==EOF)
				st = 0;
			
			nota -= 48;
			if(nota>9)
				nota -= 17;
			if(nota>25)
				nota -= 32;
			
		} else {
			gettimeofday (&antes, NULL);
			do {
				gettimeofday (&depois, NULL);
				
				nota = 0;
				if(kbhit()) {
					nota = getch();
					if(nota==27 || nota==8)
						st = 0;
				}
				
				tempo = depois.tv_sec - antes.tv_sec;
				
			} while(tempo<0.1 && musical(nota)==0 && st==1);
			tempo = 0;
			nota = musical(nota);
			fprintf(musica, "%c", hex[nota]);
		}
		
		Beep(freq(nota),100+tempo);
		parti(nota);
		
	} while(st==1);
	
	if(opmode<3)
		fprintf(musica, "~");
	fclose(musica);
	
}

void piano () {
	
	system("cls");
	system("color 80");
	
	color(8*16+14);
	printf("\n\a    MODO DE ABERTURA: \n");
	color(8*16+9);
	printf("\n    (0) Sair");
	printf("\n    (1) Tocando Musica");
	printf("\n    (2) Gravando Musica");
	printf("\n    (3) Musica Gravada");
	
	printf("\n");
	int mod;
	do {
		
		mod = getch() - 48;
		
	} while(mod>4 || mod<0);
	
	if(mod>0)
		music(mod);
	
}

int stay () {
	
	int r;
	system("color E0");
	printf("\n\a    SAIR ?");
	
	do {
		
		r = getch();
		if(r==0 || r>90)
			r -= 32;
		
		if(r==13 || r==32 || r==49 || r==80 || r==83 || r==84 || r==86)
			r = 0;
		
		if(r==8 || r==27 || r==48 || r==70 || r==78)
			r = 1;
		
	} while(r!=0 && r!=1);
	
	return r;
}

int main () {
	
	do {
		
		piano();
		
	} while(stay());
	
	return 0;
}
