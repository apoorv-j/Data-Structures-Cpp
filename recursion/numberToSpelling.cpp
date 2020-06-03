#include <bits/stdc++.h>
using namespace std;

string spellings[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string numberTospell(int n)
{
    if (n / 10 > 0)
        return numberTospell(n / 10) + " " + spellings[n % 10];

    return spellings[n % 10];
}
int main()
{
    int n;
    cin >> n;
    cout << numberTospell(n);
    return 0;
}