

#include <bits/stdc++.h>

using namespace std;



class Solution {

  public:

    bool isStraightHand(int N, int groupSize, vector<int> &hand) {

        // code her

        multiset<int> ms;

        

        for(auto i : hand){

            ms.insert(i);

        }

        

        while(ms.size()){

            int item = *ms.begin();

            

            for(int i = 0; i < groupSize; i++){

                if(ms.count(item + i) == 0){

                    return 0;

                }

                

                ms.erase(ms.find(item + i)); //ms.erase(item + 1) this wont work

            }

        }

        

        return 1;

        

    }

};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int N, groupSize;

        cin >> N >> groupSize;

        vector<int> hand(N);

        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;

        int ans = obj.isStraightHand(N, groupSize, hand);

        if (ans)

            cout << "True" << endl;

        else

            cout << "False" << endl;

    }

    return 0;

}

// } Driver Code Ends
