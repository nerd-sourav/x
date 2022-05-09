#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // allocating the memory
    int *ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory not available");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
        // printf("%d", (ptr + i));
        // printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        // scanf("%d", ptr + i);
        printf("%d", *(ptr + i));
        printf("\n");
    }
}