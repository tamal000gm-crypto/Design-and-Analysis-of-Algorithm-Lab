#include <stdio.h>

#define MAX 10

int cost[MAX][MAX];
int visited[MAX];
int path[MAX];

int n;
int minCost = 99999;
int bestPath[MAX];
int totalTours = 0;

void tsp(int city, int count, int total)
{
    int i;
    int newCost;

    if (count == n)
    {
        newCost = total + cost[city][0];

        if (newCost != 0)
        {
            totalTours++;

            printf("Tour %d: ", totalTours);

            for (i = 0; i < n; i++)
                printf("%c -> ", 'A' + path[i]);

            printf("A  Cost = %d\n", newCost);

            if (newCost < minCost)
            {
                minCost = newCost;

                for (i = 0; i < n; i++)
                    bestPath[i] = path[i];
            }
        }

        return;
    }

    for (i = 0; i < n; i++)
    {
        if (!visited[i] && cost[city][i] != 0)
        {
            visited[i] = 1;
            path[count] = i;

            tsp(i, count + 1, total + cost[city][i]);

            visited[i] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("========================================\n");
    printf("   TRAVELLING SALESMAN PROBLEM (TSP)\n");
    printf("       USING BRANCH AND BOUND\n");
    printf("========================================\n");

    printf("\nEnter number of cities: ");
    scanf("%d", &n);

    if (n < 2 || n > MAX)
    {
        printf("Invalid number of cities.\n");
        return 0;
    }

    printf("\nEnter Cost Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\n========================================\n");
    printf("             COST MATRIX\n");
    printf("========================================\n");

    printf("     ");

    for (i = 0; i < n; i++)
        printf("%5c", 'A' + i);

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%5c", 'A' + i);

        for (j = 0; j < n; j++)
            printf("%5d", cost[i][j]);

        printf("\n");
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;
    path[0] = 0;

    printf("\n========================================\n");
    printf("       ALL POSSIBLE VALID TOURS\n");
    printf("========================================\n");

    tsp(0, 1, 0);

    printf("\n========================================\n");
    printf("          TOTAL VALID TOURS\n");
    printf("========================================\n");

    printf("Total Valid Tours = %d\n", totalTours);

    printf("\n========================================\n");
    printf("             FINAL RESULT\n");
    printf("========================================\n");

    printf("Optimal Tour: ");

    for (i = 0; i < n; i++)
        printf("%c -> ", 'A' + bestPath[i]);

    printf("A\n");

    printf("Minimum Cost = %d\n", minCost);

    printf("========================================\n");

    return 0;
}