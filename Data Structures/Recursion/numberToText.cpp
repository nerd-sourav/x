#include <bits/stdc++.h>
using namespace std;
void num(int n)
{
    if (n <= 0)
    {
        return;
    }
    string arr[10] = {"zero",
                      "one",
                      "two",
                      "three",
                      "four",
                      "five",
                      "six",
                      "seven",
                      "eight",
                      "nine"};
    int q = n / 10;
    int r = n % 10;

    num(q);
    cout << arr[r] << " ";
}
int main()
{
    int n;
    cin >> n;
    num(n);
    // cout << ans;
    return 0;
}