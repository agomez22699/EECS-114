/* Adrian Gomez
SID:20119988
EECS 114
Lab 2
1/13/2021
mergeSort.c
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mergeAlg(int lowerBound, int x, int upperBound, int array[]) {

	int a, b;
	int c = lowerBound;
	int n1 = 1 + x - lowerBound;
	int n2 = upperBound - x;

	int L[n1];
	int R[n2];

	for (a = 0; a < n1; a++) {
		L[a] = array[lowerBound + a];
	}
	for (b = 0; b < n2; b++) {
		R[b] = array[1 + x + b];

	}

	a = 0;
	b = 0;

	while (a < n1 && b < n2) { // compares and merges the arrays
		if (L[a] <= R[b]) {
			array[c] = L[a];//copy the array
			a++; //increase the for loop

		}
		else {
			array[c] = R[b]; //copy the array
			b++; // increase the for loop

		}
		c++; //increase the pointer
	}

	while (a < n1) { // this merges the remaining elements from the left array
		array[c] = L[a];
		c++; //increase the pointer
		a++;//increase the pointer 
	}

	while (b < n2) { // this merges the remaining elements from the right array
		array[c] = R[b];
		c++;//increase the pointer
		b++;//increase the pointer
	}

}

void mergeSortAlg(int lowerBound, int upperBound, int array[]) {
	if (lowerBound < upperBound) {
		int x;
		x = (upperBound - lowerBound) / 2; // finding x
		x += lowerBound;

		mergeSortAlg(lowerBound, x, array); //conq,
		mergeSortAlg(x + 1, upperBound, array); //conq.

		mergeAlg(lowerBound, x, upperBound, array);
	}

}

int main() {
	int length = 10;
	//we must start an array with a given length.
	int array[10];
	int y; //responsible for creating array elements
	int element; // element gets put into this variable to get put into array
	for (y = 0; y < length; y++) {
		element = (rand() % length) + 1; // makes elements range from 1-the actual length of array 
		array[y] = element;
	}
	int i; // printing variable	
	for (i = 0; i < length; i++) {//printing alg.
		printf("%d ", array[i]); // prints on the same line
	}
	printf("\n");

	clock_t begin, end;
	double time;
	begin = clock(); //record the begining time

	mergeSortAlg(0, length - 1, array);

	end = clock(); //record the end time
	double end2 = (double)end;
	double begin2 = (double)begin;
	time = (end2 - begin2) * 1000 / CLOCKS_PER_SEC;
	printf("\n%f ms\n", time);

	for (i = 0; i < length; i++) {//printing alg.
		printf("%d ", array[i]); // prints on the same line
	}
}