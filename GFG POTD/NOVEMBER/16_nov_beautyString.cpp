#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &dp)
    {
        int mx = INT_MIN;
        int mn = INT_MAX;
        for (int i = 0; i < dp.size(); i++)
        {
            if (dp[i] != 0)
            {
                mx = max(mx, dp[i]);
                mn = min(mn, dp[i]);
            }
        }
        return mx - mn;
    }
    int beautySum(string s)
    {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> dp(26, 0);
            for (int j = i; j < n; j++)
            {
                dp[s[j] - 'a'] += 1;
                int diff = solve(dp);
                ans = ans + diff;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends