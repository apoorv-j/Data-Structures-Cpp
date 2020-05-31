#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

bool numericComparator(pair<string, string> pair1, pair<string, string> pair2)
{
    return stoi(pair1.second) < stoi(pair2.second);
}
bool lexoComparator(pair<string, string> pair1, pair<string, string> pair2)
{
    return pair1.second < pair2.second;
}

int main()
{
    int n;
    cin >> n;
    cin.get();
    string s[n];
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    int key;
    string rev;
    string com_type;
    cin >> key >> rev >> com_type;
    pair<string, string> strpairs[n];
    for (int i = 0; i < n; i++)
    {
        strpairs[i].first = s[i];
        strpairs[i].second = strtok((char *)s[i].c_str(), " ");
        for (int j = 1; j < key; j++)
        {
            strpairs[i].second = strtok(NULL, " ");
        }
    }
    if (com_type == "numeric")
    {
        sort(strpairs, strpairs + n, numericComparator);
    }
    else
    {
        sort(strpairs, strpairs + n, lexoComparator);
    }

    if (rev == "false")
    {
        for (int i = 0; i < n; i++)
        {
            cout << strpairs[i].first << endl;
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
            cout << strpairs[i].first << endl;
    }

    return 0;
}