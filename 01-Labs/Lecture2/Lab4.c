
// lab 4

#include <stdio.h>
int main()
{
    int grade;
    printf("Enter your grade: ");
    scanf("%d", &grade);
    if (grade <= 50)
        printf("Failed");
    else if (grade < 65)
        printf("Normal");
    else if (grade < 75)
        printf("Good");
    else if (grade < 85)
        printf("Very Good");
    else
        printf("Excellent");
    return 0;
}