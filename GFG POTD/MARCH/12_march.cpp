
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
int one=0,row=0,j=N-1;
        for(int i=0;i<N;i++){
            while(j>=0 and mat[i][j]){
                j--;
                one++;
                row=i;
            }
        }
        return {row,one};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends
