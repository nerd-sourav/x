#include <bits/stdc++.h>
using namespace std;
void printsubset(vector<int> input, vector<int> output, int index)
{
    if (index >= input.size())
    {
        // we need to print the vector
        for (auto i : output)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    // agr include nai krna hai
    printsubset(input, output, index + 1);

    // agr include krna hai
    output.push_back(input[index]);

    printsubset(input, output, index + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    vector<int> output;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    printsubset(input, output, 0);

    return 0;
}
