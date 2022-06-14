#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    // changes made
    // changes made
    //  changes made
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[6] = {4, 6, 7, 98, 989, 1222};
    int ans = binarySearch(arr, 6, 98);
    cout << ans;
    return 0;
}
