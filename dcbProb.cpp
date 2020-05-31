#include <bits/stdc++.h>
using namespace std;
#define ll long long

int getResult(int n)
{
    int count = 0;
    bool flag = true;
    for (int i = 0; i <= n; i++)
    {
        flag = true;
        int t = i;
        while (t)
        {
            if (t & 1 > 0)
            {
                t >>= 1;
                if (t & 1 > 0)
                {
                    flag = false;
                    break;
                }
            }
            t >>= 1;
        }
        if (flag)
        {
            count++;
        }
    }

    return count;
}
int main()
{
    int t;
    cin >> t;
    int n[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < t; i++)
    {
        cout << getResult(n[i]) << endl;
    }

    return 0;
}