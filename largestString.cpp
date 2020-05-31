#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.get();
    char a[2][1000];
    string s1, s2;
    int max_length = 0;
    for (int i = 0; i < n; i++)
    {
        // memset(a[0], '\0', 1000);
        // cin.getline(a[0], 1000);
        getline(cin, s1);
        // int cur_len = strlen(a[0]);
        int cur_len = s1.length();
        if (cur_len > max_length)
        {
            max_length = cur_len;
            s2 = s1;
            // s2.copy(s1,cur_len);
        }
    }
    cout << s2 << endl
         << max_length << endl;

    return 0;
}