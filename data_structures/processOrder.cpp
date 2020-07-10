#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> call, ideal;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        call.push(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ideal.push(temp);
    }
    int t = 0;
    while (!ideal.empty())
    {
        int ifront = ideal.front();
        int cfront = call.front();

        call.pop();
        if (ifront == cfront)
        {
            ideal.pop();
        }
        else
        {
            call.push(cfront);
        }
        t++;
    }

    cout << t;
    return 0;
}