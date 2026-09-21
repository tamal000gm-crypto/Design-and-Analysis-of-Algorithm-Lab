#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int color[MAX];
int n, m;

char *colorNames[] = {
    "Red", "Green", "Blue", "Yellow", "Orange",
    "Purple", "Pink", "Brown", "Cyan", "Magenta"
};

int isSafe(int vertex, int c)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && color[i] == c)
            return 0;
    }

    return 1;
}

int graphColoring(int vertex)
{
    int c;

    if (vertex == n)
        return 1;

    for (c = 0; c < m; c++)
    {
        if (isSafe(vertex, c))
        {
            color[vertex] = c;

            if (graphColoring(vertex + 1))
                return 1;

            color[vertex] = -1;
        }
    }

    return 0;
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    if (n > MAX || m > 10 || n <= 0 || m <= 0)
    {
        printf("Invalid input.\n");
        return 0;
    }

    printf("\nEnter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Display the adjacency matrix :\n") ;
    for(i = 0 ; i< n ; i++){
        for(j = 0 ; j < n ; j++){
            printf("%d ",graph[i][j]) ;
        }
        printf("\n") ;
    }

    for (i = 0; i < n; i++)
        color[i] = -1;

    if (graphColoring(0))
    {
        printf("\nGraph can be colored using %d colors.\n", m);

        printf("\nVertex Coloring:\n");

        for (i = 0; i < n; i++)
        {
            printf("Vertex %d -> %s\n",
                   i + 1, colorNames[color[i]]);
        }
    }
    else
    {
        printf("\nGraph cannot be colored using %d colors.\n", m);
    }

    return 0;
}