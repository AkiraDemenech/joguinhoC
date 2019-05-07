#include<stdio.h>
#include<conio.h>

void startIcon () {
	
	int c = 0;
	
	while(kbhit()==0) {
		
		system("cls");
		
		switch (c%9) {
			
			case 0:
				printf("\n   O  ");
				printf("\n      ");
				printf("\n      ");
				break;
				
			case 1:
				printf("\n    O ");
				printf("\n      ");
				printf("\n      ");
				break;
					
			case 2:
				printf("\n     O");
				printf("\n      ");
				printf("\n      ");
				break;
					
			case 3:
				printf("\n      ");
				printf("\n     O");
				printf("\n      ");
				break;
						
			case 4:
				printf("\n      ");
				printf("\n      ");
				printf("\n     O");
				break;
						
			case 5:
				printf("\n      ");
				printf("\n      ");
				printf("\n    O ");
				break;
						
			case 6:
				printf("\n      ");
				printf("\n      ");
				printf("\n   O  ");
				break;
			
						
			case 7:
				printf("\n      ");
				printf("\n   O  ");
				printf("\n      ");
				break;
				
			case 8:
				printf("\n      ");
				printf("\n      ");
				printf("\n      ");
				break;
		}
		
		switch (c%16) {
			case 0:
				system("color F");
				break;
				
			case 1:
				system("color 10");
				break;
					
			case 2:
				system("color 20");
				break;
						
			case 3:
				system("color 30");
				break;
						
			case 4:
				system("color 40");
				break;
						
			case 5:
				system("color 50");
				break;
						
			case 6:
				system("color 60");
				break;
						
			case 7:
				system("color 70");
				break;
						
			case 8:
				system("color 80");
				break;
						
			case 9:
				system("color 90");
				break;
						
			case 10:
				system("color A0");
				break;
						
			case 11:
				system("color B0");
				break;
						
			case 12:
				system("color C0");
				break;
						
			case 13:
				system("color D0");
				break;
						
			case 14:
				system("color E0");
				break;
						
			case 15:
				system("color F0");
				break;
		}
		
		//Sleep(42);
		
		c++;
		
	}
	
}

int main () {
	system("color F");
	startIcon();
	system("menuLauncher.exe");
	return 0;
}
