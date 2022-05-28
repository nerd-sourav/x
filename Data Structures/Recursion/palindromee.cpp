#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string name, int i, int j)
{

    if (i >= j)
        return true;
    if (name[i] != name[j])
        return false;
    i++;
    j--;
    return isPalindrome(name, i, j);
}

int main()
{
    string name = "racecsar";
    int ans = isPalindrome(name, 0, name.length() - 1);
    cout << ans;

    return 0;
}