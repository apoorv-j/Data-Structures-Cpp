#include <iostream>
#include <algorithm>
using namespace std;

int getSqrt(int n)
{
    int s = 0;
    int e = n;
    int mid = 0;
    int sqrt = 0;

    while (s <= e)
    {
        mid = (s + e) / 2;

        if ((mid * mid) <= n)
        {
            sqrt = mid;

            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return sqrt;
}
int main()
{
    int n;
    cin >> n;

    cout << "Sqrt: " << getSqrt(n);

    return 0;
}