

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removals(vector<int> &arr, int k)
    {
        int n = arr.size();
        int count = 0;
        sort(arr.begin(), arr.end());

        int i = 0;
        int j = 0;
        int maxSize = 0;
        while (j < n)
        {
            if (arr[j] - arr[i] <= k)
                j++;
            else if (i < j)
                i++;
            maxSize = max(maxSize, j - i);
        }
        return n - maxSize;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        int ans = ob.removals(arr, k);

        cout << ans << endl;
    }
}

// } Driver Code Ends