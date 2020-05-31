#include <iostream>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int t;
    cin >> t;
    int n[t];
    pair<int, int> *a[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];

        a[i] = new pair<int, int>[n[i]];
        for (int j = 0; j < n[i]; j++)
        {
            cin >> a[i][j].first;
            cin >> a[i][j].second;
        }
    }

    for (int i = 0; i < t; i++)
    {
        sort(a[i], a[i] + n[i], compare);
        int num = 1;
        int end = a[i][0].second;

        for (int j = 1; j < n[i]; j++)
        {
            if (a[i][j].first >= end)
            {
                num++;
                end = a[i][j].second;
            }
        }
        cout << num << endl;
    }

    return 0;
}