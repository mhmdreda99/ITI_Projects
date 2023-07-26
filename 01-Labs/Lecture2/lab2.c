#include <stdio.h>

// lab2 
/*Write a C code to calculate employee
salary in a week based on the his
working hours, hour rate is 50.
The program will ask the user to enter
the working hours, then it will print his
salary.
But if the working hours are less than 40
hours, a 10% deduction will be applied */
int main()
{
    unsigned int hours;
    float salary;
// ask user to provide working hours 
    printf("Enter the number of hours worked: ");
    scanf("%u", &hours);
// CHECK FOR CONDITION
    if (hours <= 40)
    {
        salary = hours * 50 * 0.9;
    }
    else
    {
        salary = hours * 50;
    }
// priint the salary 
    printf("The salary is %.2f", hours * 50 * 0.9;);
    return 0;
}