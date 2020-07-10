#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    stack<ll> s;
    ll arr[n];
    ll max_h = INT_MIN;

    ll i;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];

        while (!s.empty() and arr[i] < arr[s.top()])
        {
            ll height = arr[s.top()];
            while (!s.empty() and height <= arr[s.top()])
                s.pop();

            if (s.empty())
                max_h = max(max_h, height * (i));
            else
                max_h = max(max_h, height * (i - s.top() - 1));

            // cout<<max_h<<" ";
        }
        s.push(i);
    }
    while (!s.empty())
    {
        ll height = arr[s.top()];
        while (!s.empty() and height <= arr[s.top()])
            s.pop();

        if (s.empty())
            max_h = max(max_h, height * (i));
        else
            max_h = max(max_h, height * (i - s.top() - 1));
    }
    cout << max_h;
    return 0;
}