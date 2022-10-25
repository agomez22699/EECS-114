/* Adrian Gomez
SID:20119988
EECS 114
Lab 8
2/25/2021
bst.c */

#include <stdio.h>
#include <stdlib.h>

struct Node { // structure for the node
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int newData) { // creates a new node
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = newData;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}



struct Node* insertion(struct Node* root, int data) {

	if (root == NULL) {
		return newNode(data);//creates a new node for the data
	}

	else if (root->data < data) {
		//recursively inserts new data through the right of the tree
		root->right = insertion(root->right, data); // this compares the root with the data. if its greater than, then it will insert in the right tree.
	}

	else if (root->data > data) {
		//recursively inserts new data through the left of the tree
		root->left = insertion(root->left, data); // this comapres the root with the data. if its less than, then it will insert in the left tree.
	}

	return root; // returns the tree
}

int search(struct Node* root, int k) {
	while (root != NULL) {
		if (root->data > k) {
			root = root->left; // keep iterating through the left to find the key
		}

		else if (root->data < k) { // keep iterating through the right to find the key 
			root = root->right;
		}
		else {
			return 1; // if found return 1
		}
	}
	return 0; // if not found return 0
}

void printTree(struct Node* root) {
	if (root != NULL) {
		//calls the print function recursively
		printTree(root->left); // go through the left of the tree
		
		printf("%d ", root->data); // point to the data
		//calls the print function recursively
		printTree(root->right); // go through the right of the tree

	}
}

int main() {
	struct Node* root = NULL;
	root = insertion(root, 20); // create node with 20 as root
	printf("Completed inserting 20\n");
	insertion(root,64); // insert 64 in the correct position
	printf("Completed inserting 64\n");
	insertion(root,5); //insert 5 in the correct position
	printf("Completed inserting 5\n");
	insertion(root,42); // insert 42 in the correct position
	printf("Completed inserting 42\n");
	insertion(root, 9); // insert 9 in the correct position
	printf("Completed inserting 9\n");
	insertion(root, 30); //insert 30 in the correct position
	printf("Completed inserting 30\n");
	insertion(root, 11); // insert 11 in the correct position
	printf("Completed inserting 11\n");
	printf("Printing the tree in order...\n");

	printTree(root); // print the tree in order

	printf("\nSearching for 10\n");
	if (search(root, 10) == 0) { // search for 10 in the binary tree
		printf("10 is not in the BST");
	}
	printf("\nSearching for 42\n");
	if (search(root, 42) == 1) { //search for 42 in the binary tree
		printf("42 is indeed in the BST\n");
	}
}