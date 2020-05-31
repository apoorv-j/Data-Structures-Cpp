#include <iostream>
using namespace std;
void kadaneAlgo(int a[], int n)
{
    int sum = 0, tsum = 0;
    for (int i = 0; i < n; i++)
    {
        tsum += a[i];
        if (tsum < 0)
            tsum = 0;
        sum = max(sum, tsum);
    }
    cout << sum << endl;
}
int main()
{
    int t;
    cin >> t;
    int n[t];
    int *a[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
        a[i] = new int[n[i]];
        for (int k = 0; k < n[i]; k++)
            cin >> a[i][k];
    }
    for (int i = 0; i < t; i++)
    {
        kadaneAlgo(a[i], n[i]);
    }
    return 0;
}