#include <stdio.h>

int g[100][100], vis[100], n;

int main() {
    int e, u, v, start;
    int stack[100], top = -1;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter each edge (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("DFS Order: ");

    stack[++top] = start;

    while (top != -1) {
        u = stack[top--];
        if (!vis[u]) {
            vis[u] = 1;
            printf("%d ", u);
            for (v = n - 1; v >= 0; v--)
                if (g[u][v] && !vis[v])
                    stack[++top] = v;
        }
    }

    return 0;
}
