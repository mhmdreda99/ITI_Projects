#include <stdio.h>

int main()
{

    unsigned int i = 1, n, factorial = 1;
    printf("please Enter anumebr :");
    scanf("%d", &n);

    do
    {
        factorial *=n;
        
        n--;

    } while (n>0);

    printf("%d", factorial);
}