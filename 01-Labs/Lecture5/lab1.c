/**
 * @file lab1.c
 * @author mhmdreda99 (dev.mhmdreda99@gmail.com)
 * @brief 
 * Write a C code that ask the user to enter 10
 *   values and save them in an array using a for
 *   loop. Then print the values entered by the
 *  user in reverse order using another for loop.
 * @version 0.1
 * @date 2023-07-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int main() {
  int i, n, arr[10];
// ask user to provide how many number to store 
  printf("Enter the number of elements: ");
  scanf("%d", &n);
// take user input store them in an array 
  for (i = 0; i < n; i++) {
    printf(" Please Enter number  %d: ", i + 1);
    scanf("%d", &arr[i]);
  }
// print the array giver by user in reverse order  
  printf("The value  in reverse order are: ");
  for (i = n - 1; i >= 0; i--) {
    printf("%d\n", arr[i]);
    
  }

  return 0;
}