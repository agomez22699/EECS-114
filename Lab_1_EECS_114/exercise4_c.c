/*
 * exercise4_c.c
 *
 *  Created on: Jan 6, 2021
 *      Author: signa
 */

#include <stdio.h>

int main(){
    int i, x[6], sum = 0;
    printf("Enter 6 numbers: ");
    for(i = 0; i < 6; ++i){
        scanf("%d", x+i);
        sum += *(x+i);
}
printf ("Sum = %d", sum);

return 0;
}
