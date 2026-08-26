/*
	Estudo sobre a implementação da estrutura de dados lista
	@author: Mateus "oestrangeiro" Almeida
	data: 08/2026
*/



#include <stdio.h>
#include "../../includes/node.h"
#include <stdlib.h>


unsigned int getSizeOfList(Node *firstNode){

	Node *tempNode =  firstNode;

	int sizeOfList = 0;

	while(tempNode){
		sizeOfList++;
		tempNode = tempNode->next;
	}

	return sizeOfList;
}

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

	// Atualiza o tamanho da lista
	// G_currentSizeOfList = i + 1;
	// Nesse exemplo em particular eu nem preciso fazer isso:
	// G_currentSizeOfList = getSizeOfList();
	// Porque o i dentro do laço while já me trás o tamanho da lista
	// (no caso i + 1), mas fora desse laço, o ideal é sempre usar
	// a função getSizeOfList();
}

// Edita o valor de uma nó já existente com base na posição do elemento

void editANode(Node *firstNode, unsigned int positionNodeToEdit, int newValue){


	// Se a posição pra ediçao for negativa
	if(positionNodeToEdit <= 0){
		printf("[!] Insira uma posição de nó válida para edição!\n");
		exit(2);
	}

	// Se o indice para edição estiver fora do tamanho da lista
	if(positionNodeToEdit > getSizeOfList(firstNode)){
		printf("[!] Insira uma posição de nó válida para edição!\n");
		exit(3);
	}
	
	Node *currentNode = firstNode;

	unsigned int currentIndex = 0;
	while(currentIndex != (positionNodeToEdit - 1)){
		currentNode = currentNode->next;
		currentIndex++;
	}

	currentNode->value = newValue;
	
}


void* removeANode(Node *firstNode, unsigned int nodePositionToRemove){

	// A brincadeira aqui vai ser:
	// Dado um nó na posição I,
	// pegar o nodeI-1->next e apontar para
	// nodeI+1 e então deletar nodeI


	// Se a posição pra remoção for negativa
	if(nodePositionToRemove <= 0){
		printf("[!] Insira uma posição de nó válida para remoção!\n");
		exit(2);
	}

	// Se o indice para remoção estiver fora do tamanho da lista
	if(nodePositionToRemove > getSizeOfList(firstNode)){
		printf("[!] Insira uma posição de nó válida para remoção!\n");
		exit(3);
	}

	Node *previousNode, *currentNode, *nextNode;

	currentNode = firstNode;

	// Se o nó for o primeiro
	if(nodePositionToRemove == 1){
		nextNode = firstNode->next;

		// Desaloco o nó
		free(firstNode);

		// Retorno o NOVO primeiro nó
		return nextNode;

	}


	// Se o nó for o último
	if(nodePositionToRemove == getSizeOfList(firstNode)){
		for(int i = 0; i < nodePositionToRemove - 2; i++){
			currentNode  = currentNode->next;
			previousNode = currentNode;

			// Debug
			// printf("mem currentNode (%d): [%p] -> (%d)\n", i, currentNode, currentNode->value);
			// printf("mem previousNode (%d): [%p] -> (%d)\n", i, previousNode, previousNode->value);
		}



		currentNode = currentNode->next;
		free(currentNode);

		previousNode->next = NULL;

		return firstNode;
	}

	// Se for qualquer nó entre o segundo e o penúltimo
	for(int i = 0; i < nodePositionToRemove - 1; i++){
		// Pegando o nó anterior
		previousNode = currentNode->next;
	}

	// Ligando o nó anterior com o posterior
	currentNode = previousNode->next;
	nextNode	= currentNode->next;
	previousNode->next = nextNode;

	free(currentNode);

	return firstNode;

}

int main(int argc, char *argv[]){

	Node firstNode 			 = initNode(20);
	int nodePositionToEdit 	 = 2;
	int nodePositionToRemove = 5;
	int valueToEdit 		 = 0;

	printf("Número de elementos na lista: %d\n", getSizeOfList(&firstNode));


	printf("Adicionando nós...\n");
	addNode(&firstNode, 11);
	addNode(&firstNode, 22);
	addNode(&firstNode, 33);
	addNode(&firstNode, 10);

	// Lendo os valores da lista
	printf("Listando os nós...\n");
	listAllNodes(&firstNode);

	editANode(&firstNode, nodePositionToEdit, valueToEdit);
	printf("Edição do nó %d para o valor %d\n", nodePositionToEdit, valueToEdit);

	printf("Listando os novos nós...\n");
	listAllNodes(&firstNode);

	printf("Número de elementos na lista: %d\n", getSizeOfList(&firstNode));

	// Removendo o nó
	printf("Removendo o nó %d\n", nodePositionToRemove);
	Node *newFirstNode = removeANode(&firstNode, nodePositionToRemove);
	
	printf("Listando os novos nós...\n");
	listAllNodes(newFirstNode);

	return 0;
}
