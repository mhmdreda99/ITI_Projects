/**
 * @file lab6.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief Write a C code that define 2 arrays, and send them
    to a function that apply scalar multiplication
    between the two arrays and return the result, the
    main function then will print the result.
 * @version 0.1
 * @date 2023-07-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

// This function multiplies two arrays together and returns the result.
int scalar_multiplication(int a[], int b[], int n) {
  int i, result = 0;
  for (i = 0; i < n; i++) {
    result += a[i] * b[i];
  }
  return result;
}

/*This is the main function. It defines two arrays and calls
 the scalar_multiplication() function 
to multiply them together. The result is then printed to the console.*/
int main() {
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {6, 7, 8, 9, 10};
  int n = sizeof(a) / sizeof(a[0]);

  int result = scalar_multiplication(a, b, n);

  printf("The result of the scalar multiplication is: %d\n", result);

  return 0;
}