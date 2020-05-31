#include <iostream>
using namespace std;

// First the get the normal subarray sum using kadane
// Next, now for the corner elements i.e subarray including 0th and n-1th index
// find the total sum of the og array
// now invert the element's sign for all
// apply kadane again and get the sum of subarray that is the least contributing
// total sum = total sum - (-least contributing sum)
// largest subarray sum = max of total sum and normal sum

int kadaneAlgo(int a[], int n)
{
    int sum = 0, tsum = 0;
    for (int i = 0; i < n; i++)
    {
        tsum += a[i];
        if (tsum < 0)
            tsum = 0;
        sum = max(sum, tsum);
    }
    return sum;
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
        int normal_sum = 0;
        normal_sum = kadaneAlgo(a[i], n[i]);
        int corner_sum = 0;
        int total_sum = 0;
        for (int j = 0; j < n[i]; j++)
        {
            total_sum += a[i][j];
            //    invert the elements
            a[i][j] = -a[i][j];
        }
        corner_sum = total_sum + kadaneAlgo(a[i], n[i]);
        cout << max(normal_sum, corner_sum) << endl;
    }
    return 0;
}