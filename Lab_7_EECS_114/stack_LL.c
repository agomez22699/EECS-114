/* Adrian Gomez
SID:20119988
EECS 114
Lab 7
2/18/2021
stack_LL.c */

#include <stdio.h>
#include <stdlib.h>

struct StackNode {
	int data;
	struct Node* next;
};

struct StackNode* newNode(int data) {
	struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

struct StackNode* top; //helper to have the location of the top element at all  times

void push(struct StackNode* root, int data) {
	struct StackNode* temp = (struct StackNode*)malloc(sizeof(struct StackNode)); // allocate mem for the temp structure
	temp->data = data; // sets the new data 
	temp->next = top; // puts top in next
	top = temp; // this makes the temp the top of the stack 
	printf("\n%d has been added to the stack\n", top->data);
}

int pop(struct StackNode* root) {
	struct StackNode* temp;

	if (top == NULL) { // want to check if we're removing more elments than we have
		printf("\npopping more than the elements in the stack\n");
	}
	else{
		int x; //temp variable to return 

		temp = top; // set the reference for top to temp
		x = top->data; //here we want to return the data we are popping
		top = top->next; // we want to save the next pointer 
		temp->next = NULL; // remove the reference
		free(temp); // restore the memory 
		return x; // return the data element that was removed
	}

}

int isEmpty(struct StackNode* root) {
	return (top == NULL); // we want a boolean true/ false to check if the stack is empty
	// 0 for not empty, 1 for empty
}

int peek(struct StackNode* root) {
	int x = isEmpty(top);
	if (x == 0) { // checks to see if the top pointer is null, if not then return the data thats on top 
		return (top->data);
	}
	else {
		printf("\n error, stack is empty\n");// if the stack is empty, then this will print 
	}
}

int main() {
	int i = 3;
	struct StackNode* temp;
	struct StackNode* StackNode = newNode(64);

	push(StackNode, 128);
	push(StackNode, 256);
	push(StackNode, 512);

	int y;

	y = peek(StackNode);
	printf("\n%d is the peek of the stack\n", y);

	y = pop(StackNode);
	printf("\n%d has been popped from the stack\n", y);

	push(StackNode, 1024);
	
	temp = top;

	while (temp != NULL) {
		printf("\nNode %d has the Data: %d\n", i, temp->data);
		temp = temp->next;
		i--;
	}
	y = isEmpty(StackNode);
	printf("\nThis is an isEmpty check. %d, if 0 then stack is not empty. if 1 then the stack is empty\n", y);

	y = pop(StackNode);
	printf("\n%d has been popped from the stack\n", y);

	//we want to show that we have created these nodes
	i = 2;
	temp = top;

	while (temp != NULL) {
		printf("\nNode %d has the Data: %d\n", i, temp->data);
		temp = temp->next;
		i--;
	}
}