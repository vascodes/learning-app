#include <stdio.h>
#include <stdlib.h>

#include "questionmanager/questionmanager.h"
#include "queue/priorityqueue.h"

int main() {				
	int i;	
	//question questions[100];
	//qm_create_questions();
	//qm_start();
			
	int array[10];
	insert_to_heap(array, 3);
	insert_to_heap(array, 4);
	insert_to_heap(array, 9);
	insert_to_heap(array, 5);
	insert_to_heap(array, 2);
	
	printf("Max-Heap array: ");
	display(array, size);
	
	delete_from_heap(array, 4);
	
	printf("After deleting an element: ");	
	display(array, size);
	
	return 0;
}
