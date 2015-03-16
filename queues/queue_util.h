#ifndef _QUEUE_UTIL_H
#define _QUEUE_UTIL_H

#include "queue.h"

queue_node_t* queue_new_node(void* data, int size);
void print_queue (queue_t *queue, void (*printFx)(void*));

#endif
