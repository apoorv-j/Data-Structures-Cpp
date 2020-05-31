#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int freq[3] = {0};
    for (int i = 0; i < n; i++)
        freq[a[i]]++;

    for (int i = 0; i < 3; i++)
    {
        // cout<<freq[i];
        while (freq[i] > 0)
        {
            cout << i << endl;
            freq[i]--;
        }
    }
    return 0;
}