#include "fila.h"
#include "../../includes/node.h"
#include <stdio.h>
#include <stdlib.h>

Queue* createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = NULL;
    return queue;
}

void enqueue(Queue *queue, int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        return;
    }

    Node *currentNode = queue->front;

    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Fila vazia.");
        return -1;
    }

    Node *temp = queue->front;
    int v = temp->value;

    queue->front = queue->front->next;

    free(temp);
    return v;
}

int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

void printAllNodes(Queue *queue) {
    Node *currentNode = queue->front;

    if (isEmpty(queue)) {
        printf("Fila vazia");
    }

    while (currentNode) {
        printf("%d -> ", currentNode->value);
        currentNode = currentNode->next;
    }

    printf("\n");
}

int main() {
    Queue *q = createQueue();

    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);

    printAllNodes(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    printAllNodes(q);
    return 0;
}
