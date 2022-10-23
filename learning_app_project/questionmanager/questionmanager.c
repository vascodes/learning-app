#include <stdio.h>
#include <string.h>

#include "../filemanager/filemanager.h"
#include "../questionmanager/questionmanager.h"

#define DEFAULT_FREQ 2
#define DEFAULT_FILENAME "qalist.txt"

typedef struct qm_question{
    int frequency;
    char question[200];
    char answer[200];
} question;

char QUESTION_FORMAT_STR[20] = "%s|%s|%d\n";

void *qm_get_question_str(char *question, char *answer, int freq, char out_str[]){
	int max_len = 200;
	snprintf(out_str, max_len, QUESTION_FORMAT_STR, question, answer, freq);
}

void qm_add_question_from_user(){
	int fq = DEFAULT_FREQ;
	char qn[100], ans[100];
	char question_str[200];
	char ch;
	
	printf("\nEnter a question: ");
	gets(qn);
	printf("\nEnter answer for above question: ");
	gets(ans);
	printf("\nDo you want to enter frequency for this question (y/n)?: ");
	scanf("%c", &ch);
	getchar(); // To discard the enter key press.
	if(tolower(ch) == 'y'){
		printf("\nEnter frequency of this question: ");
		scanf("%d", &fq);
		getchar(); // To discard the enter key press.
	}
	else{
		fq = DEFAULT_FREQ;
		printf("\nFrequency of this question set to %d by default.", DEFAULT_FREQ);
	}
	
	qm_get_question_str(qn, ans, fq, question_str);
	append_line_to_end(DEFAULT_FILENAME, question_str);
}

void qm_create_questions(int frequency){	
	int num, i;
	
	create_file(DEFAULT_FILENAME);
	printf("\nPlease enter the number of questions you want to enter: ");
	scanf("%d", &num);
	getchar(); // To discard the enter key press.
	for(i = 0; i < num; i++){
		qm_add_question_from_user();
	}
}
