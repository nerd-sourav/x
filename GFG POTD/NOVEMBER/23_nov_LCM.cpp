
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int maxSumLCM(int n)
    {
        // code here
        long long ans = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (n / i == i)
                {
                    ans = ans + i;
                }
                else
                {
                    ans = ans + i + (n / i);
                }
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.maxSumLCM(n) << endl;
    }
    return 0;
}
