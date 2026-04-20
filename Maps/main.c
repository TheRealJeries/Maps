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

int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned matrix_size;
    int i;
    int j;
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
    for (i = 0; i < matrix_size; i++) {
        adj_matrix[i] = malloc(sizeof(int) * matrix_size);
        if (!adj_matrix[i]) { //do clean up
            printf("%s: ERROR - Allocating %zu bytes\n", __func__, sizeof(int) * matrix_size);
            return EXIT_FAILURE;
        }
    }
    
    for (i = 0; i < matrix_size; i++) {
        for (j = 0; j < matrix_size; j++) {
            if (i == j) {
                adj_matrix[i][j] = 0;
            } else if (((rand()<<4)%3)) {
                adj_matrix[i][j] = rand()%MAX_COST;
            } else {
                adj_matrix[i][j] = -1;
            }
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    
    graph = convert_to_graph(adj_matrix, matrix_size);
    
    for (int i = 0; i < graph->num_nodes; i++) {
        node = graph->nodes[i];
        printf("%s neighbors:\n", node->name);
        neigh = node->neighs;
        while (neigh) {
            if (neigh->next) {
                printf("\t%s (%d) -", neigh->node->name, neigh->cost);
            } else {
                printf("\t%s (%d)\n", neigh->node->name, neigh->cost);
            }
            neigh=neigh->next;
        }
    }
    return EXIT_SUCCESS;
}
