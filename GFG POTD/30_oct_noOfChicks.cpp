#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int NoOfChicks(int n)
    {
        long newChick[n + 1];
        long chick = 1;
        newChick[0] = 1;

        for (int day = 1; day < n; day++)
        {

            if (day >= 6)
            {
                chick -= newChick[day - 6];
            }
            newChick[day] = chick * 2;
            chick += newChick[day];
        }
        return chick;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N;
        cin >> N;
        Solution obj;
        long long int ans = obj.NoOfChicks(N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends