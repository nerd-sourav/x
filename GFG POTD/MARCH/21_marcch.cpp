 int ans=INT_MAX;
        
        for(int i=0;i<N; i++)
        {
            ans=min(ans,abs(pos[i]-cur)*time[i]);
        }
        return ans;
