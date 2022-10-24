#ifndef QUESTION_MANAGER_H
# define QUESTION_MANAGER_H

# define MAX_STR_LEN 200
# define MAX_QUESTIONS 200
# define DEFAULT_FREQ 2
# define DEFAULT_FILENAME "qalist.txt"
# define QUESTION_FORMAT_STR "%s|%s|%d\n"
# define DEFAULT_DELIMITER "|"

typedef struct qm_question{
    int frequency;
    char question[MAX_STR_LEN];
    char answer[MAX_STR_LEN];
} question;

void *qm_get_question_str(char *question, char *answer, int freq, char out_str[]);

int qm_get_question_from_str(char question_str[], question *out_question);

void get_str_from_question(question q, char *out_str);

void qm_add_question_from_user();

void qm_create_questions();

int qm_is_correct_answer(question q, char *ans_str);

void qm_set_questions_arr();

int qm_get_all_questions(question out_arr[]);

#endif
