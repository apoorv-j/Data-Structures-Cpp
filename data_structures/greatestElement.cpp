#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int res[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        res[i] = -1;
    }
    stack<int> s;

    s.push(0);
    int i = 1;
    while (i != 0)
    {
        if (arr[i] > arr[s.top()])
        {
            res[s.top()] = arr[i];
            s.pop();
        }
        if (arr[i] != -1)
        {
            s.push(i);
            arr[i] = -1;
        }
        i = (i + 1) % n;
    }
    while (!s.empty())
    {
        /* code */
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}