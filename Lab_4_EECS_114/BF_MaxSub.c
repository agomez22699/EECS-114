/* Adrian Gomez
SID:20119988
EECS 114
Lab 4
1/27/2021
BF_MaxSub.c
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>


int Find_Max_Sub(int array[], int length, int* left, int* right){
	int bestSum = INT_MIN; //(negative infnity)
	int l, r;


	for (int i = 0; i <length; i++){
		int result = 0;

		for (int j = i; j <length; j++){
			result += array[j];
			if (result >= bestSum) {
				bestSum = result;
				r = j;// saving indices
				l = i;//saving indices
			}
		}
	}

	*left = l; // a way to send the indices back to the main function
	*right = r; // a way of sending the indices back to the main function 

	return bestSum;
}

int main() {
	int length = 10;
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

	searchResult = Find_Max_Sub(array, length, &left, &right);

	end = clock(); //record the end time
	double end2 = (double)end;
	double begin2 = (double)begin;
	time = (end2 - begin2) * 1000 / CLOCKS_PER_SEC;
	printf("\nThe execution time of Brute Force Max Sub array is %f ms\n", time);

	printf("Max: %d, Index left: %d, Index right %d", searchResult, left, right);
}