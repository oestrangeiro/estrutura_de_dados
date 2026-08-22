/*
	Estudo sobre a implementação da estrutura de dados lista
	@author: Mateus "oestrangeiro" Almeida
	data: 08/2026
*/



#include <stdio.h>
#include "../../includes/node.h"
#include <stdlib.h>

// Node* addNode(Node *addressLastNode, unsigned int valueToNewNode){
void addNode(Node *headNode, int valueToNewNode){

	Node *newNode = malloc(sizeof(Node));

	newNode->value = valueToNewNode;
	newNode->next  = NULL;

	Node *lastNode = headNode;

	while(lastNode->next != NULL){
		lastNode = lastNode->next;
	}

	lastNode->next = newNode;

}

void listAllNodes(Node *firstNode){

	Node *currentNode = firstNode;
	int i = 0;
	
	while(currentNode){

		printf("Nó %d: (%d) [%p] -> [%p]\n", i+1, currentNode->value, currentNode, currentNode->next);
		i++;

		currentNode = currentNode->next;
	}
}

// Edita o valor de uma nó já existente com base na posição do elemento

void editANode(Node *firstNode, int positionNodeToEdit, int newValue){

	Node *currentNode = firstNode;

	int currentIndex = 0;
	while(currentIndex != (positionNodeToEdit - 1)){
		currentNode = currentNode->next;
		currentIndex++;
	}


	currentNode->value = newValue;
	
}

int main(int argc, char *argv[]){

	Node firstNode = initNode(20);


	addNode(&firstNode, 30);
	addNode(&firstNode, 67);
	addNode(&firstNode, 100);

	// Lendo os valores da lista

	listAllNodes(&firstNode);
	editANode(&firstNode, 2, 21);
	listAllNodes(&firstNode);
	
	return 0;
}
