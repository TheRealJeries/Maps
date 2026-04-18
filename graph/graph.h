//
//  graph.h
//  Maps
//
//  Created by Jeries Dababneh on 4/15/26.
//

#ifndef __graph_h__
#define __graph_h__

#include "../node/node.h"

typedef struct {
    node_t **nodes;
    unsigned num_nodes;
} graph_t;

graph_t *convert_to_graph(int **adjacency_matrix, unsigned gridSize);

#endif
