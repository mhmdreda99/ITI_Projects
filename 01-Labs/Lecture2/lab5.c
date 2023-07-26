#include <stdio.h>
int main()
{
    int id;
    printf("Enter your ID: ");
    scanf(" %d ", &id);
    switch (id)
    {
    case 1234:
        printf("Hello Ahmed.\n");
        break;
    case 5678:
        printf("Hello Youssef.\n");
        break;
    case 1145:
        printf("Hello Mina.\n");
        break;
    default:
        printf("Wrong ID , Please try another one .\n");
    }
    return 0;
}