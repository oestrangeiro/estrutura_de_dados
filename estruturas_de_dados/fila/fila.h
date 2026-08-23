#ifndef FILA_H
#define FILA_H

#include "../../includes/node.h"

typedef struct Queue {
    Node *front;
} Queue;

Queue *createQueue();
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
int isEmpty(Queue *queue);
void printAllNodes(Queue *queue);

#endif
