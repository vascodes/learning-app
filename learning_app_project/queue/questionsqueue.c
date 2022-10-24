#include <stdio.h>
#include <string.h>

#include "questionsqueue.h"

int queue_front = -1, 
	queue_rear = -1;
	
void queue_enqueue(question q){
	if(queue_rear + 1 == queue_len){
		//printf("\nQueue is full!\n");
		return;
	}
	
	if(queue_front == -1)	
		queue_front = 0;
	
	queue_rear++;
	queue[queue_rear] = q;	
}

void queue_dequeue(question *out_question){	
	// empty queue
	if(is_queue_empty())
		return;
						
	question deleted = queue[queue_front];		
	strcpy(out_question->question, deleted.question);
	strcpy(out_question->answer, deleted.answer);
	out_question->frequency = deleted.frequency;
		
	queue_front++;		
	//queue_len--;
	
	if(queue_front > queue_rear){
		queue_front = queue_rear = -1;
	}
}

void queue_sort(question *pq, int n){
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

void queue_display(){
	if(is_queue_empty())
		return;		

	int i;
	for(i = queue_front; i <= queue_rear; i++){		
		printf("\n%s|%s|%d", 
				queue[i].question, 
				queue[i].answer, 
				queue[i].frequency);			
	}
}

int is_queue_empty(){
	return (queue_len == 0 || queue_rear == -1);
}
