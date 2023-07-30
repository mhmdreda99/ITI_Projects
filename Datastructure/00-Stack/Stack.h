/**
 * @file Stack.h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief This file contains all declarations for stack functions
 * @version 0.1
 * @date 2023-07-30
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "StdTypes.h"
#ifndef STACK_H_
#define STACK_H_

#define STACK_MAX_SIZE 5
#define STACK_DEBUG 

typedef struct stack
{
    u32 stackptr;
    u32 data[STACK_MAX_SIZE];

} stack_t;

typedef enum stack_status
{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NOT_FULL,

} stack_status_t;

/******************Functions Declarations*************************** */
return_status_t stack_init(stack_t *mystack);
return_status_t stack_push(stack_t *mystack, u32 value);
return_status_t stack_pop(stack_t *mystack, u32 *value);
return_status_t stack_top(stack_t *mystack, u32 *value);
return_status_t stack_size(stack_t *mystack , u32 *stack_size);
return_status_t stack_display(stack_t *mystack);

#endif