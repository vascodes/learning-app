#include <stdio.h>
#include <stdlib.h>

#include "questionmanager/questionmanager.h"
#include "queue/priorityqueue.h"

int main() {				
	int i;	
	//question questions[100];
	//qm_create_questions();
	//qm_start();
			
	pq = (int *) malloc(10 * sizeof(int));	
	
	insert_to_heap(3);
    insert_to_heap(4);
    insert_to_heap(9);
    insert_to_heap(5);
    insert_to_heap(2);
    insert_to_heap(10);
	
	printf("Max-Heap array: ");
	display();
	
	delete_from_heap(4);
	
	printf("After deleting an element: ");	
	display();
	
	return 0;
}
