/**
 * @file lab2.c
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

// This function takes two integer variables by address and returns the summation of them.
int sum(int *a, int *b) {
  return *a + *b;
}

int main() {
  // Ask the user to enter two values.
  int a, b;
  printf("Enter number1: ");
  scanf("%d", &a);
printf("Enter number2: ");
scanf("%d", &b);

  // Save the user's input in two variables.
  int x = a;
  int y = b;

  // Send the variables to the function by address.
  int result = sum(&x, &y);

  // Print the result.
  printf("The sum of the two numbers is %d.\n", result);

  return 0;
}