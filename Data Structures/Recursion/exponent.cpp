#include <bits/stdc++.h>
using namespace std;
int num(int n)
{
    if (n <= 0)
        return 1;
    return 2 * num(n - 1);
}
int main()
{
    int n;
    cin >> n;
    int ans = num(n);
    cout << ans;
    return 0;
}