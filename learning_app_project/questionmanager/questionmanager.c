#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../filemanager/filemanager.h"
#include "../questionmanager/questionmanager.h"
#include "../queue/questionsqueue.h"
#include "../queue/priorityqueue.h"
#include "../uimanager/uimanager.h"

int questions_arr_len;
question questions_arr[MAX_QUESTIONS];

int get_max_int(int a, int b){
	return a > b ? a : b;
}

void *qm_get_question_str(char *question, char *answer, int freq, char out_str[]){
	snprintf(out_str, MAX_STR_LEN, QUESTION_FORMAT_STR, question, answer, freq);
}

void qm_add_question_from_user(){
	int fq = DEFAULT_FREQ;
	char qn[MAX_STR_LEN], ans[MAX_STR_LEN];
	char question_str[MAX_STR_LEN];
	char ch;
	
	system("cls");
	ui_print_equals();
	printf("\nEnter a question: ");
	gets(qn);	
	
	ui_print_equals();
	printf("\nEnter answer for above question: ");
	gets(ans);	
	
	int is_yes = ui_prompt_yes_or_no("Do you want to enter frequency for this question");	
	if(is_yes){		
		printf("\nEnter frequency of this question: ");
		scanf("%d", &fq);
		getchar(); // To discard the enter key press.
		ui_print_equals();
	}
	else{
		fq = DEFAULT_FREQ;		
		printf("\nFrequency of this question set to %d by default.", DEFAULT_FREQ);
		ui_print_asterisks();
	}
	
	qm_get_question_str(qn, ans, fq, question_str);
	fm_append_line_to_end(DEFAULT_FILENAME, question_str);
}

void qm_create_questions(){	
	int num, i;
	
	fm_create_file(DEFAULT_FILENAME);
	system("cls");	
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

int get_questions_arr_len(){
	return questions_arr_len;
}

void qm_start(){
	char ch;
	
	int is_file_exists = fm_is_file_exists(DEFAULT_FILENAME);
	if(!is_file_exists){
		ui_print_warning("Could not find previous questions. Please start a new session.");
		return;
	}
	
	int num_questions, i;
	int is_session_done, is_exit;
	int max_freq = 0;
	
	question q;
	question questions[MAX_QUESTIONS];
	
	qm_set_questions_arr();
	num_questions = qm_get_all_questions(questions);
	
	// No questions in list.
	if(num_questions == 0){
		qm_session_done();
	}
	else{
		priority_queue = (question *) malloc(num_questions * sizeof(question));		
		
		queue = (question *) malloc(num_questions * sizeof(question));
		queue_len = num_questions;
				
		for(i = 0; i < num_questions; i++){					
			// Ignore questions with frequency as 0.
			if(questions[i].frequency > 0){
				max_freq = get_max_int(max_freq, questions[i].frequency);
				pq_enqueue(questions[i]);
			}
		}
						
		do{	
			system("cls");							
			
			// Dequeue all priority queue elements to question queue.			
			while(pq_is_empty() == 0){
				question temp;
				pq_dequeue(&temp);				
				queue_enqueue(temp);								
			}
									
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
				ui_print_equals();
				printf("\tQuestion: %s?", new_question.question);
				ui_print_equals();
				printf("\n\tEnter answer: ");				
				gets(ans);
				
				prev_freq = new_question.frequency;
				is_correct = qm_is_correct_answer(new_question, ans);			
				if(is_correct == 0){
					ui_print_equals();
					printf("\tYOUR ANSWER IS CORRECT!!\n");										
					
					// Reduce frequency of current question if answer is correct.
					// Frequency cannot be less than 0.
					if(new_question.frequency != 0)
						--new_question.frequency;		
					
					printf("\n\tTurns left to master this question: %d", new_question.frequency);
					ui_print_equals();
				}
				else{
					ui_print_asterisks();
					printf("\n\tSORRY, YOUR ANSWER IS WRONG.\n");
					printf("\n\tThe correct answer is: %s\n", new_question.answer);
					ui_print_asterisks();										
					
					/*
						Increment frequency of current question if answer is wrong.						
						Frequency of current question will not be incremented above,
							maximum frequency that is in question list.
					*/
					if(new_question.frequency != max_freq)
						++new_question.frequency;																											
				}
				// enqueue current question to priority queue.
				pq_enqueue(new_question);
				
				//TODO: Validate key press.
				ui_print_press_key("\tPress ENTER key to show next question.");
				system("cls");																	
			}			
			
			/* 
				Session is complete when all questions have been mastered.
				ie: Both queues become empty.
			*/
			if(pq_is_empty() == 1 && is_queue_empty() == 1)
				is_session_done = 1;											
			
			if(!is_session_done){
				is_exit = ui_prompt_yes_or_no("Do you want to exit session now");								
			}				
		} while(pq_is_empty() == 0 || is_queue_empty() == 0);		
	
		if(is_session_done)
			qm_session_done();
	
		if(is_exit)
			qm_exit();	
	}			
}

void qm_session_done(){	
	ui_print_success_text("No more questions left to learn! All questions mastered!!");	
	qm_exit();
}

void qm_exit(){
	ui_print_success_text("Thank you, your current session is complete.");	
	destroy_queues();
}

void destroy_queues(){
	clear_queue();
	pq_clear();
	free(queue);
	free(priority_queue);
}
