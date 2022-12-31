class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
       
        vector<vector<vector<int>>>adj(n+1);
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            
            adj[u].push_back({v,w});
        }
        
        // make distance vector
        vector<int>dis(n+1,INT_MAX);
        
        // take pq -> min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        //put source node
        dis[k]=0;
        pq.push({0,k});
         
        // process
        while(pq.size()>0)
        {
            auto front=pq.top();
            pq.pop();
            
            // 2 val
            int dist_node=front.first;
            int  node=front.second;
            
            for(auto neigh:adj[node])
            {
                // update 
                if(dist_node+neigh[1]<dis[neigh[0]])
                {
                    dis[neigh[0]]=dist_node+neigh[1];
                    pq.push({dis[neigh[0]],neigh[0]});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX)
               return -1;
            else
             ans=max(ans,dis[i]);
        }
       return ans; 
    }
