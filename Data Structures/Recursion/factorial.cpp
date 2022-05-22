#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 1)
    { // base condition reached
        return 1;
    }

    int f = n;
    f = f * factorial(n - 1);
    return f;
}

int main()
{

    int n;
    cin >> n;
    factorial(n);
    int ans = factorial(n);
    cout << ans;
    return 0;
}