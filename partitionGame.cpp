#include <bits/stdc++.h>
using namespace std;

// void game(int *a, int n, int lv, int hv)
// {
//     // int lIndex = find(a, a + n, lv) - a;
//     // int hIndex = find(a, a + n, hv) - a;

//     vector<int> v1, v2, v3, v4, v5;

//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] << " ";
//         if (a[i] < lv)
//             v1.push_back(a[i]);
//         else if (a[i] > hv)
//             v3.push_back(a[i]);
//         else if (a[i] == lv)
//             v4.push_back(a[i]);
//         else if (a[i] == hv)
//             v5.push_back(a[i]);
//         else
//             v2.push_back(a[i]);
//     }
//     cout << endl;

//     for (auto it : v1)
//         cout << it << " ";
//     for (auto it : v4)
//         cout << it << " ";
//     for (auto it : v2)
//         cout << it << " ";
//     for (auto it : v5)
//         cout << it << " ";
//     for (auto it : v3)
//         cout << it << " ";
// }

void game(int *a, int n, int lv, int hv)
{
    int s = 0, e = n - 1;
    int lIndex = find(a, a + n, lv) - a;
    int hIndex = find(a, a + n, hv) - a;
    int l = lIndex + 1;
    int h = hIndex - 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < lv)
        {
            swap(a[i], a[s]);
            s++;
        }
        else if (a[i] > hv)
        {
            swap(a[i], a[e]);
            e--;
        }
        else if (a[i] > lv && a[i] < hv && l < h)
        {
            swap(a[i], a[l]);
            lIndex++;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    int n[t];
    int *arr[t];
    int lowVal[t], highVal[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
        arr[i] = new int[n[i]];
        for (int j = 0; j < n[i]; j++)
        {
            cin >> arr[i][j];
        }
        cin >> lowVal[i] >> highVal[i];
    }
    for (int i = 0; i < t; i++)
    {

        game(arr[i], n[i], lowVal[i], highVal[i]);
        for (int j = 0; j < n[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
    }

    return 0;
}