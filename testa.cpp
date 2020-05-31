#include <iostream>
#include <algorithm>
using namespace std;

int max_value(long long int *a, int n)
{
    long long num = 0;
    for (int i = 0; i < n; i++)
    {
        num = max(a[i], num);
    }
    return num;
}
int main()
{
    // int n;
    // cin >> n;
    // long long int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    // cout << max_value(a, n);

    char *p;
    char sample_string[] = "codingjunction";
    p = sample_string;
    p += 6;
    printf("%s", p);
    return 0;
}