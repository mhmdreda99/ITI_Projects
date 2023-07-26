
/**
 * @file lab3.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief Write a C code that ask the user to enter 10
    values and save them in an array using a for
    loop. Then print the summation and the
    average of the values entered.
 * @version 0.1
 * @date 2023-07-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main()

{
    unsigned int i ,Sum=0  ;
    int arr[10];
    // Take user input 
    for (i=0; i<10 ;i++)
    {
        printf("Please Enter number %d:",i+1);
        scanf("%d",&arr[i]);
        Sum+=arr[i];
    }

    // printing 
    printf("Sum = %d\n",Sum);
    printf("Average %d",Sum/10);

    return 0 ;
    
}