#include <stdio.h>

int main()
{
    int num1,num2,num3;
    // ask user to enter 3 number 
    printf("Please Enter number 1 :");
    scanf("%d",&num1);
    printf("Please Enter number 2 :");
    scanf("%d",&num2);
    printf("Please Enter number 3 :");
    scanf("%d",&num3);

    // reversed_order
    printf("number 3: %d\nnumber 2: %d \nnumber 3: %d",num3,num2,num1);
    return 0 ;
}