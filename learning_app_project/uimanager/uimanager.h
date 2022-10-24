#ifndef UI_MANAGER_H
# define UI_MANAGER_H

void ui_print_hyphens();

void ui_print_equals();

void ui_print_asterisks();

void ui_print_header(char heading_text[]);

void ui_print_warning(char warning_text[]);

void ui_print_success_text(char text[]);

void ui_failure_text(char text[]);

void ui_print_press_key(char text[]);

int ui_prompt_continue();

int ui_prompt_yes_or_no(char text[]);

void ui_print_success_text(char text[]);

void ui_print_failure_text(char text[]);

#endif
