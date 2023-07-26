/**
 * @file lab5.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief Write a C code that ask the user to enter 10 values and save them in an array
    using a for loop. Then ask the user to enter a value to search about, if the value
    existing in the 10 values, the program will print “Value Exists x times” where x
    defines how many times the value exists. If the value is not exist, the program
    will print “Value Not Exist”. Use Linear Searching Algorithm.
 * @version 0.1
 * @date 2023-07-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
/**
 * @brief 
 * 
 * @return int 
 */
int main()
{
 
    int arr[10], i,num, count_flag = 0;
    printf("Enter 10 numbers: ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to be searched: ");
    scanf("%d", &num);
    for (i = 0; i < 10; i++)
    {
        if (arr[i] == num)
        {
            count_flag++;
        }
    }
    if (count_flag > 0)
    {
        printf("Value Exists %d times ", count_flag);
    }
    else
    {
        printf("Value Not Exist ");
    }
    return 0;
}