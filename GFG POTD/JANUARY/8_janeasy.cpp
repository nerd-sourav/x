//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        // code here
long long ans=0;
        unordered_map<int,int> mm;
        for(int i=0;i<n;i++)mm[arr[i]%k]++;
        for(auto x:mm){
            long long temp = (x.second*(x.second-1))/2;
            ans+=temp;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends
