

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int findMin(int n, char a[])
    {
        // code here
        int r = 0, g = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 'R')
                r++;
            else if (a[i] == 'G')
                g++;
            else
                b++;
        }
        // if all the colors are same;
        if (r == n || b == n || g == n)
            return n;
        if ((r % 2 == 0 && g % 2 == 0 && b % 2 == 0) || (r % 2 != 0 && b % 2 != 0 && g % 2 != 0))
            return 2;
        return 1;
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
        char a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.findMin(n, a) << "\n";
    }
    return 0;
}
// } Driver Code Ends