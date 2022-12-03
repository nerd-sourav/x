//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int k, vector<int> &stalls)
    {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int l = 0, r = stalls[n - 1] - stalls[0];
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cow = 1;
            int last = stalls[0];
            for (int i = 1; i < n; i++)
            {
                if (stalls[i] - last >= mid)
                {
                    cow++;
                    last = stalls[i];
                }
            }
            if (cow >= k)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends