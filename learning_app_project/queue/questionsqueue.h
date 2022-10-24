#ifndef QUESTIONS_QUEUE_H
# define QUESTIONS_QUEUE_H

#include "../questionmanager/questionmanager.h"

int questions_queue_len;
question *questions_queue;

void questions_queue_enqueue(question q);
void questions_queue_dequeue(question *out_question);
void questions_queue_sort(question *pq, int n);
void questions_queue_display();

#endif
