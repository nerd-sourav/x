//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {

  public:

    int distributeTicket(int n, int k) {

        // code here

        deque<int> dq;

        for(int i = 1; i <=n; i++){

            dq.push_back(i);

        }

        bool front = true;

        int count = k;

        while(dq.size() > 1){

            if(count > 0 and front == true){

                dq.pop_front();

                count--;

            }

            if(count == 0){

                front = !front;

                count = k;

            }

            if(count > 0 and front == false){

                dq.pop_back();

                count--;

            }

        }

        return dq.front();

    }

};

//{ Driver Code Starts.

int main(){

    int t;

    scanf("%d ",&t);

    while(t--){

        

        int N;

        scanf("%d",&N);

        

        

        int K;

        scanf("%d",&K);

        

        Solution obj;

        int res = obj.distributeTicket(N, K);

        

        cout<<res<<endl;

        

    }

}

// } Driver Code Ends
