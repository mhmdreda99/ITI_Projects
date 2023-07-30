/**
 * @file main.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief this is the main application to test our stack functionality
 * @version 0.1
 * @date 2023-07-30
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

stack_t mystack1;
u32 stack_pop_item = 0;

int main()
{
    return_status_t ret = RET_NOK;

    ret = stack_init(&mystack1);
    if (RET_NOK == ret)
    {
        printf("Your stack failed to intialize.");
    }
    else
    {
        ret = stack_push(&mystack1, 11);
        ret = stack_push(&mystack1, 11);
        ret = stack_push(&mystack1, 11);
        ret = stack_push(&mystack1, 11);
        ret = stack_push(&mystack1, 11);
        ret = stack_push(&mystack1, 11);
        ret = stack_push(&mystack1, 11);
        ret = stack_pop(&mystack1, &stack_pop_item);
        printf("Stack poped element %i", stack_pop_item);
        u32 stack_top_val= 0 ;

        ret = stack_top(&mystack1,&stack_top_val);
        if (RET_OK == ret)
            printf("Stack top value = %d ",stack_top_val);

    }

    return 0;
}
