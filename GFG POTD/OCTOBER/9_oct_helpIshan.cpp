#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool isPrime(int n)
    {
        if (n <= 1)
        {
            return false;
        }
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    int NthTerm(int n)
    {
        if (n == 1)
            return 1;
        if (isPrime(n) == true)
        {
            return 0;
        }

        int diff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int t = 0;
            // forward
            t = n + i;
            if (isPrime(t))
            {
                return (t - n);
            }

            t = n - i;
            if (isPrime(t))
            {
                return (n - t);
            }
        }

        // int before=0;
        // int after = 0;
        //  for(int i = 0;i<=100000;i++){
        //      if(i<n && isPrime(i)){
        //          before = max(before,i);
        //      }
        //      if(i>n && isPrime(i)){
        //          after = i;
        //          break;
        //      }

        //  }
        //  return min((n-before),(after-n));

        //  int ans=0;
        //  int mx1=INT_MIN;
        //  for(int i = 1;i<=n;i++){
        //      if(isPrime(i)==true){
        //         mx1=max(mx1,i);
        //      }
        //  }

        //  int m = n;
        //  bool flag = false;
        //  while(m<=100000){
        //      if(isPrime(m)){

        //          ans = m;
        //          break;
        //      }
        //      m++;
        //  }

        //  return(min((n-mx1),(ans-n)));
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
        int ans = obj.NthTerm(N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends