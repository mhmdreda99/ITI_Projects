#include <stdio.h>

int Get_Max( void );
// global var .
int n1 , n2 ;

int main ()
{
    printf (" Please enter number1 : ");
    scanf("%d",&n1);
    printf (" Please enter number2 : ");
    scanf("%d",&n2);
    printf (" Max = %d",Get_Max());
    
}
int Get_Max (void)
{
    if (n1>n2)
    {
        return n1 ;
    }
    else
    {
        return n2;
    }
}