//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    // void dfs(int i ,int j,vector<vector<int>>&matrix,vector<vector<int>>&vis,int n,int m){
    //     if(i<0 || i==n || j<0 || j==m || matrix[i][j]==0 || vis[i][j]==1 ){
    //         return;
    //     }
    //      dfs(i+1,j,matrix,vis,n,m);
    //      dfs(i,j+1,matrix,vis,n,m);
    //      dfs(i-1,j,matrix,vis,n,m);
    //      dfs(i,j-1,matrix,vis,n,m);
    // }
    void DFS(vector<vector<int>> &M, int i, int j, int ROW, int COL)
    {

        if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1) || M[i][j] != 1)
            return;

        if (M[i][j] == 1)
        {
            M[i][j] = 0;
            DFS(M, i + 1, j, ROW, COL);
            DFS(M, i - 1, j, ROW, COL);
            DFS(M, i, j + 1, ROW, COL);
            DFS(M, i, j - 1, ROW, COL);
        }
    }

    int countIslands(vector<vector<int>> M)
    {

        int ROW = M.size();

        int COL = M[0].size();

        int count = 0;

        for (int i = 0; i < ROW; i++)
        {

            for (int j = 0; j < COL; j++)
            {

                if (M[i][j] == 1)
                {
                    count++;
                    DFS(M, i, j, ROW, COL);
                }
            }
        }
        return count;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {

        vector<vector<int>> island(n, vector<int>(m, 0));

        vector<int> v;

        for (int i = 0; i < operators.size(); i++)
        {

            int x = operators[i][0];
            int y = operators[i][1];

            if (island[x][y] != 1)
            {

                island[x][y] = 1;

                v.push_back(countIslands(island));
            }
            else
            {

                int xx = v[v.size() - 1];

                v.push_back(xx);
            }
        }
        return v;

        // code here
        //  vector<vector<int>>matrix(n, vector<int>(m,0));
        //  vector<int>ans;

        //  for(int k=0;k<q.size();k++){
        //      vector<vector<int>>vis(n, vector<int>(m,0));
        //      int count = 0;
        //      int x = q[k][0];
        //      int y = q[k][1];
        //      matrix[x][y]=1;

        //      for(int i = 0;i<n;i++){
        //          for(int j= 0;j<m;j++){
        //              if(matrix[i][j]==1 && vis[i][j]==0){
        //                  dfs(i,j,matrix,vis,n,m);
        //                  count++;
        //              }
        //          }
        //      }
        //      ans.push_back(count);
        //  }
        // return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a;

        for (int i = 0; i < k; i++)
        {
            vector<int> temp;
            for (int j = 0; j < 2; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.numOfIslands(n, m, a);

        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
}
