#include <bits/stdc++.h>
using namespace std;

int main()
{
    int freq[27] = {0};
    queue<char> q;
    char data;
    cin >> data;
    while (data != '.')
    {
        freq[data - 'a']++;
        q.push(data);

        while (freq[q.front() - 'a'] != 1 and !q.empty())
            q.pop();
        if (q.empty())
            cout << "_";
        else
            cout << q.front();

        cin >> data;
    }

    return 0;
}

// input
// aabccbcd.