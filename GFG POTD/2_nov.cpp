//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int last_x = -1, last_y = -1;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                last_x = i;
                if (last_y != -1)
                    ans = std::min(ans, std::abs(last_x - last_y));
            } else if (a[i] == y) {
                last_y = i;
                if (last_x != -1)
                    ans = std::min(ans, std::abs(last_x - last_y));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends
