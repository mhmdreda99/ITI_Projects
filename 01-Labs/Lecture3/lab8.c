#include <stdio.h>

int main()
{

    unsigned int i,num ;
    printf("please Enter anumebr :");

    for (i=0 ;i<10 ;i++)
    {
        printf("%d\n",i);
        scanf("%d",&num);
        if(num==5)
            break;
        
    }
}