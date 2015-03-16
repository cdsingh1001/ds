
#ifndef _QUEUE_H
#define _QUEUE_H
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "string.h"


typedef struct queue_node_s {
    int size;
    void* data;
    struct queue_node_s *next;
    struct queue_node_s *prev;
} queue_node_t;

typedef struct queue_s {
    queue_node_t *head, *tail;
} queue_t;

int create_queue (queue_t **queue);
int delete_queue(queue_t *queue, int size);
int enqueue (queue_t *queue, void* item, int size_item);
void* dequeue (queue_t *queue);
#endif
