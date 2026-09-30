#include <stdio.h>

int main()
{
    int n, i, key;
    int found = -1;
    int arr[100];
    
    printf("Enter the number of element");
    scanf("%d", &n);
    printf("Enter the elements");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = i;
            break;
        }
    }

    if (found != -1)
    {
        printf("Element Found at position %d\n", found + 1);
    }
    else
    {
        printf(" Element  Not Found\n");
    }

    return 0;
}