
#include <bits/stdc++.h>
using namespace std;

int main()
{
    

    vector<int> a{5, 3, 2, 8, 4, 1};
    int n = a.size();
    int currSum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    // cout << sum << endl;
    sort(a.begin(), a.end());
    int i = n - 1;
    int count = 0;

    // for (int i = n - 2; i >= 0; i--)
    // {
    //     cout << a[i] << " ";
    // }

    while (i >= 0)
    {
        // cout << a[i] << " ";
        currSum += a[i];
        // cout << currSum << endl;
        if (sum - currSum > currSum)
        {
            i--;
            cout << "sum - currSum= " + (sum - currSum) << endl;
            count++;
        }
        else
        {
            cout << "else";
            cout << count;
        }
        i--;
    }

    return 0;
}
