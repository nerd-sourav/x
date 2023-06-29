//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
     int nextHappy(int N) {
    int nextNumber = N + 1; // Start checking from the next number
    
    while (true) {
        if (isHappy(nextNumber)) {
            return nextNumber; // Found the next happy number
        }
        nextNumber++;
    }
}

bool isHappy(int num) {
    while (true) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        if (sum == 1) {
            return true; // Number is happy
        } else if (sum == 4) {
            return false; // Number is not happy (loop detected)
        }
        
        num = sum; // Continue with the new sum
    }
}


};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
