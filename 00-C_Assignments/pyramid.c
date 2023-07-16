#include <stdio.h>

/**
 * @brief 
 * this function to print a full pyramid based on user input 
 * rows 
 * 
 * 
 */
void main()
{
    int row, col, space = 0;
    printf("Please enter rows number :");
    scanf("%d", &row);

    for (int i = 1; i <= row; i++, col = 0)
    {
        for (space = 1; space <= row - i; space++)
        {
            printf("  ");
        }
        while (col != 2 * i - 1)
        {
            printf("* ");
            col++;
        }
        printf("\n");
    }
}