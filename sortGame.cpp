#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
bool compare(pair<string, int> e1, pair<string, int> e2)
{
    if (e1.second != e2.second)
        return e1.second > e2.second;

    return e1.first < e2.first;
}

int main()
{
    int n, x;
    cin >> x >> n;
    pair<string, int> emp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> emp[i].first >> emp[i].second;
    }
    sort(emp, emp + n, compare);
    pair<string, int> temp = make_pair("", x);

    for (int i = 0; i < n; i++)
    {
        if (emp[i].second < x)
            break;
        cout << emp[i].first << " " << emp[i].second << endl;
    }
    return 0;
}