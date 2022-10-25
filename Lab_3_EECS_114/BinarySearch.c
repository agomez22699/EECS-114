/* Adrian Gomez
SID:20119988
EECS 114
Lab 3
1/20/2021
BinarySearch.c
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int BinarySearch(int initialLength,int length, int numToFind, int array[]) {

	if (length > initialLength) {

		int middle =(length - initialLength) / 2;
		middle += initialLength; // to find the middle of the array 

		if (array[middle] == numToFind) {
			return middle;
		}
		else if (numToFind < array[middle] ) {
			return BinarySearch(initialLength, middle - 1, numToFind, array); // if not middle search lower
		}
		else {
			return BinarySearch(middle + 1, length, numToFind, array); // if its not middle or in the left side of the array look in top part
		}

	}

	return -100;
}

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
	int searchResult;
	int numToFind = 10;
	int initialIndex = 0;
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
	} // prints initial array
	printf("\n");

	mergeSortAlg(0, length - 1, array);

	for (i = 0; i < length; i++) {//printing alg.
		printf("%d ", array[i]); // prints on the same line
	}// prints sorted array

	clock_t begin, end;
	double time;
	begin = clock(); //record the begining time

	searchResult = BinarySearch(initialIndex ,length, numToFind, array); //put the return number into search result for comparison

	end = clock(); //record the end time
	double end2 = (double)end;
	double begin2 = (double)begin;
	time = (end2 - begin2) * 1000 / CLOCKS_PER_SEC;
	printf("\nThe execution time of Linear Search is %f ms\n", time);

	if (searchResult == -100) {
		printf("The element %d was not found in the array.\n", numToFind); // if not found
	}
	else { printf("The element %d was found at index %d", numToFind, searchResult); } // if result is found with index and number that was wanted
}