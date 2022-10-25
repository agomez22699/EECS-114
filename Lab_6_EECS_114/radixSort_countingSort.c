/* Adrian Gomez
SID:20119988
EECS 114
Lab 6
2/11/2021
radixSort_with_countingSort.c */

#include <stdio.h>
#include <stdlib.h>

int findMax_Alg(int length, int array[]) {
	int maximum;
	maximum = array[0]; // we set the max to the first element then we change when theres something greater

	for (int i = 1; i < length; i++) {
		if (maximum < array[i]) {
			maximum = array[i]; // keep changing the maximum if theres a greater number
		}
	}

	return maximum; // returns the largest element from the array

}

void countingSort(int length, int x, int array[]) {
	int b[length + 1];
	int maximum;
	maximum = array[0] / x;
	maximum = maximum % 10;

	for (int i = 1; i < length; i++) { // this for loop finds the max place of the elements

		if (maximum < ((array[i] / x) % 10)) {

			maximum = array[i];

		}
	}

	int c[maximum + 1]; // creates another array

	for (int j = 0; j < maximum; ++j) { // sets all the elements to 0

		c[j] = 0;

	}

	for (int k = 0; k < length; k++) { // this for loop counts the amount of elements

		c[(array[k] / x) % 10]++;

	}

	for (int y = 1; y < 10; y++) {

		c[y] += c[y - 1];

	}

	for (int u = length - 1; u >= 0; u--) {// this for loop places the elements into the array, sorted

		b[c[(array[u] / x) % 10] - 1] = array[u];

		c[(array[u] / x) % 10]--;

	}

	for (int i = 0; i < length; i++) {

		array[i] = b[i]; // transfer to the main array

	}


}


void radixSort_Alg(int length, int array[]) {
	int maximum;
	maximum = findMax_Alg(length, array);

    // variable where we want to check the place of the element

	// we want to sort by the places 

	for (int x = 1; 0 < maximum / x; x *= 10) {
		countingSort(length, x, array);

		printf("Unsorted array of %d place: ", x);
		int i; // printing variable	
		for (i = 0; i < length; i++) {//printing alg.
			printf("%d ", array[i]); // prints on the same line
		} // prints initial array
		printf("\n");
	}


}

int main() {
	int length = 10;
	int min = 0;
	//we must start an array with a given length.
	int array[10] = { 2,10,17,97,351,9,52,967,231, 75 };
	printf("Unsorted array: ");
	int i; // printing variable	
	for (i = 0; i < length; i++) {//printing alg.
		printf("%d ", array[i]); // prints on the same line
	} // prints initial array
	printf("\n");

	radixSort_Alg(length, array); // calls quickSort_Alg to sort the array

	printf("Sorted array:");

	for (i = 0; i < length; i++) {//printing alg.
		printf("%d ", array[i]); // prints on the same line
	} // prints initial array
	printf("\n");
}