#include<stdio.h>
#include<Windows.h>
#include<time.h>

void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void color (int bg, int ch) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, (((bg%100)%16)*16)+(((ch%100)%16)*1));
}

struct player {
	int x;
	int y;
	int size;
};

int amb[27][16];
struct player pl;

void minus () {
	int x, y;
	for(y=0; y<16; y++) {
		for(x=0; x<27; x++) {
			if(amb[x][y]!=0)
				amb[x][y]--; 
		}
	}
}

void zero () {
	int x, y;
	for(y=0; y<16; y++) {
		for(x=0; x<27; x++) {
			amb[x][y] = 0;
		}
	}
}

void newapple (int temp) {
	int x, y;
	for(y=0; y<16; y++) {
		for(x=0; x<27; x++) {
			if(amb[x][y]<0) {
				amb[x][y] = 0;
				break;
			}
		}
	}
	do {
		srand(temp+time(NULL)+pl.size+pl.x+pl.y+x+y);
		x = rand()%27;
		y = rand()%16;
	} while(amb[x][y]>0);
	amb[x][y] = -1;
}

void snake () {
	
	int c, x, y, h, m, s, t, ti, tmin=2147483647;
	
	do {
		
		t=0;
		ti = time(NULL);
		
		pl.x = 14;
		pl.y = 8;
		pl.size = 1;
		zero();
		newapple(0);
		system("color 90");
		system("cls");
		
		while(pl.size<432 && pl.size>0) {
			
			t = time(NULL) - ti;
			h = t/3600;
			m = (t%3600)/60;
			s = t%60;
			
			gotoxy(0,0);
			if((t+pl.x+pl.y+pl.size)%55==0) {
				system("cls");
				system("color 90");
				if((t+pl.x+pl.y)%4==0)
					newapple(t);
			}
			
			color(9,10);
			printf("    TIME: ");
			if(h>0)
				printf("%d : ",h);
			if(h+m>0)
				printf("%02d : ",m);
			printf("%02d ",s);
			if(h+m>0)
				printf("(%d)",t);
			printf(" |");
			
			color(9,11);
			printf("| %03d point",pl.size-1);
			if(pl.size>1)
				printf("s");
			printf(" |    \n");
			
			color(14,0);
			for(c=0; c<28; c++) {
				printf(" ");
			}
			for(y=0; y<16; y++) {
				color(14,0);
				printf(" \n ");
				
				for(x=0; x<27; x++) {
					color((amb[x][y]>0)?15:0, (amb[x][y]>0)?11:12);
					if(amb[x][y]<0)
						printf("O");
					else if(amb[x][y]==pl.size)
						printf("o");
					else
						printf(" ");
				}
			}
			color(14,0);
			printf(" \n");
			for(c=0; c<29; c++) {
				printf(" ");
			}
			
			t = time(NULL);
			do {
				
				if(kbhit()) {
					y = 0;
					x = getch();
					if(x==224 || x==0) {
						y = getch();
					}
					
					if(x>90)
						x -= 32;
					
					if(x==27)
						pl.size = 0;
					
					if(x==72) {
						zero();
						newapple(h+m+s);
					}
					
					if(x==80) {
						gotoxy(1,1);
						color(12,15);
						printf("\aPAUSE");
						t = time(NULL) - ti;
						do {
							x = getch();
							if(x>90)
								x -= 32;
						} while(x!=80);
						ti = time(NULL)-t;
						t = time(NULL) - 1;
					}
					
					if(x==87 || x==65 || x==83 || x==68 || y>0) {
						int k = 0;
						if(x==87 || y==72)
							if(pl.y>0)
								if(amb[pl.x][pl.y-1]<=0) {
									k++;
									pl.y--;
								}
						
						if(x==83 || y==80)
							if(pl.y<15)
								if(amb[pl.x][pl.y+1]<=0) {
									k++;
									pl.y++;
								}
									
						if(x==65 || y==75)
							if(pl.x>0)
								if(amb[pl.x-1][pl.y]<=0) {
									k++;
									pl.x--;
								}
									
						
						if(x==68 || y==77)
							if(pl.x<26)
								if(amb[pl.x+1][pl.y]<=0) {
									k++;
									pl.x++;
								}
						
						if(k==1)
							minus();
						t--;
						break;
					}
					
				}
				
			} while(time(NULL)-t==0);
			
			if(amb[pl.x][pl.y]<0) {
				pl.size++;
				printf("\a");
				if(pl.size<432)
					newapple((h*3600)+(m*60)+s);
			}
			
			amb[pl.x][pl.y] = pl.size;
			
		}
		system("color F0");
		printf("\n\n    ESC to Escape");	
	} while(getch()!=27);
	
}

int main () {
	snake();
	return 0;
}
