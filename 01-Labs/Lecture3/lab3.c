#include <stdio.h>

int main( ) 
{
    unsigned int i,num,sum =0 ;
    printf( "Please Enter 10 numbers : \n "); 
    for(i=0;i<10;i++)
    {
        printf("please enter number %d: ",i);
        scanf("%d",&num);
        sum += i;
    }
    
    printf("\nSum= %d ",sum);
    printf("\n Average= %d",(float)sum/10);
}
