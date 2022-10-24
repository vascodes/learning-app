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
	insert(array, 3);
	insert(array, 4);
	insert(array, 9);
	insert(array, 5);
	insert(array, 2);
	
	printf("Max-Heap array: ");
	display(array, size);
	
	deleteRoot(array, 4);
	
	printf("After deleting an element: ");
	
	display(array, size);
	
	return 0;
}
