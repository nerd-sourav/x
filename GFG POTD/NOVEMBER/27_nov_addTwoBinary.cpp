//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver
class Solution
{
public:
    string addBinary(string a, string b)
    {
        // your code here
        int n = a.size();
        int m = b.size();

        int i = n - 1;
        int j = m - 1;
        int carry = 0;
        string ans = "";
        while (i >= 0 || j >= 0)
        {

            int sum = 0;
            if (i >= 0)
            {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }

            sum += carry;
            ans.push_back(sum % 2 + '0');
            carry = sum / 2;
        }

        if (carry == 1)
        {
            ans = ans + '1';
        }

        reverse(ans.begin(), ans.end());
        int index = 0;
        while (ans[index] == '0')
        {
            index++;
        }
        return ans.substr(index);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends