#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int node, int **adj, int *adjSize, bool *visited) {
    visited[node] = true;
    for (int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs(next, adj, adjSize, visited);
        }
    }
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    int **adj = malloc(n * sizeof(int*));
    int *adjSize = calloc(n, sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    for (int i = 0; i < n; i++) {
        adj[i] = malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    bool *visited = calloc(n, sizeof(bool));
    dfs(source, adj, adjSize, visited);

    bool result = visited[destination];

    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(adjSize);
    free(visited);

    return result;
}
