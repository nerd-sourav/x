
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<int>> &ans, int target, int num, vector<int> &output)
    {
        if (target == 0)
        {
            ans.push_back(output);
            return;
        }
        if (num <= 0)
        {
            return;
        }

        if (num <= target)
        {
            output.push_back(num);
            solve(ans, target - num, num, output);
            output.pop_back();
        }
        solve(ans, target, num - 1, output);
    }

    vector<vector<int>> UniquePartitions(int n)
    {
        // Code here
        vector<vector<int>> ans;
        vector<int> output;

        solve(ans, n, n, output);
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<vector<int>> ans = ob.UniquePartitions(n);
        for (auto i : ans)
            for (auto j : i)
                cout << j << " ";
        cout << "\n";
    }
    return 0;
}
