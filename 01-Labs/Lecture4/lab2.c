#include <stdio.h>
#include "fun.c"


int main ()
{
    
    printf ("X before swap = %d\n",x);   
    printf ("y before swap = %d\n",y);   
    swap();
    printf ("******************************\n");
    printf ("X after swap = %d\n",x);   
    printf ("y after swap = %d\n",y);
 
    
}
