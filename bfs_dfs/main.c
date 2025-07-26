#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20

int V, E, G[SIZE][SIZE], visited[SIZE];
char vertices[SIZE];

int getIndex(char c)
{
    for (int i = 0; i < V; i++)
    {
        if (vertices[i] == c)
            return i;
    }
    return -1;
}

void DFS(int i)
{
    visited[i] = 1;
    printf("%c -> ", vertices[i]);
    for (int j = 0; j < V; j++)
    {
        if (G[i][j] == 1 && visited[j] == 0)
            DFS(j);
    }
}

void BFS(int start)
{
    int queue[SIZE], front = 0, rear = 0, i, current;
    for (i = 0; i < V; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        current = queue[front++];
        printf("%c -> ", vertices[current]);
        for (i = 0; i < V; i++)
        {
            if (G[current][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, idx1, idx2;
    char v1, v2, source;

    printf("\t\tGraphs with Character Vertices\n");
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter labels for vertices (A-Z):\n");
    for (i = 0; i < V; i++) {
        printf("Vertex %d: ", i + 1);
        scanf(" %c", &vertices[i]);
        vertices[i] = toupper(vertices[i]);
    }
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            G[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (i = 0; i < E; i++)
    {
        printf("Enter edge %d (format: A B): ", i + 1);
        scanf(" %c %c", &v1, &v2);
        idx1 = getIndex(toupper(v1));
        idx2 = getIndex(toupper(v2));
        if (idx1 != -1 && idx2 != -1)
        {
            G[idx1][idx2] = 1;
            G[idx2][idx1] = 1;
        }
        else
        {
            printf("Invalid vertex label.\n");
            i--;
        }
    }

    printf("\nAdjacency Matrix:\n");
    printf("    ");
    for (i = 0; i < V; i++)
        printf(" %c ", vertices[i]);
    printf("\n");
    for (i = 0; i < V; i++)
    {
        printf(" %c |", vertices[i]);
        for (j = 0; j < V; j++)
            printf(" %d ", G[i][j]);
        printf("\n");
    }

    printf("\nEnter source vertex for DFS and BFS: ");
    scanf(" %c", &source);
    int srcIndex = getIndex(toupper(source));
    if (srcIndex == -1)
    {
        printf("Invalid source vertex.\n");
        return 1;
    }

    printf("\nDFS Traversal: ");
    for (i = 0; i < V; i++) visited[i] = 0;
    DFS(srcIndex);

    printf("\nBFS Traversal: ");
    BFS(srcIndex);

    printf("\n");

    return 0;
}
