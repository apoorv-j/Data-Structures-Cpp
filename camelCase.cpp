#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    cout << s[0];
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            cout << endl;
        cout << s[i];
    }

    return 0;
}