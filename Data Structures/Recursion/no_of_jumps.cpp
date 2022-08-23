#include <bits/stdc++.h>
using namespace std;

int jumps(int n)
{
    if (n < 0)
        return 0;
    if (n == 1 || n == 0)
        return 1;

    return jumps(n - 1) + jumps(n - 2) + jumps(n - 3);
}
// changes made
// changes
// changes made
// changes made
// chanegs made
// changes made
// changes made4
/// changes made
int main()
{
    int ans = jumps(4);
    cout << ans;
    return 0;
}