#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// int linearSearch(int arr[], int index, int n, int k)
// {

//     if (index == n)
//         return -1;x
//     if (n == 0)
//         return -1;

//     if (n == 1)//
//         return 0;

//     if (arr[index] == k)
//         return index;

//     return linearSearch(arr, index + 1, n, k);
// changes made
// changes made
// changes made
int linearSearch(int arr[], int n, int k)
{

    if (n == 0)
        return 0;
    if (arr[0] == k)
        return true;
    else
    {
        return linearSearch(arr + 1, n - 1, k);
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

    cout << "Enter Key" << endl;
    cin >> k;
    int ans = linearSearch(arr, n, k);
    cout << ans;
    return 0;
}
