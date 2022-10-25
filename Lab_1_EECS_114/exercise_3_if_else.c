/*
 * exercise3_if.c
 *
 *  Created on: Jan 6, 2021
 *      Author: Adrian Gomez
 *      SID: 20119988
 *      EECS 114
 */

#include <stdio.h>

int main(){
	int num;
	printf("Enter an integer:");
	scanf("%d", &num);
	if(num%2 == 0){
		printf("%d is an even integer.", num);
	}
	else{
		printf("%d is an odd number.", num);
	}
	return 0;
}



