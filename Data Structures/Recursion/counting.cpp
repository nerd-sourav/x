#include <bits/stdc++.h>
using namespace std;
void counting(int n)
{
    if (n <= 0)
    {
        return;
    }
    cout << n << " ";
    counting(n - 1);
}

void ascending(int n)
{
    if (n <= 0)
    {
        return;
    }

    ascending(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    counting(n);
    cout << endl;
    ascending(n);

    return 0;
}