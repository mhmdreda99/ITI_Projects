#include <stdio.h>

void selection_sort(int arr[], int arr_count )
{
    // loop min 
    for (int i = 0; i < arr_count - 1; i++)
    {
        int min_index = i; //
        int temp; 
        // loop on elements 
        for (int j = i + 1; j < arr_count; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        // swap the last with the 1st 
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

#include <stdio.h>

int main()
{
    int arr[] = {10, 5, 2, 7, 3};
    int count = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, count);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
