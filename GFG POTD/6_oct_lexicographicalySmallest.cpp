//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    string lexicographicallySmallest(string S, int k)
    {
        // code here
        class Solution
        {
        public:
            string lexicographicallySmallest(string S, int k)
            {
                // code here
                int n = S.size();
                int a = n & (n - 1);
                // correct the size
                if (a == 0)
                    k /= 2;
                else
                    k *= 2;
                if (k >= n)
                    return "-1";

                stack<char> s;
                for (int i = 0; i < n; i++)
                {
                    char ch = S[i];
                    while (s.size() > 0 && k > 0 && s.top() > ch)
                    {
                        s.pop();
                        k--;
                    }
                    s.push(ch);
                }
                while (s.size() > 0 && k > 0)
                {
                    s.pop();
                    k--;
                }
                string ans = "";
                while (s.size() > 0)
                {
                    ans = ans + s.top();
                    s.pop();
                }
                reverse(ans.begin(), ans.end());
                return ans;
            }
        };
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}

// } Driver Code Ends