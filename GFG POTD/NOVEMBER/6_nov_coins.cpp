//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void solve(vector<int> &arr, vector<int> &ans, int target)
    {
        if (target <= 0)
            return;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > target)
                continue;
            else
            {
                ans.push_back(arr[i]);
                return solve(arr, ans, target - arr[i]);
            }
        }
    }
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> arr = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> ans;
        solve(arr, ans, N);
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
        int N;
        cin >> N;

        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for (auto u : numbers)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends