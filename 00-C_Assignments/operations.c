#include <stdio.h>

int main() {
    int a, b;
     printf("Please enter a :");
     scanf("%d", &a);
     printf("Please enter b :");
    scanf("%d",&b);
    int sum = a + b;
    int sub = a - b;
    int and = a & b;
    int or = a | b;
    int xor = a ^ b;
    printf(" a + b= %d\n a - b= %d\n a & b= %d\n a | b= %d\n a ^ b= %d\n ", sum, sub, and, or, xor);
    return 0;
}