#include <stdio.h>
#include <conio.h>

int main () {
	system("color F0");
	printf("\n\a    HELLO WORLD! ");
	Sleep(82 + (time(NULL)%256));
	if(kbhit())
		if(getch()==27)
			return 0;
	system("infinity.exe");
}
