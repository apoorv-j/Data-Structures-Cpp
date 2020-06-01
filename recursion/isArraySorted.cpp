#include <bits/stdc++.h>
using namespace std;

bool isSorted(int *arr, int n)
{
    if (n == 1)
        return true;

    if (arr[0] < arr[1] && isSorted(arr + 1, n - 1))
        return true;

    return false;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 6};
    cout << boolalpha << isSorted(arr, 5);

    return 0;
}