/* Adrian Gomez
SID:20119988
EECS 114
Lab 7
2/18/2021
ll.c */

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

int main() {

	// we want to delcare the 3 nodes of the linked list
	struct Node* node1 = NULL; // we have the head point to null and this is also known as the head of the list
	struct Node* node2 = NULL; // have the node point to null
	struct Node* node3 = NULL;


	// we want to allocate the appropiate space for the nodes in the memory
	node1 = (struct Node*)malloc(sizeof(struct Node)); // sets the memory to the node 
	node2 = (struct Node*)malloc(sizeof(struct Node));
	node3 = (struct Node*)malloc(sizeof(struct Node));

	node1->data = 64; // sets the data of the node to 64
	node1->next = node2; // sets the pointer of next to the next node

	node2->data = 128; // sets the data of the node to 128
	node2->next = node3; // sets the pointer of next to the next node

	node3->data = 256; // sets the data of the node to 256
	node3->next = NULL; // sets the pointer to null since there is not another node to point to

	//we want to show that we have created these nodes
	int i = 1;
	struct Node* temp;
	temp = node1;

	while (temp != NULL) {
		printf("Node %d has the Data: %d\n",i, temp->data);
		temp = temp->next;
		i++;
	}
}