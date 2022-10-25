/*
 * exercise3_while.c
 *
 *  Created on: Jan 6, 2021
 *      Author: signa
 */
#include <stdio.h>

int main(){
	int num;
	long long factorial;

	printf("Enter an integer: ");
	scanf("%d", &num);

	factorial = 1;
	while (num > 0){
		factorial *= num;
		--num;
	}
	printf("Factorial= %lld", factorial);
	return 0;
}

