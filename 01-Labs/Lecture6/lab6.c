/**
 * @brief 
 * write a function that takes 3 arrays 2 of them are given 
 * multiply array1 and array2 and store the result in arr3
 * the 3 arrays has same length 
 * @param a 
 * @param b 
 * @param c 
 * @param n 
 */
#include<stdio.h>
void multiply_arrays(int *a, int *b, int *c, int arr_size) {
  // multiply each element of the 2 arrays
  for (int i = 0; i < arr_size; i++) {
    c[i] = a[i] * b[i];
  }
}

int main() {
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {4, 5, 6, 7, 8};
  int c[5];

  // multiply the arrays
  multiply_arrays(a, b, c, 5);

  // print the results
  for (int i = 0; i < 5; i++) {
    printf("c[%d] = %d\n", i, c[i]);
  }

  return 0;
}