#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        while (!s.empty() and arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        if (s.empty())
            cout << i + 1 << " ";
        else
            cout << i - s.top() << " ";

        s.push(i);
    }
    cout << "END";
    return 0;
}