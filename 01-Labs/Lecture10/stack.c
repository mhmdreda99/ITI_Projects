/**
 * @file stack.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief Stack array based impelmentations 
 * @version 0.1
 * @date 2023-07-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
struct stack {
    int data[100];
    int top;
};

// Initialize the stack
void init_stack(struct stack *s) {
    s->top = -1;
}

// Push an element onto the stack
void push(struct stack *s, int data) {
    s->data[++s->top] = data;
}

// Pop an element from the stack
int pop(struct stack *s) {
    return s->data[s->top--];
}

// Check if the stack is empty
int is_empty(struct stack *s) {
    return s->top == -1;
}

// Check if the stack is full
int is_full(struct stack *s) {
    return s->top == 99;
}

// Print the stack
void print_stack(struct stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    // Initialize the stack
    struct stack s;
    init_stack(&s);

    // Push some elements onto the stack
    push(&s, 10);
    push(&s, 9);
    push(&s, 8);
    push(&s, 7);
    push(&s, 6);
    push(&s, 5);
    push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
    // Print the stack
    print_stack(&s);

    // Pop an element from the stack
    int popped_element = pop(&s);

    // Print the popped element
    printf("Popped element: %d\n", popped_element);

    // Print the stack again
    print_stack(&s);

    return 0;
}