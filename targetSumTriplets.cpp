#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int target;
    cin >> target;

    sort(a, a + n);
    for (int k = 0; k < n; k++)
    {
        if (a[k] < target)
        {
            int i = k + 1;
            int j = n - 1;
            while (i < j)
            {
                if (a[i] + a[j] == target - a[k])
                {
                    cout << a[k] << ", " << a[i] << " and " << a[j] << endl;
                    i++;
                    j--;
                }
                else if (a[i] + a[j] < target - a[k])
                    i++;
                else
                    j--;
            }
        }
    }
    return 0;
}