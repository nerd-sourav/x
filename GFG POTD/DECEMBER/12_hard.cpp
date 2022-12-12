//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto neigh : adj[node])
        {
            if (neigh == parent)
                continue;
            else if (!vis[neigh])
            {
                child++;
                // dfs call
                dfs(neigh, node, vis, tin, low, timer, adj, isArticulation);

                // update low
                low[node] = min(low[node], low[neigh]);

                // check the articulation point
                if (low[neigh] >= tin[node] && parent != -1)
                {
                    isArticulation[node] = 1;
                }
            }
            else if (neigh != parent)
            {
                low[node] = min(low[node], tin[neigh]);
            }
        }

        if (parent == -1 && child > 1)
            isArticulation[node] = 1;
    }

    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<int> vis(n, 0);
        vector<int> isArticulation(n, 0);
        int timer = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (isArticulation[i] == 1)
                ans.push_back(i);
        }
        if (ans.size() == 0)
        {
            return {-1};
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends