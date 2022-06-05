#include <bits/stdc++.h>
#include <cmath>
using namespace std;
// changes made

int binarySearch(int arr[], int start, int end, int key)
{
    if (start > end)
    {
        return 0;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == key)
    {
        return true;
    }
    if (arr[mid] > key)
    {
        // search left half
        return binarySearch(arr, start, mid - 1, key);
    }
    else
    {
        // search right half;
        return binarySearch(arr, mid + 1, end, key);
    }
}

int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;

    int ans = binarySearch(arr, 0, n - 1, k);
    cout << ans;

    return 0;
}
