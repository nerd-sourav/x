#include <bits/stdc++.h>
using namespace std;
int main()
{

    int a[] = {2, 4, 6, 8};
    int b[] = {1, 3, 5, 7, 10, 12};
    int c[] = {};
    int i = 0, j = 0, k = 0;
    int m = 4, n = 6;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < m)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j < n)
    {
        c[k] = b[j];
        k++;
        j++;
    }

    for (int o = 0; o < m + n; o++)
    {
        cout << c[o] << " ";
    }

    return 0;
}