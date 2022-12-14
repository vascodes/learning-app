#ifndef FILE_MANAGER_H
# define FILE_MANAGER_H

/*
	Creates a file with given file name.
	Returns 0 if file is created successfully.
*/
int fm_create_file(char *filename);

/*
	Renames a file with given new_filename.
	Returns 0 if file is renamed successfully.
*/
int fm_rename_file(char old_filename[], char new_filename[]);

/*
	Deletes a file with given filename.
	Returns 0 if file is deleted successfully.
*/
int fm_delete_file(char *filename);

/*
	To append a line to end of a file.
	filename - Name of file
	str[] - String that is to be appended. 		
	
	Returns 0 if line is appended successfully.
*/
int fm_append_line_to_end(char *filename, char str[]);

/*
	To get a specified line using line number from a file.
		
	filename: Name of file.
	line_num: Line number of line to be read from file.
	out_str: string to which line from file is stored.
	
	Returns 1 if line is found in file else 0.							
*/
int fm_get_line_by_number(char *filename, int line_num, char *out_str);


/*
	Checks whether file with given filename exists.
	Returns 1 if file exists.
*/
int fm_is_file_exists(char *filename);

#endif
