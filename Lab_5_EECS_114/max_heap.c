/* Adrian Gomez
SID:20119988
EECS 114
Lab 5
2/3/2021
max_heap.c
*/

#include <stdio.h>
#include <stdlib.h>


void swapTerms(int *x, int *y) {
	int tempVar; // temp variable to retain the old location of x and contents
	tempVar = *x;
	*x = *y;
	*y = tempVar;
	// done with the swap
}

void max_heapify(int array[], int length, int max) {
	int maximum = max; //maximum value
	int leftChild = 1 + 2 * max; // looks for the maximum leftChild
	int rightChild = 2 + 2 * max; // looks for the maximum rightChild

	if (array[leftChild] > array[maximum] && leftChild < length){
		maximum = leftChild; //exchanges indicies
	}

	if (array[rightChild] > array[maximum] && rightChild <length){
		maximum = rightChild; //exchanges indicies
	}
	if (maximum != max) {
		swapTerms(&array[maximum], &array[max]); //swaps the terms
		max_heapify(array, length, maximum); //calls to max_heapify
	}
}

void build_maxHeap(int array[], int length) {
	int i = 0; //counter
	for (i = (length / 2) - 1; i >= 0; i--) { // this portion builds the max heap
		max_heapify(array, length, i);
	}
}

void max_heapSort(int array[], int length) {

	build_maxHeap(array,length);

	int i = 0; //counter
	for (i = length - 1; i >= 0; i--) { // this portion of the code is the heap sort
		swapTerms(&array[i], &array[0]);
		max_heapify(array, i, 0);
		}
}


int main() {
	int length = 10;
	int min = 0;
	//we must start an array with a given length.
	int array[10];


	int y; //responsible for creating array elements
	int element; // element gets put into this variable to get put into array
	for (y = 0; y < length; y++) {
		element = (rand() % length) + 1; // makes elements range from 1-the actual length of array 
		array[y] = element;
	}

	printf("Unsorted array: ");

	int i; // printing variable	
	for (i = 0; i < length; i++) {//printing alg.
		printf("%d ", array[i]); // prints on the same line
	} // prints initial array
	printf("\n");

	max_heapSort(array, length); // calls max_heapSort to sort the array

	printf("Sorted array:");

	for (i = 0; i < length; i++) {//printing alg.
		printf("%d ", array[i]); // prints on the same line
	} // prints initial array
	printf("\n");
}