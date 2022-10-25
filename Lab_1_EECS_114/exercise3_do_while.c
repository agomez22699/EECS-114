/*
 * exercise3_do_while.c
 *
 *  Created on: Jan 6, 2021
 *      Author: Adrian Gomez
 */

#include <stdio.h>


int main(){
	double number, sum =0;
	do{
		printf("Enter a number: ");
		scanf("%lf", &number);
		sum += number;
	}while(number != 0.0);

	printf("Sum = %.2lf", sum);
	return 0;
}
