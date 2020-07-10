#include <bits/stdc++.h>
using namespace std;

int main()
{
    long q;
    cin >> q;
    stack<int> cost;
    for (long i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 2)
        {
            int c;
            cin >> c;
            cost.push(c);
        }
        else if (t == 1)
        {
            if (!cost.empty())
            {
                cout << cost.top();
                cost.pop();
            }
            else
            {
                cout << "No Code";
            }
            cout << endl;
        }
    }
    return 0;
}