//
//  graph.c
//  Maps
//
//  Created by Jeries Dababneh on 4/15/26.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../node/node.h"
#include "graph.h"

graph_t *convert_to_graph(int **adjacency_matrix, unsigned matrix_size) {
    graph_t *graph = malloc(sizeof(graph_t));
    FILE *fd = fopen("City Names","r");
    char buffer[MAX_NAME_LEN+1] = {0};
    int u, v;
    if (!graph) {
        printf("%s: ERROR - Allocating %zu bytes\n", __func__, sizeof(graph));
        return graph;
    }
    
    graph->num_nodes = matrix_size;
    graph->nodes = calloc(matrix_size, sizeof(node_t *));
    if (!graph->nodes) {
        free(graph);
        graph = NULL;
        return graph;
    }

    for (u = 0; u < matrix_size; u++) {
        // Create node u if it doesn't exist yet.
        if (!graph->nodes[u]) {
            fgets(buffer, MAX_NAME_LEN, fd);
            graph->nodes[u] = create_node(buffer);
            if (!graph->nodes[u]) {
                printf("%s: ERROR - creating node for %s\n", __func__, buffer);
                return NULL;
            }
        }
        for (v = 0; v < matrix_size; v++) {
            if (u != v && adjacency_matrix[u][v] > 0) {
                /*
                 * If u is not v, and there is an edge from u to v
                 * Create v if it doesn't exist yet
                 */
                if (!graph->nodes[v]) {
                    fgets(buffer, MAX_NAME_LEN, fd);
                    graph->nodes[v] = create_node(buffer);
                    if (!graph->nodes[v]) {
                        printf("%s: ERROR - creating node for %s\n", __func__, buffer);
                        return NULL;
                    }
                }

                if (add_neigh(graph->nodes[u], graph->nodes[v], adjacency_matrix[u][v])) {
                    printf("%s: ERROR - adding neighbor %s to %s failed\n", __func__,graph->nodes[v]->name, graph->nodes[u]->name);
                }
            }
        }
    }
    return graph;
}
