#include <stdio.h>
#include <string.h>

#include "questionsqueue.h"

int questions_queue_len;
question *questions_queue;

int questions_queue_front = -1, 
	questions_queue_rear = -1;
	
void questions_queue_enqueue(question q){
	if(questions_queue_rear == questions_queue_len)
		return;
		
	questions_queue_front = 0;
	questions_queue_rear++;
	questions_queue[questions_queue_rear] = q;
}

void questions_queue_dequeue(question *out_question){	
	if(questions_queue_front == -1)
		return;
	else{
		question temp = questions_queue[questions_queue_front];		
		strcpy(out_question->question, temp.question);
		strcpy(out_question->answer, temp.answer);
		out_question->frequency = temp.frequency;
		questions_queue_front++;
	}
}

void questions_queue_sort(question *pq, int n){
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

void questions_queue_display(){
	if(questions_queue_front == -1)
		return;

	int i;
	for(i = questions_queue_front; i <= questions_queue_rear; i++){		
		printf("\n%s|%s|%d", 
				questions_queue[i].question, 
				questions_queue[i].answer, 
				questions_queue[i].frequency);			
	}
}
