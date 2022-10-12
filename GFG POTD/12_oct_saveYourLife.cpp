//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string maxSum(string w, char x[], int b[], int n)
    {
        // code here
        unordered_map<char, int> mp;
        int sum = 0;
        int maxSum = INT_MIN;
        string ans = "";
        string temp = "";
        // pushing elements in the map;
        for (int i = 0; i < n; i++)
        {
            mp[x[i]] = b[i];
        }

        for (int i = 0; i < w.size(); i++)
        {
            // checking if the element is redefined
            char ch = w[i];
            if (mp.find(ch) != mp.end())
            {
                sum += mp[ch];
            }
            else
            {
                sum += ch;
            }
            // making a temp string till the curent sum
            temp += ch;
            if (sum > maxSum)
            {
                maxSum = sum;
                ans = temp;
            }
            // reseting temp
            if (sum < 0)
            {
                temp = "";
                sum = 0;
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
        string w;
        cin >> w;
        int n;
        cin >> n;
        char x[n];
        int b[n];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.maxSum(w, x, b, n) << endl;
    }
    return 0;
}
// } Driver Code Ends