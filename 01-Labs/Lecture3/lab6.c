#include <stdio.h>

int main()
{
    unsigned int i, n;
    printf("please Enter how many numebr :");
    scanf("%d", &n);
    printf("Odd numebr are :");
    for (i = 1; i <= n; i++)
    {
        if (i%2!=0) 
            printf("%d ",i);
    }
}