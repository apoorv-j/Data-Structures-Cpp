#include <bits/stdc++.h>
using namespace std;

bool getSubarrays(int *in, int sum, int i)
{
    if (in[i + 1] == '\0')
    {
        if (sum + in[i] == 0)
            return true;
        return false;
    }

    return getSubarrays(in, sum, i + 1) or getSubarrays(in, sum + in[i], i + 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (getSubarrays(arr, 0, 0))
            cout << "Yes";

        else
            cout << "No";

        cout << endl;
    }
    return 0;
}