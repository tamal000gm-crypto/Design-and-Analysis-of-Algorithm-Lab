#include <stdio.h>

int binarySearchIncreasing(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearchDecreasing(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int firstOccurrence(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return ans;
}

int lastOccurrence(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] > key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return ans;
}

int main()
{
    int n, key, choice, i, index, valid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nChoose Array Type:\n");
    printf("1. Increasing\n");
    printf("2. Decreasing\n");
    printf("3. Non-Decreasing\n");
    printf("4. Non-Increasing\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    do
    {
        valid = 1;

        printf("\nEnter array elements:\n");
        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        switch(choice)
        {
            case 1: // Increasing
                for(i = 0; i < n - 1; i++)
                {
                    if(arr[i] > arr[i + 1])
                    {
                        valid = 0;
                        break;
                    }
                }
                break;

            case 2: // Decreasing
                for(i = 0; i < n - 1; i++)
                {
                    if(arr[i] < arr[i + 1])
                    {
                        valid = 0;
                        break;
                    }
                }
                break;

            case 3: // Non-Decreasing
                for(i = 0; i < n - 1; i++)
                {
                    if(arr[i] > arr[i + 1])
                    {
                        valid = 0;
                        break;
                    }
                }
                break;

            case 4: // Non-Increasing
                for(i = 0; i < n - 1; i++)
                {
                    if(arr[i] < arr[i + 1])
                    {
                        valid = 0;
                        break;
                    }
                }
                break;

            default:
                printf("Invalid Choice!\n");
                return 0;
        }

        if(valid == 0)
        {
            printf("\nArray is not sorted according to your choice.\n");
            printf("Try Again!\n");
        }

    } while(valid == 0);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    switch(choice)
    {
        case 1:
            index = binarySearchIncreasing(arr, n, key);
            break;

        case 2:
            index = binarySearchDecreasing(arr, n, key);
            break;

        case 3:
            index = firstOccurrence(arr, n, key);
            break;

        case 4:
            index = lastOccurrence(arr, n, key);
            break;
    }

    if(index != -1)
        printf("\nElement found at index %d\n", index);
    else
        printf("\nElement not found.\n");

    return 0;
