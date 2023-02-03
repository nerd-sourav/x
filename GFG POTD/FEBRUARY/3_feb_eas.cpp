//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
int i=0;
        int j=0;
        int dir=2;
        int n=matrix.size();
        int m=matrix[0].size();
        int ans_i=0;
        int ans_j=0;
        while(i>=0 and j>=0 and i<n and j<m)
        {
            ans_i=i;
            ans_j=j;
            if(matrix[i][j]==0)
            {
                if(dir==0)
                {
                    j--;
                }
                if(dir==1)
                {
                    i--;
                }
                if(dir==2)
                {
                    j++;
                }
                if(dir==3)
                {
                    i++;
                }
            }
            else
            {
                matrix[i][j]=0;
                if(dir==0)
                {
                    dir=1;
                }
                else if(dir==1)
                {
                    dir=2;
                }
                else if(dir==2)
                {
                    dir=3;
                }
                else if(dir==3)
                {
                    dir=0;
                }
            }
        }
        return {ans_i,ans_j};
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Endsv
