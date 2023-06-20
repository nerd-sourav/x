  int ans=0,len=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                if(len)ans++;
                len=0;
            }
            else len++;
        }
        if(len==n)return -1;
        if(len)ans++;
        return ans;
