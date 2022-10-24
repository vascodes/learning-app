#ifndef PRIORITY_QUEUE_H
# define PRIORITY_QUEUE_H

#include "../questionmanager/questionmanager.h"

question *priority_queue;

void pq_dequeue(question *out_question);
void pq_enqueue(question q);
int is_pq_empty();

#endif
