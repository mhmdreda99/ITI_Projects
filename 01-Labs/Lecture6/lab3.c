/**
 * @file lab3.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief Write a C code that ask the user to enter 2
    the program sends these variables to
    values and save them in two variables, then
    function that calculates the summation and
    subtraction of them, the function returns the
    2 results and return them in two pointers
    received as input arguments . The program
    then print the 2 results
 * @version 0.1
 * @date 2023-07-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
/*
 * This function calculates the sum and subtraction of two integers. It takes two pointers to integers as input arguments and returns two pointers to integers as output arguments. 
 */
void calculateSumAndSubtraction(int *sum, int *subtraction, int first, int second) {
    *sum = first + second;
    *subtraction = first - second;
}
/*
 * The main function asks the user to enter 
 two integers and then calls the calculateSumAndSubtraction 
 function to calculate the sum and subtraction of these two integers. 
 It then prints the results. 
 */
int main() {
    int first, second, sum, subtraction; 
    printf("Enter two integers: ");
    scanf("%d", &first);
    scanf("%d", &second);

calculateSumAndSubtraction(&sum, &subtraction, first, second); // call the calculateSumAndSubtraction function
printf("The sum of the two numbers is %d.\n", sum); // print the sum
printf("The subtraction of the two numbers is %d.\n", subtraction); // print the subtraction
return 0; 
}