//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
    		    int[]arr=new int[26];
            int prev=0;
            int ans=0;
            for(int i=0;i<s.length();i++){
                arr[s.charAt(i)-'A']++;
                int curr=find(arr,k);
                if(curr==-1){
                    arr[s.charAt(prev++)-'A']--;
                }else{
                    ans=Math.max(ans,curr);
                }
            }
            return ans;
    
        }
        int find(int[]arr,int k){
            int same=0;
            int diff=0;
            for(int i:arr){
                if(i>same){
                    diff+=same;
                    same=i;
                }else{
                    diff+=i;
                }
            }
            return diff<=k? same+diff : -1;
    		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends