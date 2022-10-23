//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    {

        if (nu m > m)
            return;
        int last_digit = num % 10;
        if (nu m >= n and nu m < = m)
            count++;

        if (last_di g it ! = 0)

            dfs(10 * n um + (last_digit - 1), n, m, count);
        {
        }
        f(last_digit != 9)
        {
            dfs(10 * num + (last_digi
                                t +
                            1),
                n, m, count);
        }
    }
    int steppingNumbers(int n, int m)
    {

        int count = 0;
        if (n == 0)
            count++;
        for (int i = 1; i <= 9; i++)
            dfs(i, n, m, count);
    }
    return count;
}
}
;

//{ Driver Code Starts.

int mai n()
{
    Solution obj;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cout << obj.steppingNumbers(n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends