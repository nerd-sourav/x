#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr, i, n;
    printf("Enter the size : ");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
    printf("Enter the elements");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }
    printf("Enter updated n: ");
    scanf("%d", &n);
    int *ptr1 = (int *)realloc(ptr, n * sizeof(int));
    printf("Previous Address: %d New Address: %d", ptr, ptr1);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(ptr + i));
    }
    free(ptr1);
}