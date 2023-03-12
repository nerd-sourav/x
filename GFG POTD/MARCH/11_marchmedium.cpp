//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        int arr[N];
        for(int i=0;i<N;i++){
            int c = 1;
            for(int j=i+1;j<N;j++){
                if(A[i] == A[j])c++;
            }
            arr[i]=c;
        }
        vector<int> ans;
        for(int i=0;i<num;i++){
            int start = Q[i][0];
            int end = Q[i][1];
            int k = Q[i][2];
            int c=0;
            for(int j=start;j<=end;j++){
                if(arr[j]==k)c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends
