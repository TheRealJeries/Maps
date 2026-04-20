//
//  stack.h
//  Maps
//
//  Created by Jeries Dababneh on 4/18/26.
//
#ifndef __stack_h__
#define __stack_h__

#include <stdbool.h>
#include "../node/node.h"

typedef struct stack_el_struct {
    node_type *node;
    struct stack_el_struct *next;
} stack_el_type;

typedef struct {
    stack_el_type *head;
} stack_type;

stack_type *create_stack(void);
void push(stack_type *stack, node_type *node);
node_type *pop(stack_type *stack);
bool isEmpty(stack_type *stack);

#endif
