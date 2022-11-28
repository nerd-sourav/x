//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> findSubarray(int a[], int n)
    {
        // code here

        int start = 0, end = -1;
        int i = 0, j = 0, mx = 0, sum = 0;

        while (j < n)
        {

            if (a[j] >= 0)
            {
                sum += a[j];
                j++;
            }
            // max== sum but we got the new maximum length
            else if (mx == sum && (end - start + 1) < ((j - 1) - i + 1))
            {
                start = i;
                end = j - 1;

                sum = 0;
                j++;
                i = j;
            }
            // max < sum means we need to update max
            else if (mx < sum)
            {
                // update new window
                mx = sum;
                start = i;
                end = j - 1;

                sum = 0;
                j++;
                i = j;
            }
            // as max>sum condition so simply ingnore this window
            else
            {
                sum = 0;
                j++;
                i = j;
            }
        }

        // extra
        if (mx < sum)
        {
            mx = sum;
            start = i;
            end = j - 1;
        }

        // same sum but max length
        if (mx == sum && (end - start + 1) < ((j - 1) - i + 1))
        {
            start = i;
            end = j - 1;
        }

        vector<int> ans;

        for (int i = start; i <= end; i++)
            ans.push_back(a[i]);

        if (ans.empty())
            ans.push_back(-1);

        return ans;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans)
{
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends