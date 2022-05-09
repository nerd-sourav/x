#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 12345;
    int digits = 0;
    int y = n;
    int r = 0;
    int q = 0;
    while (y >= 1)
    {
        digits++;
        y = y / 10;
    }

    return 0;
}