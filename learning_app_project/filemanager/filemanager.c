#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include "filemanager.h"

FILE *file_ptr;

/*
	Creates a file with given file name.
	Returns 1 if file is created else 0.
*/
int create_file(char *filename){
	int is_created;
	
	file_ptr = fopen(filename, "w");
	if(file_ptr != NULL)
		is_created = 1;	
	
	fclose(file_ptr);	
	return is_created;	
}

/*
	Deletes a file with given file name.
	Returns 1 if file is deleted else 0.
*/
int delete_file(char *filename){
	int is_deleted;
	is_deleted = remove(filename);	
	
	return is_deleted;
}

/*
	To append a line to end of specified file.
	filename - Name of file
	str - String that is to be appended. 		
	
	Returns 1 if line is appended else 0.
*/
int append_line_to_end(char *filename, char str[100]){
	int is_str_appended;	
	file_ptr = fopen(filename, "a");	
			
	if(file_ptr == NULL){
		printf("\nError! Could not open file.");
		return 0;
	}

	is_str_appended = fputs(str, file_ptr);	
	
	fclose(file_ptr);
	return is_str_appended;
}

/*
	To get a specified line using line number from a file.	
	file_name: Name of file.
	line_num: 	Line number of line to be read from file.
	
	Returns line read from file.					
*/
char *get_line_by_number(char *filename, int line_num){	
	int is_file_exists;
	int curr_line = 1, max_len = 150;
	char *str = (char *) malloc(max_len * sizeof(char));

	file_ptr = fopen(filename, "r");			
	if(file_ptr == NULL)
		printf("\nError. Could not open file %s\n.", filename);
	else{
		while(fgets(str, max_len, file_ptr)){			
			if(curr_line == line_num)
				break;
							
			curr_line++;			
		}
		printf("\nstring is: %s\n", str);
	}
	
	fclose(file_ptr);
	return str;
}
