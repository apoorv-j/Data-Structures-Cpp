#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll k;
    cin >> k;

    deque<ll> q;
    ll i;
    for (i = 0; i < k; i++)
    {

        // remove element less than the current element
        while (!q.empty() and arr[i] > arr[q.back()])
        {
            q.pop_back();
        }
        // add curr element to deque
        q.push_back(i);
    }

    for (; i < n; i++)
    {
        //prll largest element in current deque ie the sub arrray
        cout << arr[q.front()] << " ";

        //remove element that is outside the window size
        while (!q.empty() and (i - k) >= q.front())
        {
            q.pop_front();
        }

        // remove element less than the current element
        while (!q.empty() and arr[i] >= arr[q.back()])
        {
            q.pop_back();
        }
        // add curr element to deque
        q.push_back(i);
    }
    cout << arr[q.front()];

    return 0;
}