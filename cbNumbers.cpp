#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.get();
    string s;
    getline(cin, s);
    int len = 0;
    int res = 0;
    bool flag = true;
    for (int i = 0; i < t; i++)
    {
        flag = true;
        for (int j = 2; j < sqrt(s[i]); j++)
        {
            if (s[i] % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            res++;
        }
    }
    return 0;
}