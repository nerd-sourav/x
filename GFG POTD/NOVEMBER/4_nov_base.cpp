#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string baseEquiv(int n, int m)
    {
        // code here
        for (int i = 2; i <= 32; i++)
        {
            int digit = 0;
            int num = n;
            while (num > 0)
            {
                digit++;
                num = num / i;
            }
            if (digit == m)
                return "Yes";
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout << ob.baseEquiv(n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends