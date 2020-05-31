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
    int i = 0;
    int j = n - 1;
    sort(a, a + n);

    while (i < j)
    {
        if (a[i] + a[j] == target)
        {
            cout << a[i] << " and " << a[j] << endl;
            i++;
            j--;
        }
        else if (a[i] + a[j] < target)
            i++;
        else
            j--;
    }
    return 0;
}