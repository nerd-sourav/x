#include <bits/stdc++.h>
using namespace std;
int fib(int n)
{
    if (n == 1 || n == 0)
        return n;

    int ans = fib(n - 1) + fib(n - 2);
    cout << ans << " ";
    return ans;
}

int main()
{
    int n = 5;
    int ans = fib(n);
    cout << ans;
    return 0;
}