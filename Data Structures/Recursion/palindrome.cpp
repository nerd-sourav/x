#include <bits/stdc++.h>
using namespace std;
int palindrome(string s, int start, int end)
{
    int ans;
    if (s[start] != s[end])
    {
        return ans;
    }
    if (start <= end)
    {
        return ans;
    }
    return palindrome(s, start + 1, end - 1);
}

int main()
{

    string name;
    cin >> name;
    int ans = palindrome(name, 0, name.length() - 1);
    cout << ans;
    return 0;
}