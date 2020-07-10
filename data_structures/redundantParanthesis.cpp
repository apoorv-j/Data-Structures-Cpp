#include <bits/stdc++.h>
using namespace std;

string checkParanthesis(string arr)
{
    stack<char> p;
    for (auto i : arr)
    {
        if (i != ')')
            p.push(i);
        else if (i == ')')
        {
            int top = p.top();
            int c = 0;
            while (top != '(' and !p.empty())
            {
                c++;
                p.pop();
                top = p.top();
            }

            if (c == 0)
            {
                return "Duplicate";
            }
            p.pop();
        }
    }
    return "Not Duplicates";
}

int main()
{
    int t;
    cin >> t;
    cin.get();
    while (t--)
    {
        string s;
        getline(cin, s);
        cout << checkParanthesis(s) << endl;
    }
    return 0;
}