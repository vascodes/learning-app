#include <stdio.h>
#include <string.h>

#include "../filemanager/filemanager.h"
#include "../questionmanager/questionmanager.h"

#define DEFAULT_FREQ 2
#define DEFAULT_FILENAME "qalist.txt"
#define DEFAULT_DELIMITER "|"

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

int qm_get_question_from_str(char question_str[200], question *out_question){
	int i, index = 0, question_str_len;
	char *str;		
	char str_split_arr[5][strlen(question_str)];
	
	/*
		Split contents of a string with delimiter to an array.
		
		example: 	If question_str = "Hello|World|10", then
					str_split_arr will be ["Hello", "World", "10"]
	*/	
	str = strtok(question_str, DEFAULT_DELIMITER);
	while(str != NULL){		
		strcpy(str_split_arr[index], str);
		index++;		
		str = strtok(NULL, DEFAULT_DELIMITER);
	}	
	
	// Map question, answer and frequency to a question type.
	strcpy(out_question->question, str_split_arr[0]);
	strcpy(out_question->answer, str_split_arr[1]);
	out_question->frequency =  atoi(str_split_arr[2]);
	
	return;	
}




