//driver code not added

string a="pr";
      string b="rp";
      
      //abcpr
      if(X<Y)
      {
          swap(X,Y);
          swap(a,b);
      }
      
      long long ans=0;
      
      stack<char>st;
      int n=S.size();
      for(int i=0;i<n; i++)
      {
          if(st.empty())
          {
              st.push(S[i]);
          }
          else if(S[i]==a[1] and st.top()==a[0])
          {
              ans+=X;
              st.pop();
          }
          else
          {
              st.push(S[i]);
          }
      }
      
      S="";
      //a b c
      while(!st.empty())
      {
          S+=st.top();
          st.pop();
      }
      reverse(S.begin(),S.end());
      n=S.size();
      
      for(int i=0;i<n; i++)
      {
          if(st.empty())
          {
              st.push(S[i]);
          }
          else if(S[i]==b[1] and st.top()==b[0])
          {
              ans+=Y;
              st.pop();
          }
          else
          {
              st.push(S[i]);
          }
      }
      
      return ans;
