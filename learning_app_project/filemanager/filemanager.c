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
