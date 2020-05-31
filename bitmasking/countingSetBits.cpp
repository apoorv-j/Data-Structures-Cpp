/* Given a number N, find the no. of set bits in the binary rep of the number */
#include <iostream>
#include <algorithm>
using namespace std;

int simpleCount(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1 > 0)
            count++;
        n = n >> 1;
    }
    return count;
}
int fastCount(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n & n - 1;
        count++;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    cout << simpleCount(n) << endl;
    cout << fastCount(n) << endl;

    return 0;
}