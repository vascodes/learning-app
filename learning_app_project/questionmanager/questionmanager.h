#ifndef QUESTION_MANAGER_H
# define FILE_MANAGER_H

void *qm_get_question_str(char *question, char *answer, int freq, char out_str[]);
void qm_add_question_from_user();
void qm_create_questions(int frequency);

#endif
