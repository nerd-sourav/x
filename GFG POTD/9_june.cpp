//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution

{

	public:		vector<string>finfd_permutation(string S)

		{

		    // Code here there

		}

		void nikaldo(string &s,vector<string> &ans,unordered_map<string,int> &mm){

	        int i=0,j=s.length()-1;

	        for(i=s.length()-2;i>=0;i--){

	            if(s[i]<s[i+1])break;

	        }

	        if(i<0)return;

	        for(int k=s.length()-1;k>i;k--){

	            if(s[k]>s[i]){

	                j=k;

	                break;

	            }

	        }

	        swap(s[i],s[j]);

	        i++;

	        j=s.length()-1;

	        while(i<j){

	            swap(s[i],s[j]);

	            i++;

	            j--;

	        }

	        mm[s]++;

	        if(mm[s]==1)ans.push_back(s);

	    }

		vector<string>find_permutation(string S)

		{

		    // Code here there

		    sort(S.begin(),S.end());

		    vector<string> ans;

		    ans.push_back(S);

		    unordered_map<string,int> mm;

		    mm[S]++;

		    int fact = 1;

		    for(int i=2;i<=S.length();i++)fact*=i;

		    fact--;

		    while(fact--){

		        nikaldo(S,ans,mm);

		    }

		    return ans;

		}

};

//{ Driver Code Starts.

int main(){

    int t;

    cin >> t;

    while(t--)

    {

	    string S;

	    cin >> S;

	    Solution ob;

	    vector<string> ans = ob.find_permutation(S);

	    for(auto i: ans)

	    {

	    	cout<<i<<" ";

	    }

	    cout<<"\n";

    }

	return 0;

}

// } Driver Code Ends
