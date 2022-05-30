#include <bits/stdc++.h>
using namespace std;
// changes made
int power(int base, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    if (pow == 1)
    {
        return base;
    }
    int ans = power(base, pow / 2);

    if (pow % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return pow * ans * ans;
    }
}

int main()
{
    int n, m;
    n = 5, m = 3;
    int ans = power(n, m);
    cout << ans;
    return 0;
}