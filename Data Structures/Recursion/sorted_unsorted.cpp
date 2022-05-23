#include <iostream>
#include <cmath>
using namespace std;

int check(int arr[], int index, int n)
{
    if (index == n)
    {
        return 1;
    }
    if (arr[index] < arr[index - 1])
    {
        return -1;
    }

    // return -1;
    return check(arr, index + 1, n);

    // return 1;
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
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    int ans = check(arr, 1, n);
    cout << ans;
    return 0;
}
