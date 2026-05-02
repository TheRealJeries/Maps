//
//  main.c
//  Maps
//
//  Created by Jeries Dababneh on 4/15/26.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "graph/graph.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

#define MAX_SIZE 100000
#define MAX_COST 50
#define SPARSITY 10 // means SPARSITY% chance of an edge existing

int main(int argc, const char * argv[]) {
    unsigned matrix_size;
    int u;
    int v;
    int **adj_matrix;
    node_type *node;
    neigh_type *neigh;
    graph_type *graph;
    srand((unsigned)time(NULL));
    printf("Grid size: ");
    scanf("%u", &matrix_size);

    if (matrix_size > MAX_SIZE) {
        printf("Too large! Max is %d\n ", MAX_SIZE);
        return EXIT_FAILURE;
    }
    
    adj_matrix = malloc(sizeof(int *) * matrix_size);
    if (!adj_matrix) {
        printf("%s: ERROR - Allocating %zu bytes\n ", __func__, sizeof(int *) * matrix_size);
        return EXIT_FAILURE;
    }
    for (u = 0; u < matrix_size; u++) {
        adj_matrix[u] = malloc(sizeof(int) * matrix_size);
        if (!adj_matrix[u]) { //do clean up
            printf("%s: ERROR - Allocating %zu bytes\n", __func__, sizeof(int) * matrix_size);
            return EXIT_FAILURE;
        }
    }
    
    for (u = 0; u < matrix_size; u++) {
        for (v = 0; v < matrix_size; v++) {
            if (u == v) {
                adj_matrix[u][v] = 0;
            } else if ((rand() % 100) < SPARSITY) {
                adj_matrix[u][v] = rand()%MAX_COST;
            } else {
                adj_matrix[u][v] = -1;
            }
            printf("%d ", adj_matrix[u][v]);
        }
        printf("\n");
    }
    
    graph = convert_to_graph(adj_matrix, matrix_size);
    print_graph(graph);

    for (u = 0; u < graph->num_nodes; u++) {
        for (v = 0; v < graph->num_nodes; v++) {
            if (dfs(graph, graph->nodes[u], graph->nodes[v])) {
                //printf("\tFound path from %s to %s\n", graph->nodes[u]->name, graph->nodes[v]->name);
            } else {
                //printf("\tDid not find path from %s to %s\n", graph->nodes[u]->name, graph->nodes[v]->name);
            }
        }
    }
    return EXIT_SUCCESS;
}
