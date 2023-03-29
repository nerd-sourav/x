//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
int ans = 0,sum=0;
        unordered_map<int,int> mm;
        for(int i=0;i<S.length();i++){
            if(isupper(S[i]))sum++;
            else sum--;
            if(sum==0)ans++;
            if(mm[sum])ans+=mm[sum];
            mm[sum]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends
