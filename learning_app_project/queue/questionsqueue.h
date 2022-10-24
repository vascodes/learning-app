#ifndef queue_H
# define queue_H

#include "../questionmanager/questionmanager.h"

int queue_len;
question *queue;

void queue_enqueue(question q);
void queue_dequeue(question *out_question);
void queue_sort(question *pq, int n);
void queue_display();
int is_queue_empty();

#endif
