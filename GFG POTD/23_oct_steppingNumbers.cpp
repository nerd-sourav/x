#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int num, int n, int m, int &count)
    {
        if (num > m)
            return;
        int last_digit = num % 10;
        if (num >= n and num <= m)
            count++;
        if (last_digit != 0)
        {
            dfs(10 * num + (last_digit - 1), n, m, count);
        }
        if (last_digit != 9)
        {
            dfs(10 * num + (last_digit + 1), n, m, count);
        }
    }
    int steppingNumbers(int n, int m)
    {
        int count = 0;
        if (n == 0)
            count++;
        for (int i = 1; i <= 9; i++)
        {
            dfs(i, n, m, count);
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << obj.steppingNumbers(n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends