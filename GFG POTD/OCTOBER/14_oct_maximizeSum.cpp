#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeSum(int a[], int n)
    {
        // Complete the function

        /*
            1 2 2 2 3 3 4 6 9
            1-1
            2-3 -
            3-2 -1-0
            4-1 -0
            6-1 -0
            9-1 -0
            sum = 9 + 6= 15+4 = 19 +3 =22
        */
        unordered_map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(a[i]) == mp.end())
            {
                mp[a[i]] = 1;
            }
            else
            {
                mp[a[i]]++;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (mp.find(a[i]) != mp.end() && mp[a[i]] > 0)
            {
                sum += a[i];
                mp[a[i]]--;
                if (mp.find(a[i] - 1) != mp.end())
                {
                    mp[a[i] - 1]--;
                }
            }
        }
        return sum;
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
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        Solution ob;

        cout << ob.maximizeSum(arr, n) << endl;
    }
}
