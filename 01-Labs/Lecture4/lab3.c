/**
 * @file lab3.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
int x=20 , y=10 ;

int swap ( void)
{
    x = x + y ;
    y = x - y ;
    x= x - y;
  
}
// global var .

int main ()
{
    
    printf ("X before swap = %d\n",x);   
    printf ("y before swap = %d\n",y);   
    swap();
    printf ("******************************\n");
    printf ("X after swap = %d\n",x);   
    printf ("y after swap = %d\n",y);
 
    
}
