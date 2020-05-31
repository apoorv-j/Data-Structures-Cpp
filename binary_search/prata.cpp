// p pratas
// l cooks
// r rank 1-8
// n min  n/r pratas
#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int *rank, int p, int l, int min_time)
{
    int count[l];
    int tRank[l];
    for (int i = 0; i < l; i++)
    {
        tRank[i] = rank[i];
        count[i] = 2;
    }

    int pratas = 0;
    int ctime = 0, ntime = 0;
    for (int j = 0; j < l; j++)
    {
        ctime = 0;
        ntime = rank[j];
        while (ctime + ntime <= min_time)
        {
            p--;
            ctime += ntime;
            ntime += rank[j];
            if (p == 0)
                return true;
        }
    }

    return false;
}

int getMinMinutes(int *rank, int p, int l)
{
    int s = 0;
    int e = rank[l - 1] * p * (p + 1) / 2;
    int mid;
    int min_time = e;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (isPossible(rank, p, l, mid))
        {
            min_time = min(min_time, mid);
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return min_time;
}
int main()
{
    int t;
    cin >> t;
    int p[t], l[t];
    int *rank[t];
    for (int i = 0; i < t; i++)
    {
        cin >> p[i] >> l[i];
        rank[i] = new int[l[i]];
        for (int j = 0; j < l[i]; j++)
        {
            cin >> rank[i][j];
        }
    }
    for (int i = 0; i < t; i++)
    {
        sort(rank[i], rank[i] + l[i]);
        cout << getMinMinutes(rank[i], p[i], l[i]) << endl;
    }

    return 0;
}