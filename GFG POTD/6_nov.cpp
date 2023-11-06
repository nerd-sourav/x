//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // code here
         vector<int> result;
        for (int c = 0; c < q; c++) {
            int hop = queries[c][0];
            int row = queries[c][1];
            int col = queries[c][2];

            int sum = 0;
            for (int i = -hop; i <= hop; i++) {
                for (int j = -hop; j <= hop; j++) {
                    bool isValidRow = (row+i >= 0) && (row+i < n);
                    bool isValidCol = (col+j >= 0) && (col+j < m);

                    if (isValidRow && isValidCol && (abs(i) == hop || abs(j) == hop)) {
                        sum += mat[row+i][col+j];
                    }
                }
            }

            result.push_back(sum);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends
