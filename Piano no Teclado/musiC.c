#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

void gotoxy (int x, int y) {
    COORD coord = {0, 0};
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void color (int cor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, cor);
}

void nota (int n) {
	switch (n%7) {
		case 0: printf("Do"); break;
		case 1: printf("Re"); break;
		case 2: printf("Mi"); break;
		case 3: printf("Fa"); break;
		case 4: printf("Sol"); break;
		case 5: printf("La"); break;
		case 6: printf("Si"); break;
	}
}

int freq (int nota) {
	int hz = 0;
	switch (nota%7) {
		case 0: hz = 264; break;
		case 1: hz = 297; break;
		case 2: hz = 330; break;
		case 3: hz = 352; break;
		case 4: hz = 396; break;
		case 5: hz = 440; break;
		case 6: hz = 495; break;
	}
	return hz;
}

int main () {
	int c = 1, t = time(NULL), x = 0, h, m, s;
	while(c>0) {
		
		h = (time(NULL)-t)/3600;
		m = ((time(NULL)-t)%3600)/60;
		s = (time(NULL)-t)/60;
		
		x = getch();
		
		if(x==27)
			c = 0;
		else
		{
			color(15);
			printf("\n   ");
			nota(x-49);
			Beep(freq(x-49),55);
		}
	}
	return 0;
}
