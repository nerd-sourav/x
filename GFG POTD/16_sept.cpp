//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        int mod= 1e9+7;
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
        long long ans=0;
        long long one=1;
        long long two=1;
        long long three=2;
        for(int i=3;i<=n;i++){
            ans= (one+two+three)%mod;
            one=two;
            two=three;
            three=ans;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
