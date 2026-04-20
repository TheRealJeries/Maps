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

typedef struct neigh_struct {
    int cost;
    struct node_struct *node;
    struct neigh_struct *next;
} neigh_type;

typedef struct node_struct {
    char *name;
    int index;
    size_t name_len;
    neigh_type *neighs;
} node_type;

node_type *create_node(const char *name, int index);
int add_neigh(node_type *node, node_type *neigh, int cost);

#endif
