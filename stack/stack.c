//
//  stack.c
//  Maps
//
//  Created by Jeries Dababneh on 4/18/26.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

stack_type *create_stack(void) {
    stack_type *res = malloc(sizeof(stack_type));
    if (!res) {
        printf("%s: ERROR - Allocating %zu bytes", __func__, sizeof(stack_type));
        return res;
    }
    res->head = NULL;
    res->num_elements = 0;
    return res;
}

void push(stack_type *stack, node_type *node) {
    stack_el_type *stack_el = NULL;
    if (!stack || !node) {
        printf("%s: ERROR - NULL arg", __func__);
        return;
    }

    stack_el = malloc(sizeof(stack_el_type));
    if (!stack_el) {
        printf("%s: ERROR - Allocating %zu bytes", __func__, sizeof(stack_el_type));
        return;
    }
    
    stack_el->node = node;
    stack_el->next = stack->head;
    stack->head = stack_el;
}

node_type *pop(stack_type *stack) {
    stack_el_type *el = NULL;
    node_type *node =  NULL;
    if (!stack) {
        printf("%s: ERROR: NULL arg", __func__);
        return node;
    }
    
    el = stack->head;
    if (el) {
        node = el->node;
        stack->head = el->next;
        free(el);
        el->node = NULL;
        el->next = NULL;
    }
    return node;
}

bool isEmpty(stack_type *stack) {
    return (stack->head == NULL);
}
