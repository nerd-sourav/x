//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        // Code here.
        if (nums.size() % 2 == 1)
            return false;

        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i] % k]++;

        for (int i = 0; i < nums.size(); i++)
        {
            int rem = nums[i] % k;

            // if rem zero count should be even
            if (rem == 0)
            {
                if (mp[rem] % 2 == 1)
                    return 0;
            }
            else
            {
                if (mp[rem] != mp[k - rem])
                    return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
