/**
 * @file lab1.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief Write a C code that ask the user to enter 2
    values and save them in two variables, then
    the program sends these variables by address
    to a function that returns the summation of
    them. The program then prints the result.
 * @version 0.1
 * @date 2023-07-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>

int main()
{
    int x = 10;
    printf("x besfore change  = %d", x);

    int *ptr;
    ptr = &x;
    *ptr = 20;
    printf("\nx after change = %d", *ptr);
}