//
//  test.c
//  Maps
//
//  Created by Jeries Dababneh on 4/19/26.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "stack.h"
#include "common.h"

void test_empty_stack(void) {
    stack_type *stack = create_stack();
    assert(__func__, stack != NULL);
    assert(__func__, stack->head == NULL);
    assert(__func__, isEmpty(stack) == true);
    free(stack);
}

void test_nonempty_stack(void) {
    stack_type *stack = create_stack();
    node_type node = {0};
    node.name = "Test";
    node.name_len = 4;
    assert(__func__, stack != NULL);
    push(stack, &node);

    assert(__func__, stack->head != NULL);
    assert(__func__, isEmpty(stack) == false);
    free(stack);
}

void test_pop_empty_stack(void) {
    stack_type *stack = create_stack();
    assert(__func__, stack != NULL);
    assert(__func__, stack->head == NULL);
    assert(__func__, pop(stack) == NULL);
    free(stack);
}



int stack_tests(void) {
    test_empty_stack();
    test_nonempty_stack();
    test_pop_empty_stack();
    printf("Tests succeeded!\n");
    return 0;
}


