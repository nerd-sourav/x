#include <bits/stdc++.h>
using namespace std;
void spell(int n, string arr[10])
{

    // base changes wmade
    // changes madee
    // changes madee
    if (n <= 0)
    {
        return;
    }
    int q = n / 10;

    int r = n % 10;

    spell(q, arr);
    cout << arr[r] << " ";
}

int main()
{
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
    spell(123, arr);

    return 0;
}