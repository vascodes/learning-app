#include<stdio.h>
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

int delete_file(char *filename){
	int is_deleted;
	is_deleted = remove(filename);	
	
	return is_deleted;
}

int append_line_to_end(char *filename, char *str){
	int is_file_exists;
	file_ptr = fopen(filename, "a");
	
	if(file_ptr != NULL){
		is_file_exists = 1;
		fprintf(file_ptr, str);
	}

	fclose(file_ptr);
	return is_file_exists;
}