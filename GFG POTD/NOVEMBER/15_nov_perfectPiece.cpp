
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPerfectPiece(int arr[], int n)
    {

        int ans = 0;
        map<int, int> mp;
        for (int i = 0, j = 0; i < n; i++)
        {
            mp[arr[i]]++;
            int mx = mp.rbegin()->first;
            int mn = mp.begin()->first;
            while (mx - mn > 1)
            {
                mp[arr[j]]--;
                if (mp[arr[j]] == 0)
                    mp.erase(arr[j]);
                j++;
                mx = mp.rbegin()->first;
                mn = mp.begin()->first;
            }
            ans = max(ans, i - j + 1);
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
        int N;

        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends