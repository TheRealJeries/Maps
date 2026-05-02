//
//  graph.h
//  Maps
//
//  Created by Jeries Dababneh on 4/15/26.
//

#ifndef __graph_h__
#define __graph_h__

#include <stdbool.h>
#include "../stack/stack.h"
#include "../node/node.h"

typedef struct {
    node_type **nodes;
    unsigned num_nodes;
} graph_type;

graph_type *convert_to_graph(int **adjacency_matrix, unsigned gridSize);

void emptyStack(stack_type *stack);
bool dfs(graph_type *graph, node_type *from, node_type *to);
void explore(node_type *node, stack_type *stack, bool *visited, int *last_visited);
void visit(node_type *node, bool *visited);
void print_graph(graph_type *graph);
#endif
