#include <stdio.h>

int main() {
  // Declare  the functions.
  int add(int a, int b);
  int subtract(int a, int b);
  int multiply(int a, int b);
  int divide(int a, int b);
  // Get the user's input.
  int a, b;
  printf("Enter two numbers: ");
  scanf("%d", &a);
  scanf("%d", &b);

  // Choose the function to use.
  int choice;
  printf("Enter 1 to add \n, 2 to subtract\n, 3 to multiply\n, 4 to divide\n ");
  scanf("%d", &choice);

  // Call the function.
  int result;
  switch (choice) {
    case 1:
      result = add(a, b);
      break;
    case 2:
      result = subtract(a, b);
      break;
    case 3:
      result = multiply(a, b);
      break;
    case 4:
      result = divide(a, b);
      break;

    default:
      printf("Invalid choice.\n");
      return 0;
  }

  // Print the result.
  printf("The result is %d.\n", result);

  return 0;
}

// Define the functions.
int add(int a, int b) {
  return a + b;
}

int subtract(int a, int b) {
  return a - b;
}

int multiply(int a, int b) {
  return a * b;
}

int divide(int a, int b) {
  return (float)a / (float)b;
}
