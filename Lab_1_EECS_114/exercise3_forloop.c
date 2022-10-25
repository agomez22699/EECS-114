/*
 * exercise3_forloop.c
 *
 *  Created on: Jan 6, 2021
 *      Author: Adrian Gomez
 */

#include <stdio.h>

int main (){
	int num = 0, count = 0, sum = 0;
	printf("Enter a positive integer: ");
	scanf("%d", &num);

	for (count = 1; count <= num; ++count){
		sum += count;
	}
	printf("Sum = %d", sum);
	return 0;
}
