#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> leafNodes(int arr[], int n)
    {

        vector<int> ans;
        stack<int> stk;

        for (int i = 0, j = 1; j < n; i++, j++)
        {
            if (arr[i] > arr[j])
            {
                stk.push(arr[i]);
            }
            else
            {
                bool found = false;
                while (!stk.empty())
                {
                    if (arr[j] > stk.top())
                    {
                        stk.pop();
                        found = true;
                    }
                    else
                        break;
                }
                if (found)
                {
                    ans.push_back(arr[i]);
                }
            }
        }
        ans.push_back(arr[n - 1]);
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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> ans = ob.leafNodes(arr, N);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends