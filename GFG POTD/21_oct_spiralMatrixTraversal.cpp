//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> reverseSpiral(int r, int c, vector<vector<int>> &a)
    {
        // code here
        vector<int> ans;
        int top = 0;
        int down = r - 1;
        int left = 0;
        int right = c - 1;
        int dir = 0; // 0(left to right) 1(top to down) 2 (right to left) 3 ( left to up)
        while (left <= right && top <= down)
        {
            if (dir == 0)
            {
                // left -> right
                for (int i = left; i <= right; i++)
                {
                    ans.push_back(a[top][i]);
                }
                top++;
            }
            else if (dir == 1)
            {
                // top ->down
                for (int i = top; i <= down; i++)
                {
                    ans.push_back(a[i][right]);
                }
                right--;
            }
            else if (dir == 2)
            {
                // right -> left
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(a[down][i]);
                }
                down--;
            }
            else if (dir == 3)
            {
                // down -> top
                for (int i = down; i >= top; i--)
                {
                    ans.push_back(a[i][left]);
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }
        reverse(ans.begin(), ans.end());
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
        int R, C;
        cin >> R >> C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for (int i = 0; i < R * C; i++)
            cin >> a[i / C][i % C];
        Solution ob;
        vector<int> ans = ob.reverseSpiral(R, C, a);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends