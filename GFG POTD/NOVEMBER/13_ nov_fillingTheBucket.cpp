
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalWays(int n, vector<int> capacity)
    {
        // code here
        long ans = 1;
        long mod = 1000000007;
        sort(capacity.begin(), capacity.end());
        for (int i = 0; i < n; i++)
        {
            ans = (ans * (capacity[i] - i)) % mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> capacity(n);
        for (int i = 0; i < n; i++)
            cin >> capacity[i];
        Solution ob;
        int ans = ob.totalWays(n, capacity);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends