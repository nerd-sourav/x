#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int add(int *arr, int index, int size)
{
    if (size == 1)
    {
        return arr[0];
    }
    if (size == 0)
    {
        return 0;
    }
    int ans = arr[index] + add(arr + 1, index + 1, size - 1);

    return ans;
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
    int ans = add(arr, 0, n);
    cout << ans;
    return 0;
}
