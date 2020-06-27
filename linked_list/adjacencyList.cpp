#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v;
    cin >> v;
    list<pair<int, int>> l[v];
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        l[x].push_back(make_pair(y, wt));
        l[y].push_back(make_pair(x, wt));
    }

    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (auto v : l[i])
        {
            cout << "(" << v.first << "," << v.second << "), ";
        }
        cout << endl;
    }

    return 0;
}