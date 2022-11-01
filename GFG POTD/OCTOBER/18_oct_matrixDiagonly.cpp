
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<int> downwardDigonal(int n, vector<vector<int>> a)
    {
        // Your code goes here
        vector<int> ans;
        // for upper triangle
        for (int i = 0; i < n; i++)
        {
            int row = 0;
            int col = i;
            while (col >= 0)
            {
                ans.push_back(a[row][col]);
                row++;
                col--;
            }
        }
        // lower triangle
        for (int i = 1; i < n; i++)
        {
            int row = i;
            int col = n - 1;
            while (row < n)
            {
                ans.push_back(a[row][col]);
                row++;
                col--;
            }
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
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends