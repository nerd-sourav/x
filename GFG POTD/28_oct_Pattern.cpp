

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int NthTerm(int n)
    {
        // Code  here
        long ans = 1;
        long mod = 1000000007;
        for (int i = 1; i <= n; i++)
        {
            ans = ((ans * i) + 1) % mod;
            //  cout<<ans  <<endl;
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
        Solution obj;
        int ans = obj.NthTerm(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends