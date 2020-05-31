#include <iostream>
#include <algorithm>
using namespace std;
void bruteForce(int *a, int n) //O(n^3)
{
    int sum = 0;
    int maxi, maxj;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int tsum = 0;
            for (int k = i; k <= j; k++)
            {
                // cout << a[k] << ",";
                tsum += a[k];
            }
            if (tsum > sum)
            {
                sum = tsum;
                maxi = i;
                maxj = j;
            }
            // cout << endl;
            // cout << tsum << endl;
        }
    }
    cout << sum << endl;
    for (int i = maxi; i <= maxj; i++)
        cout << a[i] << " ";
    cout << endl;
}
void bruteForce2(int *a, int n) //O(n^2)
{
    int sum = 0;
    int maxi, maxj;
    for (int i = 0; i < n; i++)
    {

        int tsum = 0;
        for (int j = i; j < n; j++)
        {

            tsum += a[j];
            if (tsum > sum)
            {
                sum = tsum;
                maxi = i;
                maxj = j;
            }
            // cout << endl;
            // cout << tsum << endl;
        }
    }
    cout << sum << endl;
    for (int i = maxi; i <= maxj; i++)
        cout << a[i] << " ";
    cout << endl;
}
void cumulativeSum(int *a, int n) //O(n^2)
{
    int sum = 0;
    int maxi, maxj;
    int cumsum[n];
    cumsum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        cumsum[i] = cumsum[i - 1] + a[i];
        // cout << cumsum[i] << " ";
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int tsum = 0;
            tsum = cumsum[j] - cumsum[i - 1];
            if (tsum > sum)
            {
                sum = tsum;
                maxi = i;
                maxj = j;
            }
            // cout << endl;
            // cout << tsum << endl;
        }
    }
    cout << sum << endl;
    for (int i = maxi; i <= maxj; i++)
        cout << a[i] << " ";
    cout << endl;
}

void kadaneAlgo(int a[], int n) //O(n)
{
    int sum = 0, tsum = 0;
    for (int i = 0; i < n; i++)
    {
        tsum += a[i];
        if (tsum < 0)
            tsum = 0;
        sum = max(sum, tsum);
    }
    cout << "Maximum Subarray Sum is " << sum << endl;
}
int main()
{
    int a[] = {-4, 1, 3, -2, 6, 2, -1, -4, -7};
    int n = sizeof(a) / sizeof(int);
    bruteForce(a, n);
    bruteForce2(a, n);
    cumulativeSum(a, n);
    kadaneAlgo(a, n);
    return 0;
}