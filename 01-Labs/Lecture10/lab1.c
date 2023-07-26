/**
 * @file lab1.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief
 * Write a C code that apply the bubble
    sorting algorithm on a set of numbers
    entered by the user. The code shall ask
    the user to enter the number of values
    to be sorted, then the code shall ask the
    user to enter the values then print them
    in ascending order
 * @version 0.1
 * @date 2023-07-26
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>
#include <stdlib.h>

// This function sorts the array `arr` in ascending order using the bubble sorting algorithm.
void bubbleSort(int arr[], int n)
{
    // Iterate through the array from the beginning to the end.
    for (int i = 0; i < n - 1; i++)
    {
        // Iterate through the array from the beginning to the end, comparing each pair of adjacent elements.
        for (int j = 0; j < n - i - 1; j++)
        {
            // If the current element is greater than the next element, swap them.
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// This function gets the number of values from the user.
int getNumValues()
{
    // Prompt the user to enter the number of values.
    printf("Enter the number of values: ");

    // Get the number of values from the user.
    int numValues;
    scanf("%d", &numValues);

    // Return the number of values.
    return numValues;
}

// This function gets the values from the user.
int *getValues()
{
    // Get the number of values from the user.
    int numValues = getNumValues();

    // Allocate memory for the array of values.
    int *values = malloc(numValues * sizeof(int));

    // Get the values from the user.
    for (int i = 0; i < numValues; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    // Return the array of values.
    return values;
}

int main()
{
    // Get the array of values from the user.
    int *values = getValues();

    // Get the length of the array.
    int n = getNumValues();

    // Sort the array in ascending order.
    bubbleSort(values, n);

    // Print the sorted array.
    for (int i = 0; i < n; i++)
    {
        printf("%d ", values[i]);
    }

    // Free the memory allocated for the array.
    free(values);

    // Exit the program.
    return 0;
}
