#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], n;

void dfs(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (int i = 0; i < n; i++)
        if (graph[vertex][i] && !visited[i])
            dfs(i);
}

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);
    for (i = 0; i < n; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    dfs(start);
    printf("\n");

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);
    for (i = 0; i < n; i++) visited[i] = 0;
    printf("BFS Traversal: ");
    bfs(start);
    printf("\n");

    return 0;
}
