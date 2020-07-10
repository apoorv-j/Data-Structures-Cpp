#include <bits/stdc++.h>
using namespace std;

stack<int> reverseStack(stack<int> s)
{
    stack<int> s2;
    while (!s.empty())
    {
        s2.push(s.top());
        s.pop();
    }
    return s2;
}

void transfer(stack<int> &s1, stack<int> &s2, int itr)
{
    while (itr--)
    {
        int temp = s1.top();
        s2.push(temp);
        s1.pop();
    }
}

void reverseUsing1Stack(stack<int> &s)
{
    stack<int> s2;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int temp = s.top();
        s.pop();
        transfer(s, s2, n - i - 1);
        s.push(temp);
        transfer(s2, s, n - i - 1);
    }
}

void insertAtBottom(stack<int> &s, int data)
{
    if (s.empty())
    {
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottom(s, data);
    s.push(temp);
}

void reverseStackRecursive(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    reverseStackRecursive(s);
    insertAtBottom(s, x);
}

int main()
{
    stack<int> s;
    for (int i = 1; i < 6; i++)
    {
        s.push(i);
    }
    // reverseStackRecursive(s);
    reverseUsing1Stack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}