void dfs(int node,vector<bool> &vis,vector<int> &topo,vector<pair<int,int>> adj[]){
      vis[node]=true;
      for(auto x:adj[node]){
          if(!vis[x.first])dfs(x.first,vis,topo,adj);
      }
      topo.push_back(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<bool> vis(N,false);
        vector<int> topo;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,vis,topo,adj);
            }
        }
        reverse(topo.begin(),topo.end());
        vector<int> dis(N,INT_MAX);
        dis[0]=0;
        for(int i=0;i<N;i++){
            if(dis[topo[i]]!=INT_MAX){
                for(auto x:adj[topo[i]]){
                    if(dis[topo[i]]+x.second<dis[x.first]){
                        dis[x.first]=dis[topo[i]]+x.second;
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i]==INT_MAX)dis[i]=-1;
        }
        return dis;
    }
