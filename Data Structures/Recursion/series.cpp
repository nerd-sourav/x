#include <bits/stdc++.h>
using namespace std;

vector<int> print(int n, int m, int k, vector<int> v)
{

    if (n < -1 * m || n == 0)
    {

        return v;
    }

    v.push_back(n);

    return print(n - k, m, k, v);
}

int main()
{
    // vector<int> v;
    vector<int> v = print(5, 5, 2, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "d";
    }
}