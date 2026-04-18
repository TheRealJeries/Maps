//
//  node.c
//  Maps
//
//  Created by Jeries Dababneh on 4/15/26.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"

void strip(char *str) {
    int i = strlen(str)-1;
    while (str[i] == '\n') {
        str[i] = '\0';
        i--;
    }
}

node_t *create_node(const char *name) {
    node_t *node = malloc(sizeof(node_t));
    if (!node) {
        printf("%s: ERROR - Allocating %zu bytes\n", __func__, sizeof(node_t));
        return NULL;
    }
    
    if (!name) {
        printf("%s: ERROR - NULL passed as name\n", __func__);
        free(node);
        return NULL;
    }
    strip(name);
    node->name_len = strlen(name);
    node->name_len = node->name_len > MAX_NAME_LEN ? MAX_NAME_LEN : node->name_len;
    node->name = malloc(sizeof(char) * (node->name_len+1));
    strncpy(node->name, name, node->name_len);
    node->name[node->name_len] = '\0';
    node->neighs = NULL;

    return node;
}

/*
 * Adds neighbor neigh to node node.
 */
int add_neigh(node_t *node, node_t *neigh_node, int cost) {
    int res = 1;
    neigh_t *neigh = NULL;
    if (!node) {
        printf("%s: ERROR - NULL passed as node\n", __func__);
        return res;
    }
    
    if (!neigh_node) {
        printf("%s: ERROR - NULL passed as neigh_node\n", __func__);
        return res;
    }

    neigh = malloc(sizeof(neigh_t));
    if (!neigh) {
        printf("%s: ERROR - Allocating %zu bytes", __func__, sizeof(neigh_t));
        return res;
    }
    
    neigh->node = neigh_node;
    neigh->next = node->neighs;
    neigh->cost = cost;
    node->neighs = neigh;

    res = 0;
    return res;
}

void destroy(node_t *node) {
    // clean up?
}
