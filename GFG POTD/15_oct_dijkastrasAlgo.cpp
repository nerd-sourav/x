//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {

        // code here
        if (source.first == destination.first && source.second == destination.second)
            return 0;

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dis(row, vector<int>(col, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        // make source dis=0
        dis[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (q.size() > 0)
        {
            auto node = q.front();
            q.pop();

            int dist = node.first;
            int r = node.second.first;
            int c = node.second.second;

            // all four dirc
            for (int i = 0; i < 4; i++)
            {
                int newR = r + dr[i];
                int newC = c + dc[i];

                // valid
                if (newR >= 0 && newR < row && newC >= 0 && newC < col && grid[newR][newC] == 1 && dist + 1 < dis[newR][newC])
                {
                    // update
                    dis[newR][newC] = dist + 1;

                    // check we reach destination or not
                    if (newR == destination.first && newC == destination.second)
                        return dist + 1;

                    q.push({dist + 1, {newR, newC}});
                }
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}
