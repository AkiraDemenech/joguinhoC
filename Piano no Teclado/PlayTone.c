#include<stdio.h>
#include<windows.h>
#include<conio.h>

int main () {
	int c = 1, t;
	while(c>0) {
		Beep(c,55);
		system("cls");
		system("color F");
		printf("\n      %d Hz",c);
		if(kbhit()) {
			t = getch();
			if(t>48 && t<58)
				c += t;
			switch (t) {
				case 43: c++; break;
				case 45: c--; break;
				case 13: c+=10; break;
				case 8: c-=10; break;
				case 32:
					printf("\nHz: ");
					scanf("%d",&c);
					break;
				case 27: c=0; break;
				case 47: system("pause"); break;
			}
		}
	}
	return 0;
}
