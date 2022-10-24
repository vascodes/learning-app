#include <stdio.h>
#include <stdlib.h>

#include "questionmanager/questionmanager.h"
#include "uimanager/uimanager.h"

int main() {				
	int i;	
	
	char ch;
	int is_show_menu;
	do{
		system("cls");
		int option;
		ui_print_header("SMART LEARNING APP MAIN MENU");
		printf("\n1. Start a new learning session.");
		printf("\n2. Start previous learning session.");
		printf("\n3. Exit.");
		printf("\n\nEnter an option (1/2/3): ");
		scanf("%d", &option);
		getchar();
		
		switch(option){
			case 1: ui_print_warning("Starting a new session will erase data of previous session.");									
					if(ui_prompt_continue()){
						qm_create_questions();					
						qm_start();
					}										
					break;
	
			case 2: qm_start();
					break;
			
			case 3: ui_print_success_text("Thank you for using this application.");
					exit(0);
			
			default: ui_print_failure_text("Please enter a valid option!");
		}
		is_show_menu = ui_prompt_yes_or_no("Do you want to go back to MAIN MENU");
	}	
	while(is_show_menu);	
	
	return 0;
}
