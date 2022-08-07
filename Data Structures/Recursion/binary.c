#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int arr[], int start, int end, int key)
{
    // int start = 0;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else
        {
            if (arr[mid] < key)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}
// changes made
// changes made
// changes mades
// changes
// changes made
// changes made
// chanegs made.
// changes made

// changes made
int Bsearch(int arr[], int start, int end, int key)
{

    int mid = (start + end) / 2;

    if (start > end)
        return -1;
    if (arr[mid] == key)
        return mid;

    if (arr[mid] < key)
        Bsearch(arr, mid + 1, end, key);
    else
    {
        Bsearch(arr, start, mid - 1, key);
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 7;
    int ans = Bsearch(arr, 0, 10, key);
    printf("%d", ans);
    /* code */
    return 0;
}
