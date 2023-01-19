//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int help(int x,int y){
        if(x<=y)return 0;
        return 1+help(x/2,y);
    }
    int carpetBox(int A, int B, int C, int D){
        //code here
        int a = help(A,C);
        int b = help(B,D);
        int c = help(A,D);
        int d = help(B,C);
        return min(a+b,c+d);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
