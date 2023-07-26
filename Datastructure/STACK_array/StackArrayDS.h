
#ifndef STACK_ARRAY_DS_H
#define STACK_ARRAY_DS_H

#include <stdlib.h>
#include "Platform_Types.h"

typedef struct{
    void **StackArray;    /* Points to the array that allocated in the heap */
    sint32 ElementCount;  /* Has the actual number of elements in the stack */
    uint32 StackMaxSize;  /* Has the maximum number of elements in the stack */
    sint32 StackTop;      /* Has the index of the top element in the stack */
}Stack_t;

typedef enum{
    STACK_NOK = 0,     /* Stack operation not performed successfully */
    STACK_OK,          /* Stack operation performed successfully  */
    STACK_FULL,        /* Stack is full */
    STACK_EMPTY,       /* Stack is empty */
    STACK_NULL_POINTER /* NULL pointer passed to the Stack operations */
}StackStatus_t;

/**
  * @brief  This algorithm creates an empty stack by allocating the head
            structure and the array from dynamic memory.
  * @param  (maxSize) Stack maximum number of elements
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to the allocated stack in the heap
  */
Stack_t* CreateStack (uint32 maxSize, StackStatus_t *ret_status);

/**
  * @brief  This function releases all memory to the heap.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval NULL
  */
Stack_t* DestroyStack (Stack_t* stack_obj, StackStatus_t *ret_status);

/**
  * @brief This function pushes an item onto the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (itemPtr) pointer to be inserted
  * @retval Status returned while performing this operation
  */
StackStatus_t PushStack (Stack_t* stack_obj, void* itemPtr);

/**
  * @brief This function pops the item on the top of the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* PopStack (Stack_t* stack_obj, StackStatus_t *ret_status);

/**
  * @brief  This function retrieves the data from the top of the
            stack without changing the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* StackTop (Stack_t* stack_obj, StackStatus_t *ret_status);

/**
  * @brief  Returns number of elements in stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (stack_count) number of elements in stack.
  * @retval Status returned while performing this operation
  */
StackStatus_t StackCount (Stack_t* stack_obj, uint32 *stack_count);

#endif // STACK_ARRAY_DS_H
