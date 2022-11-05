#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxGroupSize(int arr[], int N, int K)
    {
        // code here
        vector<int> dp(K, 0);
        for (int i = 0; i < N; i++)
        {
            int rem = arr[i] % K;
            dp[rem] += 1;
        }

        int i = 1;
        int j = K - 1;
        int ans = 0;
        while (i < j)
        {
            ans += max(dp[i], dp[j]);
            i++;
            j--;
        }
        if ((i == j && dp[i] != 0))
        {
            ans += 1;
        }
        if (dp[0] > 0)
        {
            ans += 1;
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
        int N, K;

        cin >> N >> K;
        int arr[N];

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr, N, K) << endl;
    }
    return 0;
}
// } Driver Code Ends