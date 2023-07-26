#include <stdio.h>

int main()
{

    unsigned int i,num ,result=0 ;
    printf("please Enter anumebr :");

    for (i=0 ;i<5 ;i++)
    {

        scanf("%d",&num);
       
        if (num < 0)
            continue;
        result+=num;
        
        
    }
    printf("sum=%d",result);
}