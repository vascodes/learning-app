#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../filemanager/filemanager.h"
#include "../questionmanager/questionmanager.h"

int questions_arr_len;
question questions_arr[MAX_QUESTIONS];

int priority_queue_len;
question *qm_priority_queue;
int questions_queue_len;
question *questions_queue;

int pq_front = -1, pq_rear = -1;
void enqueue(question q){
	if(pq_rear == questions_arr_len)
		return;
	pq_front = 0;
	pq_rear++;
	qm_priority_queue[pq_rear] = q;
}

void dequeue(question *out_question){	
	if(pq_front == -1)
		return;
	else{
		question temp = qm_priority_queue[pq_front];		
		strcpy(out_question->question, temp.question);
		strcpy(out_question->answer, temp.answer);
		out_question->frequency = temp.frequency;
		pq_front++;
	}
}

void disp(){
	if(pq_front == -1)
		return;

	int i;
	for(i = pq_front; i <= pq_rear; i++){		
		printf("\n%s|%s|%d", 
				qm_priority_queue[i].question, 
				qm_priority_queue[i].answer, 
				qm_priority_queue[i].frequency);			
	}
}

void *qm_get_question_str(char *question, char *answer, int freq, char out_str[]){
	snprintf(out_str, MAX_STR_LEN, QUESTION_FORMAT_STR, question, answer, freq);
}

void qm_add_question_from_user(){
	int fq = DEFAULT_FREQ;
	char qn[MAX_STR_LEN], ans[MAX_STR_LEN];
	char question_str[MAX_STR_LEN];
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
	fm_append_line_to_end(DEFAULT_FILENAME, question_str);
}

void qm_create_questions(){	
	int num, i;
	
	fm_create_file(DEFAULT_FILENAME);
	printf("\nPlease enter the number of questions you want to enter: ");
	scanf("%d", &num);
	getchar(); // To discard the enter key press.
	for(i = 0; i < num; i++){
		qm_add_question_from_user();
	}
}

int qm_get_question_from_str(char question_str[MAX_STR_LEN], question *out_question){
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

void get_str_from_question(question q, char *out_str){
	snprintf(out_str, MAX_STR_LEN, QUESTION_FORMAT_STR, q.question, q.answer, q.frequency);
}

int qm_is_correct_answer(question q, char *ans_str){
	return strcmpi(q.answer, ans_str);
}

void qm_set_questions_arr(){
	int line_num, i;
	int is_line_found;
	char line[MAX_STR_LEN];
	question q;
	
	i = 0;
	line_num = 1;	
	// Read all lines from a file and store it to an array of questions.
	is_line_found = fm_get_line_by_number(DEFAULT_FILENAME, line_num, line);
	while(is_line_found){									
		qm_get_question_from_str(line, &q);
		questions_arr[i++] = q;
		line_num++;		
		is_line_found = fm_get_line_by_number(DEFAULT_FILENAME, line_num, line);		
	}
	questions_arr_len = line_num-1;		
}

int qm_get_all_questions(question out_arr[]){
	int i;
	for(i = 0; i < questions_arr_len; i++){
		out_arr[i] = questions_arr[i];
	}
	
	return i;
}

// TODO: Implement priority queue using max heap.
void sort_pq(question *pq, int n){
	int i, j;
	question temp;
	for(i = 0; i < n; i++){
		for(j = i+1; j < n; j++){
			if(pq[i].frequency < pq[j].frequency){
				temp = pq[i];
				pq[i] = pq[j];
				pq[j] = temp;
			}
		}
	}
}

void qm_start(){
	int num_questions, i;
	question q;
	question questions[MAX_QUESTIONS];
	
	qm_set_questions_arr();
	num_questions = qm_get_all_questions(questions);
	
	if(num_questions == 0){
		printf("\nNo questions left to learn. Please start a new session.\n");
	}
	else{
		qm_priority_queue = (question *) malloc(num_questions * sizeof(question));
		for(i = 0; i < questions_arr_len; i++){					
			enqueue(questions[i]);
		}
		printf("\nBefore sort: ");
		disp();
		sort_pq(qm_priority_queue, num_questions);		
		printf("\n\nAfter sort: ");				
		disp();				
		
		
//		priority_queue_len = num_questions;
//		questions_queue_len = num_questions;
//		while(priority_queue_len > 0 && questions_queue_len > 0){
//			
//		}
		
		//free(qm_priority_queue);
	}
}

