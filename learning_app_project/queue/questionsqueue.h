#ifndef queue_H
# define queue_H

#include "../questionmanager/questionmanager.h"

int queue_len;
question *queue;

void queue_enqueue(question q);
void queue_dequeue(question *out_question);
void queue_display();
int is_queue_empty();
void clear_queue();

#endif
