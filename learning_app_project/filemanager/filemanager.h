#ifndef FILE_MANAGER_H
# define FILE_MANAGER_H

/*
	Creates a file with given file name.
	Returns 1 if file is created else 0.
*/
int create_file(char *filename);

/*
	Renames a file with given new_filename.
	Returns 0 if file rename is successful.
*/
int rename_file(char old_filename[], char new_filename[]);

/*
	Deletes a file with given filename.
	Returns 1 if file is deleted else 0.
*/
int delete_file(char *filename);

/*
	To append a line to end of a file.
	filename - Name of file
	str[] - String that is to be appended. 		
	
	Returns 1 if line is appended else 0.
*/
int append_line_to_end(char *filename, char str[]);

/*
	To get a specified line using line number from a file.	
	file_name: Name of file.
	line_num: Line number of line to be read from file.
	
	Returns line read from file.					
*/
char *get_line_by_number(char *filename, int line_num);

#endif
