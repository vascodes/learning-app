#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

#include "filemanager.h"

FILE *file_ptr;

int fm_create_file(char *filename){
	int is_created;
	
	file_ptr = fopen(filename, "w");
	if(file_ptr != NULL)
		is_created = 1;	
	
	fclose(file_ptr);	
	return is_created;	
}

int fm_rename_file(char old_filename[100], char new_filename[100]){
	return rename(old_filename, new_filename);
}

int fm_delete_file(char *filename){
	return remove(filename);
}

int fm_append_line_to_end(char *filename, char str[100]){
	int is_str_appended;	
	file_ptr = fopen(filename, "a");	
			
	// If file could be opened.
	if(file_ptr != NULL){		
		is_str_appended = fputs(str, file_ptr);
	}
	
	fclose(file_ptr);
	return is_str_appended;
}

// TODO: Create config file for max string len etc.
int fm_get_line_by_number(char *filename, int line_num, char *out_str){	
	int curr_line = 1, 
		is_line_found = 0,
		max_len = 200;
	
	file_ptr = fopen(filename, "r");			
	
	// If file could not be opened.
	if(file_ptr == NULL)
		out_str = NULL;
	else{		
		// Read each line from file to str until given line number.
		while(fgets(out_str, max_len, file_ptr) != NULL){									
			if(curr_line == line_num){
				is_line_found = 1;
				break;
			}
										
			curr_line++;			
		}				
	}
	
	if(is_line_found == 0)
		strcpy(out_str, "");
		
	fclose(file_ptr);
	return is_line_found;
}

int fm_is_file_exists(char *filename){
	int is_file_exists;
	
	file_ptr = fopen(filename, "r");
	if(file_ptr != NULL)
		is_file_exists = 1;
	fclose(file_ptr);
	
	return is_file_exists;
}
