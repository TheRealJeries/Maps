//
//  common.c
//  Maps
//
//  Created by Jeries Dababneh on 4/19/26.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void assert(const char *test_name, bool expr) {
    if (!expr) {
        printf("%s failed\n", test_name);
        exit(1);
    }
}
