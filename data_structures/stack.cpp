#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
private:
    vector<T> arr;
    T last = NULL;

public:
    Stack()
    {
        arr.clear();
    }
    Stack(T data)
    {
        arr.clear();
        push(data);
    }

    void push(T data)
    {
        arr.push_back(data);
        updateTop();
    }

    bool isEmpty()
    {
        return arr.size() == 0;
    }

    void updateTop()
    {
        last = arr[arr.size() - 1];
    }

    void pop()
    {
        if (isEmpty())
            return;
        arr.pop_back();
        updateTop();
    }

    T top()
    {
        return last;
    }
    // ~Stack<T>();
};

int main()
{
    Stack<int> s;
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.top() << " ";
    s.pop();
    cout << s.top() << " ";
    return 0;
}