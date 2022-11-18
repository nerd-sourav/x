#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int noOfOpenDoors(long long N)
    {

        return sqrt(N);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;

        cin >> N;

        Solution ob;
        cout << ob.noOfOpenDoors(N) << endl;
    }
    return 0;
}
// } Driver Code Ends