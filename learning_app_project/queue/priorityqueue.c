#include<stdio.h>
#include<limits.h>

#include "priorityqueue.h"

int size = 0;

void _swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Function to _heapify the tree
void _heapify(int pq[], int size, int i) {
  if (size == 1) {
    return; // Single element in heap.
  } 
  else {
	// Find the largest among root, left child and right child.
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < size && pq[l] > pq[largest])
	  largest = l;
	if (r < size && pq[r] > pq[largest])
	  largest = r;
	
	// _swap and continue _heapifying if root is not largest.
	if (largest != i) {
	  _swap(&pq[i], &pq[largest]);
	  _heapify(pq, size, largest);
	}
  }
}

// To insert an element into the heap.
void _insert_to_heap(int newNum) {
  if (size == 0) {
    pq[0] = newNum;
    size += 1;
  } 
  else {
	int i;
	pq[size] = newNum;
	size += 1;
	
	for (i = size / 2 - 1; i >= 0; i--) {
	  _heapify(pq, size, i);
	}
  }
}

// To delete an element from the heap.
int _delete_from_heap() {
  int i, num = pq[0];
  int deleted = pq[0];
  
  for (i = 0; i < size; i++) {
    if (num == pq[i])
      break;
  }

  _swap(&pq[i], &pq[size - 1]);
  size -= 1;
  for (i = size / 2 - 1; i >= 0; i--) {
    _heapify(pq, size, i);
  }
  
  return deleted;
}

int pq_dequeue(){
	int deleted = pq[0];
	_delete_from_heap();
	
	return deleted;
}

void pq_enqueue(int e){
	_insert_to_heap(e);
}

void display() {
  int i;
  for (i = 0; i < size; ++i)
    printf("%d \n", pq[i]);  	
}
