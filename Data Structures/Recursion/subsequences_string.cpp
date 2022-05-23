#include <bits/stdc++.h>
using namespace std;
void subsequences(string s, string out, int index)
{
    if (index >= s.length())
    {
        for (int i = 0; i < out.length(); i++)
        {
            cout << out[i] << "";
        }
        cout << endl;
        return;
    }

    // element nai le rahe hai
    subsequences(s, out, index + 1);
    // element le rahe hai;
    subsequences(s, out + s[index], index + 1);
}

int main()
{
    string name;
    cin >> name;
    string s = "";
    subsequences(name, s, 0);

    return 0;
}