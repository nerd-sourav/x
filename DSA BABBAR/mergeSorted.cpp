#include <bits/stdc++.h>
#include <cmath>
using namespace std;
// changes made
// changes made
void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {

            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }
    while (i < n)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < m)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}
void print(int arr3[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr2[8] = {1, 3, 5, 7, 9, 11, 13, 15};
    int arr1[3] = {2, 4, 6};

    int arr3[11] = {0};

    merge(arr1, 3, arr2, 8, arr3);
    print(arr3, 11);

    return 0;
}
