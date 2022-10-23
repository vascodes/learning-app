#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include "filemanager.h"

FILE *file_ptr;

int create_file(char *filename){
	int is_created;
	
	file_ptr = fopen(filename, "w");
	if(file_ptr != NULL)
		is_created = 1;	
	
	fclose(file_ptr);	
	return is_created;	
}

int rename_file(char old_filename[100], char new_filename[100]){
	return rename(old_filename, new_filename);
}

int delete_file(char *filename){
	return remove(filename);
}

int append_line_to_end(char *filename, char str[100]){
	int is_str_appended;	
	file_ptr = fopen(filename, "a");	
			
	// If file could be opened.
	if(file_ptr != NULL){		
		is_str_appended = fputs(str, file_ptr);
	}
	
	fclose(file_ptr);
	return is_str_appended;
}

// TODO: Add out str as parameter instead of returning str.
void get_line_by_number(char *filename, int line_num, char *out_str){	
	int curr_line = 1, 
		max_len = strlen(out_str);
	
	file_ptr = fopen(filename, "r");			
	
	// If file could not be opened.
	if(file_ptr == NULL)
		out_str = NULL;
	else{
		// Read each line from file to str until given line number.
		while(fgets(out_str, max_len, file_ptr)){			
			if(curr_line == line_num)
				break;
							
			curr_line++;			
		}		
	}
	
	fclose(file_ptr);
}
