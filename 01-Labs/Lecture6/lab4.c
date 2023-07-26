/**
 * @file lab4.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief swap function usinig pointer 
 * @version 0.1
 * @date 2023-07-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int swap(int *x, int *y) {
  int temp =*x ;
  *x=*y ;
  *y=temp;
}

int main()
{
    int x = 20, y = 50;
    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swapping: x = %d, y = %d\n", x, y);
    return 0;
}