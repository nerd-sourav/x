#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int findSum(int a[], int n)
    {
        // code here.
        int maxm = INT_MIN, minm = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            maxm = max(maxm, a[i]);
            minm = min(minm, a[i]);
        }
        return (maxm + minm);
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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        int ans = ob.findSum(arr, n);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends