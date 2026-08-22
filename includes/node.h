#ifndef NODE_H
#define NODE_H

typedef struct Node {
	struct Node *next;
	int value;
} Node;


Node initNode(int value);

#endif
