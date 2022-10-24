#include <stdio.h>
#include <limits.h>
#include <string.h>

#include "priorityqueue.h"

int size = 0;

void _swap(question *a, question *b) {
  question temp;
  temp = *b;
  *b = *a;
  *a = temp;
}

// Function to _heapify the tree
void _heapify(question pq[], int size, int i) {
  if (size == 1) {
    return; // Single element in heap.
  } 
  else {
	// Find the largest among root, left child and right child.
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < size && pq[l].frequency > pq[largest].frequency)
	  largest = l;
	if (r < size && pq[r].frequency > pq[largest].frequency)
	  largest = r;
	
	// swap and continue heapifying if root is not largest.
	if (largest != i) {
	  _swap(&pq[i], &pq[largest]);
	  _heapify(pq, size, largest);
	}
  }
}

// To insert an element into the heap.
void _insert_to_heap(question q) {
  if (size == 0) {
    pq[0] = q;
    size++;
  } 
  else {
	int i;
	pq[size] = q;
	size++;
	
	for (i = size / 2 - 1; i >= 0; i--) {
	  _heapify(pq, size, i);
	}
  }
}

// To delete an element from the heap.
question _delete_from_heap(question q) {
  int i;
  question deleted = pq[0];
  
  for (i = 0; i < size; i++) {
    if (strcmpi(q.question, pq[i].question) == 0)
      break;
  }

  _swap(&pq[i], &pq[size - 1]);
  size--;
  
  for (i = size / 2 - 1; i >= 0; i--) {
    _heapify(pq, size, i);
  }
  
  return deleted;
}

void pq_dequeue(question *out_question){
	question deleted = pq[0];		
	
	strcpy(out_question->question, deleted.question);
	strcpy(out_question->answer, deleted.answer);
	out_question->frequency = deleted.frequency;
		
	_delete_from_heap(deleted);		
}

void pq_enqueue(question q){
	_insert_to_heap(q);
}

void display() {
  int i;
  for (i = 0; i < size; ++i)
    printf("%s|%s|%d \n", pq[i].question, pq[i].answer, pq[i].frequency);  	
}
