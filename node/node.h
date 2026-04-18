//
//  node.h
//  Maps
//
//  Created by Jeries Dababneh on 4/15/26.
//
#ifndef __node_h__
#define __node_h__

#define MAX_NAME_LEN 128

struct node_s; // forward declaration

typedef struct neigh_s {
    int cost;
    struct node_s *node;
    struct neigh_s *next;
} neigh_t;

typedef struct node_s {
    char *name;
    size_t name_len;
    neigh_t *neighs;
} node_t;

node_t *create_node(const char *name);
int add_neigh(node_t *node, node_t *neigh, int cost);

#endif
