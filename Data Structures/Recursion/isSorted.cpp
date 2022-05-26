#include <bits/stdc++.h>
#include <cmath>
using namespace std;

bool isSorted(int arr[], int index, int n)
{
    if (index == n)
        return true;
    if (arr[index] < arr[index - 1])
        return false;

    return isSorted(arr, index + 1, n);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = isSorted(arr, 1, n);
    cout << ans;
    return 0;
}
