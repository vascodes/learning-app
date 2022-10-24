#include <stdio.h>

#include "uimanager.h"

void ui_print_hyphens(){
	printf("\n------------------------------------------------------------------------\n");
}

void ui_print_equals(){
	printf("\n========================================================================\n");
}

void ui_print_asterisks(){
	printf("\n************************************************************************\n");
}

void ui_print_header(char heading_text[]){
	ui_print_hyphens();
	printf("\t\t%s", heading_text);
	ui_print_hyphens();
}

void ui_print_warning(char warning_text[]){
	ui_print_asterisks();
	printf("\t\t\tWARNING!!");
	ui_print_asterisks();
	printf("\n%s\n", warning_text);	
	ui_print_hyphens();
}

int ui_prompt_continue(){
	char ch;
	int is_continue;
	printf("\nDo you want to continue? (y/n): ");	
	scanf("%c", &ch);
	getchar(); // to discard Enter key press.
	if(tolower(ch) == 'y')
		is_continue = 1;

	return is_continue;
}

int ui_prompt_yes_or_no(char text[]){
	char ch;
	int is_yes;
	printf("\n%s? (y/n): ", text);	
	scanf("%c", &ch);
	getchar();
	if(tolower(ch) == 'y')
		is_yes = 1;

	return is_yes;
}

void ui_print_success_text(char text[]){
	ui_print_equals();
	printf("\n%s\n", text);
	ui_print_equals();
}

void ui_print_failure_text(char text[]){
	ui_print_asterisks();
	printf("\n%s\n", text);
	ui_print_asterisks();
}

void ui_print_press_key(char text[]){
	ui_print_equals();
	printf("\n%s\n", text);
	ui_print_equals();	
	getchar();
}
