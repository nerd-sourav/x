//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countTriplets(vector<int> nums)
    {
        // Code here.
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int left = 0;
            int right = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    left++;
            }
            for (int k = n - 1; k > i; k--)
            {
                if (nums[k] > nums[i])
                    right++;
            }
            count += left * right;
        }
        return count;
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
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.countTriplets(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends