#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int s = *min_element(a, a + n);
    int e = *max_element(a, a + n);

    int freq[(e - s) + 1] = {0};
    for (int i = 0; i < n; i++)
        freq[a[i] - s]++;

    for (int i = 0; i <= e - s; i++)
    {
        // cout<<freq[i];
        while (freq[i] > 0)
        {
            cout << i + s << " ";
            freq[i]--;
        }
    }
    return 0;
}