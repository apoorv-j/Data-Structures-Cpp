#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    queue<char> q;
    int freq[27] = {0};

    int max_size = 0;
    for (int i = 0; i < n; i++)
    {
        //update freq and queue
        q.push(arr[i]);
        freq[arr[i] - 'a']++;

        while (freq[arr[i] - 'a'] > 1)
        {
            q.pop();
            freq[q.front() - 'a']--;
        }
        max_size = max(max_size, (int)q.size());
    }
    cout << max_size;

    return 0;
}