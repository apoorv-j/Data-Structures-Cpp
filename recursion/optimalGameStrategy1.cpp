#include <bits/stdc++.h>
using namespace std;

int game(int *arr, int s, int e, int sum)
{
    if (s > e)
    {
        return sum;
    }

    if ((s + e) % 2 == 0)
        return min(game(arr, s + 1, e, sum), game(arr, s, e - 1, sum));

    return max(game(arr, s + 1, e, sum + arr[s]), game(arr, s, e - 1, sum + arr[e]));
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << game(arr, 0, n - 1, 0);
    return 0;
}