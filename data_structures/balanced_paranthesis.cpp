#include <bits/stdc++.h>
using namespace std;

string checkParanthesis(string arr)
{
    stack<char> p;
    for (auto i : arr)
    {
        if (i == '(' or i == '{' or i == '[')
            p.push(i);
        else if (i == ')')
        {
            if (p.empty() or p.top() != '(')
                return "No";
            p.pop();
        }
        else if (i == '}')
        {
            if (p.empty() or p.top() != '{')
                return "No";
            p.pop();
        }
        else if (i == ']')
        {
            if (p.empty() or p.top() != ']')
                return "No";
            p.pop();
        }
    }
    if (p.empty())
    {
        return "Yes";
    }
    return "No";
}

int main()
{
    string s;
    getline(cin, s);
    cout << checkParanthesis(s);
    return 0;
}