#ifndef PRIORITY_QUEUE_H
# define PRIORITY_QUEUE_H

#include "../questionmanager/questionmanager.h"

question *priority_queue;

void pq_dequeue(question *out_question);
void pq_enqueue(question q);
void pq_display();
int pq_is_empty();
void pq_clear();

#endif
