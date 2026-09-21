#include <stdio.h>

int set[20], subset[20];
int n, target;

void sumOfSubsets(int index, int currentSum)
{
    if (currentSum == target)
    {
        printf("{ ");

        for (int i = 0; i < n; i++)
        {
            if (subset[i])
                printf("%d ", set[i]);
        }

        printf("}\n");
        return;
    }

    if (index == n || currentSum > target)
        return;

    subset[index] = 1;
    sumOfSubsets(index + 1, currentSum + set[index]);

    subset[index] = 0;
    sumOfSubsets(index + 1, currentSum);
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d:\n", target);

    sumOfSubsets(0, 0);

    return 0;
}