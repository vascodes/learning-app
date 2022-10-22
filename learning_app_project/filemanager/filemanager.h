#ifndef FILE_MANAGER_H
# define FILE_MANAGER_H

int create_file(char *);
int delete_file(char *);
int append_line_to_end(char *, char str[]);
char *get_line_by_number(char *, int);

#endif
