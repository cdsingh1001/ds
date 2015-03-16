#include "queue.h"
#include "queue_util.h"

int create_queue (queue_t **queue)
{
    queue_t *qt = NULL;

    if (*queue) {
        printf("NON EMPTY QUEUE\n");
        return 0;
    }

    qt = (queue_t*) malloc(sizeof(queue_t));
    if (!qt)
        *queue = NULL;
    else {
        qt->head = qt->tail = NULL;
        *queue = qt;
    }

    return 0;
}

int delete_queue(queue_t *queue, int size)
{
    queue_node_t *tail = NULL;
    char *buf = (char*) malloc(size);

    if (!queue) {
        printf("EMPTY QUEUE !!!");
        return 0;
    }

    tail = queue->tail;

    while (tail) {
        buf = (void*)dequeue(queue);
        free(buf);
        buf = NULL;
        tail = queue->tail;
    }

    queue->head = NULL;
    queue->tail = NULL;

    free (queue);
}

int enqueue (queue_t *queue, void* item, int size_item)
{
    queue_node_t *head = NULL;
    queue_node_t *tail = NULL;
    queue_node_t *node = NULL;

    if (!queue) {
        return -1;
    }

    head = queue->head;
    tail = queue->tail;

    node = queue_new_node(item, size_item);
    if (!node) {
        return -1;
    }

    if (!head) {
        assert(!tail);
        head = tail = node;
    }
    else {
        assert(tail);
        node->next = head;
        head->prev = node;
        head = node;
    }

    queue->head = head;
    queue->tail = tail;

    return 0;
}

void* dequeue (queue_t *queue)
{
    queue_node_t *tail = NULL;
    queue_node_t *node = NULL;
    void *data;

    if (!queue) {
        return NULL;
    }

    tail = queue->tail;

    if (!tail)
        return NULL;

    node = tail;
    tail = node->prev;

    if (!tail)
        queue->head = NULL;
    else
        tail->next = NULL;

    queue->tail = tail;

    data = (char*)malloc(node->size);
    memcpy(data, node->data, node->size);
    return (void*)data;
}

