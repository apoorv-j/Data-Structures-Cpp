#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n[t];
    int *arr[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
        arr[i] = new int[n[i]];
        for (int j = 0; j < n[i]; j++)
            cin >> arr[i][j];
    }
    for (int i = 0; i < t; i++)
    {
        if (!next_permutation(arr[i], arr[i] + n[i]))
            sort(arr[i], arr[i] + n[i]);

        for (int j = 0; j < n[i]; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}