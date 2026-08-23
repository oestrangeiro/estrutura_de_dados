#include "node.h"
#include <stdlib.h>

Node initNode(int value) {
	Node initialNode;

	initialNode.value = value;
	initialNode.next  = NULL;

	return initialNode;
}
