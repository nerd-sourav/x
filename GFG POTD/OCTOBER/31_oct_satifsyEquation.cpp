#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> satisfyEqn(int A[], int N)
    {
        // code here
        unordered_map<int, pair<int, int>> m;
        vector<vector<int>> ans;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                int sum = A[i] + A[j];
                if (m.find(sum) != m.end())
                {
                    pair<int, int> p = m[sum];
                    if (i != p.first && i != p.second && j != p.first && j != p.second)
                    {
                        ans.push_back({p.first, p.second, i, j});
                    }
                }

                else
                    m[sum] = {i, j};
            }
        }
        if (ans.size() == 0)
            return {-1, -1, -1, -1};
        sort(ans.begin(), ans.end());
        return ans[0];
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
        int A[N];

        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A, N);

        cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << " " << ptr[3] << endl;
    }
    return 0;
}
// } Driver Code Ends