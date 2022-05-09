#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);
        printArray(arr, n);
    }
}
void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
            printArray(arr, n);
        }
        printf("\n");
    }
}

int main()
{
    int arr[] = {12, 43, 1, 53, 23, 2, 75};
    int n = sizeof(arr) / sizeof(arr[0]);
    // selectionSort(arr, n);
    bubbleSort(arr, n);
    // printArray(arr, n);
    return 0;
}