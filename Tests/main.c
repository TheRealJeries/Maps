//
//  main.c
//  Tests
//
//  Created by Jeries Dababneh on 4/20/26.
//

#include <stdlib.h>
#include <stdio.h>
#include "stack_tests/stack_tests.h"
#include "common/common.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    assert(__func__, stack_tests() == 0);
    return EXIT_SUCCESS;
}
