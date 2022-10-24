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
	pq = (int *) malloc(pq_size * sizeof(int));	
	
	pq_enqueue(3);
    pq_enqueue(4);
    pq_enqueue(9);
    pq_enqueue(5);
    pq_enqueue(2);
    pq_enqueue(10);
	
	printf("\nDeleted: %d", pq_dequeue());
	printf("\nDeleted: %d", pq_dequeue());
	printf("\nDeleted: %d", pq_dequeue());
		
	return 0;
}
