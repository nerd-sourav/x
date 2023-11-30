//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minimumStep(int n){
        //complete the function here
         int len = n/2;
        for(int i=1; i<n-1; i++){
            int currNum = arr[i] ,currPos = i;
            while(currNum > 0){
                int newPos = currPos < len ? 2*currPos : 2*(currPos-len)+1;
                int newNum = arr[newPos];
                arr[newPos] = -currNum;
                currNum = newNum;
                currPos = newPos;
            }
        }
        for(int i=0; i<n; i++) if(arr[i] < 0) arr[i] = -arr[i];
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends
