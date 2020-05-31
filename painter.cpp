#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
bool isPossible(ll int *boards, ll int n, ll int k, ll int mid)
{
    ll int time = 0;
    k--;
    for (ll int i = 0; i < n; i++)
    {

        if (time + boards[i] > mid)
        {
            k--;
            if (k < 0)
                return false;
            else
            {
                time = boards[i];
            }
        }
        else
        {
            time += boards[i];
        }
    }
    return true;
}
int main()
{
    ll int k, n;
    cin >> k >> n;
    ll int boards[n];
    ll int e = 0;
    for (ll int i = 0; i < n; i++)
    {
        cin >> boards[i];
        e += boards[i];
    }
    sort(boards, boards + n);
    ll int s = boards[n - 1];

    ll int mid;
    ll int min_time = e;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (isPossible(boards, n, k, mid))
        {
            min_time = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << min_time;
    return 0;
}