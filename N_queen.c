#include <stdio.h>
#include <stdbool.h>

int board[20][20];
int n;

bool isSafe(int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(int row)
{
    if (row == n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            if (solveNQueens(row + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (solveNQueens(0))
    {
        printf("Solution:\n");

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", board[i][j]);

            printf("\n");
        }
    }
    else
    {
        printf("No solution exists.\n");
    }

    return 0;
}