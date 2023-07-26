# include <stdio.h> 

int main() 
{

    unsigned int i =1 ,input =0 ;
    printf(" Please Enter the number to show multiplication tabler :");
    scanf("%d",&input);
    while (i<=input)
    {

        printf("%d * %d = %d \n",input,i,input*i);
        i++;

    }
        
    
    
}
