#include <bits/stdc++.h>
using namespace std;
int main()
{

    int a = 2;
    int b = 3;
    int ans = 0;
    while (b != 0)
    {
        b = b >> 1;
        ans++;
    }

    cout << ans;
    return 0;
}