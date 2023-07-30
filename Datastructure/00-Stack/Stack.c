#include "Stack.h"
/**
 * @brief this fuction intailize the stack pointer
 *
 * @param mystack is a pointer to the stack
 * @return return_status_t status of the intializtion fuction process
 */
return_status_t stack_init(stack_t *mystack)
{
    return_status_t ret = RET_NOK;
    // validate the pointer address
    if (NULL == mystack)
    {
        ret = RET_NOK;
    }
    else
    {
        mystack->stackptr = -1;
        ret = RET_OK;
    }

    return ret;
}

/**********************Helper Fucntions *******************************/

/**
 * @brief
 *
 * @param mystack is a pointer to the stack
 * @return stack_status_t status of the full fuction process
 */
static stack_status_t stack_full(stack_t *mystack)
{
    if (mystack->stackptr == STACK_MAX_SIZE - 1)
    {
        return STACK_FULL;
    }
    else
    {
        return STACK_NOT_FULL;
    }
}
/**
 * @brief this function validate the status of the stack
 *
 * @param mystack is a pointer to the stack
 * @return stack_status_t status of the empty fuction process
 */
static stack_status_t stack_empty(stack_t *mystack)
{
    if (mystack->stackptr == -1)
    {
        return STACK_EMPTY;
    }
    else
    {
        return STACK_NOT_FULL;
    }
}

/**
 * @brief
 *
 * @param mystack
 * @param value store the value to be pushed to stack 
 * @return return_status_t
 */
return_status_t stack_push(stack_t *mystack, u32 value)
{
    return_status_t ret = RET_NOK;
    // before push validate if the stack is not full
    // Validate if the stack pointer is not pointed to null
    if ((STACK_FULL == stack_full(mystack)) || (NULL == mystack))
    {
        #ifdef STACK_DEBUG
        printf("Failed Pushing to STACK");
        #endif // STACK_DEBUG
        ret = RET_NOK;
    }
    else
    {
        mystack->stackptr++;
        mystack->data[mystack->stackptr] = value;
        #ifdef STACK_DEBUG
        printf("Value (%d) has been added Successfully to STACK", value);
        #endif // STACK_DEBUG
        ret = RET_OK;
    }

    return ret;
}
/**
 * @brief
 *
 * @param mystack
 * @param value
 * @return return_status_t
 */
return_status_t stack_pop(stack_t *mystack, u32 *value)
{
    return_status_t ret = RET_NOK;

    if ((NULL == mystack) || (NULL == value) || (STACK_EMPTY == stack_empty(mystack)))
    {
        #ifdef STACK_DEBUG
        printf("Failed Pushing to STACK");
        #endif // STACK_DEBUG
        ret = RET_OK;
    }
    else
    {
        *value = mystack->data[mystack->stackptr];
        mystack->stackptr--;
        #ifdef STACK_DEBUG
        printf("Value (%d) has been popped Successfully from STACK", *value);
        #endif // STACK_DEBUG
        ret = RET_OK;
    }
    return ret;
}
/**
 * @brief
 *
 * @param mystack
 * @param value store the value from top
 * @return return_status_t
 */
return_status_t stack_top(stack_t *mystack, u32 *value)
{
    return_status_t ret = RET_NOK;
    // just want to copy the value of the top without moving it
     if ((NULL==mystack) || (NULL==value) || (STACK_EMPTY==stack_empty(mystack)){
        #ifdef STACK_DEBUG
        printf("FAILED get the TOP value from STACK");
        #endif // STACK_DEBUG
        ret = RET_NOK;

     }
     else{
        *value = mystack->data[mystack->stackptr];
        #ifdef STACK_DEBUG
        printf("STACK TOP value is %d", *value);
        #endif // STACK_DEBUG
        ret = RET_OK;
     }


     return ret;
}
/**
 * @brief
 *
 * @param mystack
 * @param stack_size store the stack size 
 * @return return_status_t 
 */
return_status_t stack_size(stack_t *mystack, u32 *stack_size)
{
    return_status_t ret = RET_NOK;
    if ((NULL==mystack) ){

        ret = RET_NOK; 
    }
    else
    {
        *stack_size = mystack->stackptr + 1;
        ret  =RET_OK;
    }
    
    return ret;

}
/**
 * @brief
 *
 * @param mystack pointer to the stack 
 * @return return_status_t reurn stack status 
 */
return_status_t stack_size(stack_t *mystack)
{
    return_status_t ret = RET_NOK;
    u32 stack_local_counter = 0 ;
    if ((NULL==mystack) || (STACK_EMPTY==stack_empty(mystack)){
       
       ret = RET_NOK

    }
    else{
        for (stack_local_counter= mystack->stackptr; stack_local_counter>STACK_MAX_SIZE ; stack_local_counter--)
        {
            printf("STACK ITEMS are : %d \n ", mystack->data[stack_local_counter]);
        }
        ret = RET_OK;

    }
    
    return ret;

}