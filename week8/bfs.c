#include <stdio.h>

int g[100][100], vis[100], n;

int main() {
    int e, u, v, start;
    int q[100], f = 0, r = 0;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter each edge (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("BFS Order: ");

    q[r++] = start;
    vis[start] = 1;

    while (f < r) {
        u = q[f++];
        printf("%d ", u);
        for (v = 0; v < n; v++) {
            if (g[u][v] && !vis[v]) {
                vis[v] = 1;
                q[r++] = v;
            }
        }
    }

    return 0;
}
