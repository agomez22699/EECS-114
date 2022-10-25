/* Adrian Gomez
SID:20119988
EECS 114
Lab 2
1/13/2021
insertionSort.c
*/


#include <stdio.h>
#include <math.h>
#include <time.h>

void insertionSortAlg(int length, int array[]) {

	int a = 0; // two temp variables
	int b = 0;
	int key = 0;

	for (a = 1; a < length; a++) { // begin of sorting alg.
		key = array[a];
		b = a - 1;

		while (array[b] > key && b >= 0) {
			array[b + 1] = array[b];
			b = b - 1;
		}
		array[b + 1] = key;
	} // end of sorting alg
}

int main() {
	int length = 10;
	//we must start an array with a given length.
	int array[10];
	int x; //responsible for creating array elements
	int element; // element gets put into this variable to get put into array
	for (x = 0; x < length; x++) {
		element = (rand() % length) + 1; // makes elements range from 1-the actual length of array 
		array[x] = element;
	}

	int i; // printing variable	
	for (i = 0; i < length; i++) {//printing alg.
		printf("%d ", array[i]); // prints on the same line
	}
	printf("\n");

	clock_t begin, end;
	double time;
	begin = clock(); //record the begining time

	insertionSortAlg(length, array);

	end = clock(); //record the end time
	double end2 = (double)end;
	double begin2 = (double)begin;
	time = (end2 - begin2) * 1000 / CLOCKS_PER_SEC;
	printf("\n%f ms\n", time);

	for (i = 0; i < length; i++) {
		printf("%d ", array[i]);//prints on the same line
	}
	return 0;
}