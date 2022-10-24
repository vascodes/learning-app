#include <stdio.h>
#include <stdlib.h>

#include "questionmanager/questionmanager.h"

int main() {				
	int i;	
	
	char ch;
	do{
		system("cls");
		int option;
		printf("\n\tSMART LEARNING APP MAIN MENU\n");
		printf("\n1. Start a new learning session.");
		printf("\n2. Resume previous learning session.");
		printf("\n3. Exit.");
		printf("\nEnter an option (1/2/3): ");
		scanf("%d", &option);
		getchar();
		
		switch(option){
			case 1: qm_create_questions();
					qm_start();
					break;
	
			case 2: qm_start();
					break;
			
			case 3: exit(0);
			
			default: printf("\nPlease enter a valid option!\n");
		}
		printf("\nDo you want to go back to MAIN MENU? (y/n): ");
		scanf("%c", &ch);
		getchar();
	}
	while(tolower(ch) == 'y');
		
	return 0;
}
