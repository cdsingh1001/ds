#include "queue.h"


queue_node_t* queue_new_node(void* data, int size)
{
    queue_node_t* node = (queue_node_t*) malloc(sizeof(queue_node_t));

    if(!node)
        return NULL;

    node->size = size;
    node->data = (char*)malloc(size);
    memcpy (node->data,data,size);
    node->next = NULL;
    node->prev = NULL;
}

void print_queue (queue_t *queue, void (*printFx)(void*))
{
    queue_node_t *tail = NULL;

    if (!queue) {
        printf("EMPTY QUEUE !!!");
        return;
    }

    tail = queue->tail;

    if (!tail) {
        printf("EMPTY QUEUE !!!");
        return;
    }

    while (tail) {
        printFx(tail->data);
        tail = tail->prev;
    }
}
