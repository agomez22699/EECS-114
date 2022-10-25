/* Adrian Gomez
SID:20119988
EECS 114
Lab 6
2/11/2021
quickSort.c */

#include <stdio.h>
#include <stdlib.h>


void swapTerms(int* x, int* y) {
	int tempVar; // temp variable to retain the old location of x and contents
	tempVar = *x;
	*x = *y;
	*y = tempVar;
	// done with the swap
}

int partition(int min, int max, int array[]) {
	int x = array[max]; // start of the first subarray
	int i = min - 1; //the start of the second subarray

	for (int j = min; j <= max - 1; j++) { // j has the remaining of the array
		if (array[j] < x) {
			i++; // increasing the index of the smaller element
			swapTerms(&array[j], &array[i]); //swapping the two elements
		}
	}
	swapTerms(&array[i + 1], &array[max]);
	return (i + 1);
}


void quickSort_Alg(int min, int max, int array[]) {
	if (min < max) {
		int q = partition(min, max, array);
		quickSort_Alg(min, q - 1, array);
		quickSort_Alg(q + 1, max, array);
	}
}

int main() {
	int length = 20;
	int min = 0;
	//we must start an array with a given length.
	int array[20];
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

	quickSort_Alg(0, length - 1, array); // calls quickSort_Alg to sort the array

	printf("Sorted array:");

	for (i = 0; i < length; i++) {//printing alg.
		printf("%d ", array[i]); // prints on the same line
	} // prints initial array
	printf("\n");
}