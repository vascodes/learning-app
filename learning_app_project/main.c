#include <stdio.h>
#include <stdlib.h>

#include "questionmanager/questionmanager.h"
#include "queue/priorityqueue.h"

int main() {				
	int i;	
	//question questions[100];
	//qm_create_questions();
	//qm_start();
			
	int pq_size = 10;
	pq = (question *) malloc(pq_size * sizeof(question));	
		
	question q1;
	strcpy(q1.question, "q1");
	strcpy(q1.answer, "a1");
	q1.frequency = 2;
	
	question q2;
	strcpy(q2.question, "q2");
	strcpy(q2.answer, "a2");
	q2.frequency = 5;
	
	question q3;
	strcpy(q3.question, "q3");
	strcpy(q3.answer, "a3");
	q3.frequency = 3;
	
	pq_enqueue(q1);
    pq_enqueue(q2);    
    pq_enqueue(q3);    
		
	display();		

	question t;
	pq_dequeue(&t);
	printf("\nDeleted: %s|%s|%d", t.question, t.answer, t.frequency);
	pq_dequeue(&t);
	printf("\nDeleted: %s|%s|%d", t.question, t.answer, t.frequency);
	pq_dequeue(&t);
	printf("\nDeleted: %s|%s|%d", t.question, t.answer, t.frequency);
//	
//	pq_dequeue(&t);
//	printf("\nDeleted: %s|%s|%s", t.question, t.answer, t.frequency);

//	display();
		
	return 0;
}
