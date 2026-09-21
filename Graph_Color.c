#include <stdio.h>
#include <stdbool.h>

int graph[20][20];
int color[20];
int n, m;

bool isSafe(int vertex, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && color[i] == c)
            return false;
    }

    return true;
}

bool graphColoring(int vertex)
{
    if (vertex == n)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(vertex, c))
        {
            color[vertex] = c;

            if (graphColoring(vertex + 1))
                return true;

            color[vertex] = 0;
        }
    }

    return false;
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    if (graphColoring(0))
    {
        printf("Graph can be colored using %d colors.\n", m);
        printf("Vertex\tColor\n");

        for (int i = 0; i < n; i++)
            printf("%d\t%d\n", i + 1, color[i]);
    }
    else
    {
        printf("Graph cannot be colored using %d colors.\n", m);
    }

    return 0;
}