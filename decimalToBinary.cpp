#include <iostream>
#include <algorithm>
using namespace std;

int decToBin(int n)
{
    int pow = 1;
    int res = 0;
    while (n > 0)
    {
        if (n & 1 > 0)
        {
            res += pow;
        }
        pow *= 10;
        n = n >> 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << decToBin(n) << endl;

    return 0;
}