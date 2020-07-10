#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{

    queue<T> q1, q2;
    int size;

public:
    Stack()
    {
        size = 0;
    }

    void push(T data)
    {
        q1.push(data);
        size++;
    }

    void pop()
    {
        if (q1.empty())
            return;
        T temp = q1.front();
        q1.pop();
        while (!q1.empty())
        {
            q2.push(temp);
            temp = q1.front();
            q1.pop();
        }
        queue<T> t = q1;
        q1 = q2;
        q2 = t;
    }
    T top()
    {
        T temp;
        while (!q1.empty())
        {
            temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        queue<T> t = q1;
        q1 = q2;
        q2 = t;
        return temp;
    }
    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "top : " << s.top() << endl;
    s.pop();
    cout << "top : " << s.top() << endl;

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}