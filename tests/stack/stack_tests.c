//
//  test.c
//  Maps
//
//  Created by Jeries Dababneh on 4/19/26.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../stack/stack.h"
#include "../common/common.h"

int test_create_stack(void) {
    stack_type *stack = create_stack();
    assert(__func__, stack != NULL);
    assert(__func__, stack->head == NULL);
    assert(__func__, stack->num_elements == 0);
    return 1;
}

int main(void) {
    test_create_stack();
    return 0;
}


