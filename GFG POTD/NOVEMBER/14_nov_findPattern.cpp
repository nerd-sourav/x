

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubsequences(string s, string w)
    {

        vector<int> dp(s.size(), 0);
        int i = 0, j = 0;
        int ans = 0;
        while (i < s.size())
        {
            if (s[i] == w[0] && dp[i] == 0)
            {
                s[i] = ' ';
                j = 1;
                int k = i + 1;
                while (j < w.size() && k < s.size())
                {
                    if (s[k] == w[j])
                    {
                        s[k] = ' ';
                        k++;
                        j++;
                    }
                    else
                        k++;
                }
                if (j == w.size())
                    ans++;
            }
            i++;
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S, W) << endl;
    }
    return 0;
}

// } Driver Code Ends