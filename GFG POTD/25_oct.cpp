//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
         int[] dp = new int[W+1];
        dp[0] = 0;
        int max = 0;
        int tbagc = 0;
        for(int bagc = 1;bagc<=W;bagc++) {
            max = 0;
            for(int j = 0;j<N;j++) {
                if(wt[j] <= bagc) {
                    int rbagc = bagc - wt[j];
                    tbagc = val[j] + dp[rbagc];
                }
                if(max < tbagc) {
                    max = tbagc;
                }
            }
            dp[bagc] = max;
        }
        return dp[W];         
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
