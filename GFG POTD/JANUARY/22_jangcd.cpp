//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int N, int K, vector<int> &arr) {
        // code here
int sum = 0;
        for(int i=0;i<N;i++){
            sum += arr[i];
        }
        vector <int> factors;
        
        int M = sqrt(sum) + 1;

        for(int i=1; i<M; i++){
            if(sum % i == 0){
                factors.push_back(i);
                factors.push_back(sum / i);
            }
        }
        
        for(int i=1; i<N; i++){
            arr[i] += arr[i-1];
        }
        
        int ans = 1;
        for(int ele:factors){
            int subarray_count = 0;
            for(int i=0; i<N; i++){
                if(arr[i] % ele == 0){
                    subarray_count++;
                }
            }
            if(subarray_count >= K){
                ans = max(ans, ele);
            }
        }
        return ans;
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
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
