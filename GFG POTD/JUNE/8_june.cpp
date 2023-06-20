//{ Driver Code Starts

//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution

{

public:

    string kthPermutation(int n, int k)

    {

        // code here

        string h="";

        int chk=1;

        for(int i=1;i<=n;i++){

            h+=to_string(i);

            chk*=i;

        }

        string ans="";

        int i=0,g=0,r=0;

        while(i<n){

           r=chk/(n-i),g=k/r;

           if(k%r==0) g--;

           ans+=h[g];

           h.erase(h.begin()+g);

           k=k-(r)*(g);

           i++;

           chk=r;

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

        int n, k;

        cin >> n >> k;

        Solution ob;

        string ans = ob.kthPermutation(n, k);

        cout << ans;

        cout << "\n";

    }

    return 0;

}

// } Driver Code Ends
