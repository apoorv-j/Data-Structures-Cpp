// piyush and magical park hackerblock practive
#include <iostream>
using namespace std;

int main()
{
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    char a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
    {
        if (s < k)
            break;
        for (int j = 0; j < m; j++)
        {
            s--;
            if (a[i][j] == '.')
                s -= 2;
            else if (a[i][j] == '*')
                s += 5;
            else if (a[i][j] == '#')
                break;
        }
        s++;
    }
    if (s > k)
    {
        cout << "Yes" << endl
             << s << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}