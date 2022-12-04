//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string rearrange(string s, int n)
    {
        // your code here
        // your code here
        int nv = 0, nc = 0;
        vector<int> vo(26, 0);
        vector<int> co(26, 0);
        char smallestVow = 'u', smallestCons = 'z';
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                vo[c - 'a']++;
                nv++;
                if (s[i] < smallestVow)
                    smallestVow = s[i];
            }
            else
            {
                nc++;
                co[c - 'a']++;
                if (s[i] < smallestCons)
                    smallestCons = s[i];
            }
        }

        // size diff greater than 1 no ans possible
        if (abs(nv - nc) > 1)
            return "-1";

        // for first ch
        bool vowFirst;
        if (nv == nc)
        {
            if (smallestVow < smallestCons)
                vowFirst = true;
            else
                vowFirst = false;
        }
        else if (nv > nc)
            vowFirst = true;
        else
            vowFirst = false;

        int i = 0, j = 0, it = 0;
        while (i < 26 || j < 26)
        {
            // check vowel
            if (vowFirst == true)
            {
                while (vo[i] == 0 && i < 26)
                    i++;

                if (i == 26)
                    break;

                s[it] = 'a' + i;
                it++;
                vo[i]--;
                vowFirst = false;
            }
            else
            {
                while (co[j] == 0 && j < 26)
                    j++;

                if (j == 26)
                    break;

                s[it] = 'a' + j;
                it++;
                co[j]--;
                vowFirst = true;
            }
        }

        return s;
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.rearrange(s, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends