//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here

// code here
        int zero=0,one=0;
        for(int i=0;i<N;i++){
            if(S[i]=='1'){
                if(zero>0){
                    if(one==0 and zero>X)return false;
                    else if(zero>X*2)return false;
                }
                zero=0;
                one=1;
            }
            else zero++;
        }
        if(zero>0){
            if(one==0 or zero>X)return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends
