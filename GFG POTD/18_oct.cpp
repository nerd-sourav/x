//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> list;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) if (dfs(adj, i, vis)) list.push_back(i);
        return list;
    }

    bool dfs(vector<int> adj[], int i, vector<int> &vis) {
        if (vis[i] == 1) return false;
        if (vis[i] == 2) return true;

        vis[i] = 1;
        for (int nbrs : adj[i]) {
            int a = vis[nbrs];
            if (a == 1) return false;
            if (a == 2) continue;
            if (!dfs(adj, nbrs, vis)) return false;
        }
        vis[i] = 2;
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
