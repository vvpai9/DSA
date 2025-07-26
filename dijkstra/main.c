#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6 // Number of vertices

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index = -1, v;

    for (v = 0; v < V; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[])
{
    int i;
    printf("\nVertex \t Distance from Source\n");
    for (i = 0; i < V; i++)
        printf("%c \t\t %d\n", 'A' + i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V], i, count, u, v;       // dist[i] holds shortest distance from src to i
    bool sptSet[V];    // true if vertex i is included in shortest path tree

    for (i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    printf("\nStep-by-step distance updates:\n");
    for (count = 0; count < V - 1; count++)
    {
        u = minDistance(dist, sptSet);
        sptSet[u] = true;

        printf("After visiting %c:\n", 'A' + u);
        for (v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
            printf("Distance to %c: %d\n", 'A' + v, dist[v]);
        }
        printf("\n");
    }

    printSolution(dist);
}

int main()
{
    int graph[V][V] = {
        // A  B  C  D  E  F
        { 0, 7, 9, 0, 0,14 }, // A
        { 0, 0,10,15, 0, 0 }, // B
        { 0, 0, 0,11, 0, 2 }, // C
        { 0, 0, 0, 0, 6, 0 }, // D
        { 0, 0, 0, 0, 0, 9 }, // E
        { 0, 0, 0, 0, 0, 0 }  // F
    };

    char source;
    printf("Enter source vertex (A-F): ");
    scanf(" %c", &source);

    if (source < 'A' || source > 'F')
    {
        printf("Invalid vertex! Enter between A and F.\n");
        return 1;
    }

    dijkstra(graph, source - 'A');
    return 0;
}
