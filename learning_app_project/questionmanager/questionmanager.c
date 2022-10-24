#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../filemanager/filemanager.h"
#include "../questionmanager/questionmanager.h"
#include "../queue/questionsqueue.h"
#include "../queue/priorityqueue.h"

int questions_arr_len;
question questions_arr[MAX_QUESTIONS];

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
	
	// Read all lines from a file and store it to an array of questions.
	i = 0;
	line_num = 1;	
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
		priority_queue = (question *) malloc(num_questions * sizeof(question));		
		
		queue = (question *) malloc(num_questions * sizeof(question));
		queue_len = num_questions;
		
		printf("\nAdding initial questions to pq.\n");
		for(i = 0; i < num_questions; i++){					
			// Ignore questions with frequency as 0.
			if(questions[i].frequency > 0)
				pq_enqueue(questions[i]);
		}
				
		//printf("\nis pq empty: %d, is qq empty: %d\n", is_pq_empty(), is_queue_empty());
		char ch;
		do{	
			system("cls");								
			
			// Dequeue all priority queue elements to question queue.
			printf("\nDequeing all questions from pq to qq.\n");
			while(is_pq_empty() == 0){
				question temp;
				pq_dequeue(&temp);				
				queue_enqueue(temp);								
			}
			
//			printf("\nQuestions in qq: \n");
//			queue_display();
//			printf("\nQuestions in pq: \n");
//			pq_display();			
						
			while(is_queue_empty() == 0)
			{				
				int prev_freq;
				int is_correct;			
				char ans[MAX_STR_LEN];
				question new_question;
				
				// Get a new question from questions queue.
				queue_dequeue(&new_question);
							
				// Ignore questions with frequency as 0.
				if(new_question.frequency == 0)
					continue;
															
				// Ask question to user and then read answer.
				printf("\nQuestion: %s?", new_question.question);
				printf("\nEnter answer: ");
				gets(ans);
				
				prev_freq = new_question.frequency;
				is_correct = qm_is_correct_answer(new_question, ans);			
				if(is_correct == 0){
					printf("\nAnswer is correct!\n");
					
					// Reduce frequency of current question if answer is correct.
					// Frequency cannot be less than 0.
					if(new_question.frequency != 0)
						--new_question.frequency;					
																							
					// enqueue to priority queue.
					pq_enqueue(new_question);						
				}
				else{
					printf("\nWrong Answer!!\n");
					
					//TODO: Change max freq according to questions in qalist.txt
					
					// Increment frequency of current question if answer is wrong.
					// Frequency of current question will not be incremnted above MAX_FREQ.
					if(new_question.frequency != MAX_FREQ){
						++new_question.frequency;				
					}
															
					// enqueue to priority queue.
					pq_enqueue(new_question);					
				}																		
			}			
			
			// When all questions have been mastered.
			if(is_pq_empty() == 1 && is_queue_empty() == 1){
				qm_session_done();
				break;
			}
			
			printf("\nDo you want to exit session now?(y/n): ");
			scanf("%c", &ch);
			getchar();
			if(tolower(ch) == 'y'){
				qm_exit();
				break;
			}								
				
		} while(is_pq_empty() == 0 || is_queue_empty() == 0);
		
	}
	// TODO: clear both queues.
	free(queue);
	free(priority_queue);
}

void qm_session_done(){
	printf("\nNo more questions left to learn! All questions mastered!!\n");
}

void qm_exit(){
	printf("\nThank you, your current session is done.");
}
