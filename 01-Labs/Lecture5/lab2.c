/**
 * @file lab2.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-07-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int i, flag = 1;
    // Take two stirngs
    printf("Enter first string: ");
    scanf("%[^\n]%*c", str1);
    printf("Enter second string: ");
    scanf("%[^\n]%*c", str2);
// check if the two stings are equal 
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
        {
            flag = 0;
            break;
        }
    }
 // check for flag status 
    if (flag == 1)
        printf("Welcome %s.", str1);
    else
        printf("The two strings are not equal.");

    return 0;
}