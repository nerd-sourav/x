#include <bits/stdc++.h>
using namespace std;

void reverse(string &text, int i, int j)
{
    if (i > j)
        return;
    swap(text[i], text[j]);
    // i++;
    // j--;
    reverse(text, i + 1, j - 1);
}

int main()
{

    string text = "sourav";

    reverse(text, 0, text.length() - 1);
    cout << text;
    return 0;
}