# include <stdio.h> 

int main() 
{
    unsigned char result =12 ;
    unsigned int input ;

    
        printf("please enter the answer of 3 * 4 = ?");
        scanf("%d",&input);
    
    while (input!=result)
    {
        printf("Not correct , Please Try again :");
        scanf("%d",&input);

    }
        
    
    printf("\nThank you ");
    
}