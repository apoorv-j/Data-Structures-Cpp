// UNIQUE NUMBER - 2N+1
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    // int arr[] = {7, 9, 6, 8, 3, 7, 8, 6, 9};
    // int n = sizeof(arr) / sizeof(int);
    int n;
    cin >> n;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        res = res ^ x;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     res = res ^ arr[i];
    // }
    cout << res;

    return 0;
}