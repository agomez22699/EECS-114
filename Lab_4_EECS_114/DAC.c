/* Adrian Gomez
SID:20119988
EECS 114
Lab 4
1/27/2021
DAC.c
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

int findMax(int a, int b, int c) { // finds the greatest amongst 3 numbers that were given 
	if (a >= b && a >= c) {
		return a;
	}
	else if (b >= c && b >= a) {
		return b;
	}
	else {
		return c;
	}
}

int max_cross(int array[], int min, int middle, int length, int* left, int* right) {
	int left_sum = INT_MIN; //negative infinty
	int right_sum = INT_MIN; // negative infinity
	int result = 0;
	int l, r;

	for (int i = middle; i >= min; i--) {
		result += array[i];
		if (left_sum < result) {
			left_sum = result;

			l = i;
		}
	}

	result = 0;

	for (int j = middle + 1; j <= length; j++) {
		result += array[j];
		if (right_sum < result) {
			right_sum = result;

			r = j;
		}
	}

	*left = l;
	*right = r;



	return (right_sum + left_sum);

}

int Find_max_sub(int array[], int min, int length, int* left, int* right) {

	if (length == min) {
		*left = min;
		*right = length;
		return array[min];
	}
	else {
		int middle = (min + length) / 2;
		int max_sum_left = Find_max_sub(array, min, middle, left, right); // divide and conq.
		int max_sum_right = Find_max_sub(array, middle + 1, length, left, right); // divide and conq.
		int max_sum_crossing = max_cross(array, min, middle, length, left, right); //divide and conq.
		return findMax(max_sum_left, max_sum_right, max_sum_crossing);// compare the 3 values that were found.
	}
}

int main() {
	int length = 10;
	int min = 0;
	//we must start an array with a given length.
	int array[10];
	int searchResult;
	int left, right;
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

	clock_t begin, end;
	double time;
	begin = clock(); //record the begining time

	searchResult = Find_max_sub(array, min, length - 1, &left, &right);

	end = clock(); //record the end time
	double end2 = (double)end;
	double begin2 = (double)begin;
	time = (end2 - begin2) * 1000 / CLOCKS_PER_SEC;
	printf("\nThe execution time of DAC Max Sub array is %f ms\n", time);

	printf("Max: %d, Index left: %d, Index right %d", searchResult, left, right);
}