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
#include "../stack/stack.h"

graph_type *convert_to_graph(int **adjacency_matrix, unsigned matrix_size) {
    graph_type *graph = malloc(sizeof(graph_type));
    FILE *fd = fopen("City Names","r");
    char buffer[MAX_NAME_LEN+1] = {0};
    int u, v;
    if (!graph) {
        printf("%s: ERROR - Allocating %zu bytes\n", __func__, sizeof(graph));
        return graph;
    }

    if (!fd) {
        printf("%s: ERROR - Opening file\n", __func__);
        free(graph);
        return NULL;
    }
    
    graph->num_nodes = matrix_size;
    graph->nodes = calloc(matrix_size, sizeof(node_type *));
    if (!graph->nodes) {
        free(graph);
        graph = NULL;
        return graph;
    }

    for (u = 0; u < matrix_size; u++) {
        // Create node u if it doesn't exist yet.
        if (!graph->nodes[u]) {
            fgets(buffer, MAX_NAME_LEN, fd);
            graph->nodes[u] = create_node(buffer, u);
            if (!graph->nodes[u]) {
                printf("%s: ERROR - creating node for %s\n", __func__, buffer);
                return NULL;
            }
        }
        for (v = 0; v < matrix_size; v++) {
            if (adjacency_matrix[u][v] > 0) {
                /*
                 * If u is not v, and there is an edge from u to v
                 * Create v if it doesn't exist yet
                 */
                if (!graph->nodes[v]) {
                    fgets(buffer, MAX_NAME_LEN, fd);
                    graph->nodes[v] = create_node(buffer, v);
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

void visit(node_type *node, bool *visited) {
    visited[node->index] = true;
}

void explore(node_type *node, stack_type *stack, bool *visited) {
    neigh_type *neigh = node->neighs;
    while (neigh) {
        if (!visited[neigh->node->index]) {
            push(stack, neigh->node);
        }
        neigh=neigh->next;
    }
}

bool dfs(graph_type *graph, node_type *from, node_type *to) {
    stack_type stack = {0};
    bool *visited = calloc(graph->num_nodes, sizeof(bool));
    node_type *node = NULL;
    if (!graph || !from || !to) {
        printf("%s: ERROR - NULL args", __func__);
        return false;
    }
    
    node = from;
    push(&stack, node);
    while(!isEmpty(&stack)) {
        node = pop(&stack);
        if (node->index == to->index) {
            while (!isEmpty(&stack)) {
                pop(&stack);
            }
            free(visited);
            return true;
        }
        visit(node, visited);
        explore(node, &stack, visited);
    }
    free(visited);
    return false;
}

void print_graph(graph_type *graph) {
    neigh_type *neigh;
    node_type *node;
    for (int i = 0; i < graph->num_nodes; i++) {
        node = graph->nodes[i]; 
        printf("%s neighbors:\n", node->name);
        neigh = node->neighs;
	printf("\t");
        while (neigh) {
            if (neigh->next) {
                printf("%s(%d) -> ", neigh->node->name, neigh->cost);
            } else {
                printf("%s(%d)\n", neigh->node->name, neigh->cost);
            }
            neigh=neigh->next;
        }
    }
}
