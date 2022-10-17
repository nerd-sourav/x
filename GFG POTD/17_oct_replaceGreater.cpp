

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution
{
public:
    vector<int> findLeastGreater(vector<int> &arr, int n)
    {
        vector<int> ans(n, 0);
        set<int> s;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s.size() == 0)
                ans[i] = -1;

            else if (s.size() > 0)
            {
                // find upper bound
                auto it = s.upper_bound(arr[i]);

                // 2 case possible

                // ele present
                if (it != s.end())
                    ans[i] = *it;
                else
                    ans[i] = -1;
            }
            // insert
            s.insert(arr[i]);
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.findLeastGreater(arr, n);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends