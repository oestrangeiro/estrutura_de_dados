/*
	Estudo sobre a implementação da estrutura de dados lista
	@author: Mateus "oestrangeiro" Almeida
	data: 08/2026
*/



#include <stdio.h>


typedef struct Node {
	struct Node *next;
	unsigned int value;
}Node;


Node initNode(unsigned int value){

	Node initialNode;
	initialNode.value = value;
	
	return initialNode;
}

// Node* addNode(Node *addressLastNode, unsigned int valueToNewNode){
void addNode(Node *headNode, unsigned int valueToNewNode){

	Node newNode;
	newNode.value = valueToNewNode;

	Node *lastNode;
	
	while(headNode->next == NULL){
		lastNode = lastNode->next;
	}

	lastNode->next = &newNode;

}

void listAllNodes(Node *firstNode){

	Node *currentNode = firstNode;
	
	while(currentNode){
		
		printf("Nó: (%d) [%p] -> [%p]\n", currentNode->value, currentNode, currentNode->next);

		currentNode = currentNode->next;
	}
}

int main(int argc, char *argv[]){

	Node firstNode = initNode(20);
	

	addNode(&firstNode, 30);
	addNode(&firstNode, 67);
	addNode(&firstNode, 100);

	// Lendo os valores da lista

	listAllNodes(&firstNode);
	
	return 0;
}
