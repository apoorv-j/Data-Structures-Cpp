#include <iostream>
using namespace std;

int main()
{
    char x;
    cin >> x;
    if (x >= 'A' && x <= 'Z')
        cout << 'U';
    else if (x >= 'a' && x <= 'z')
        cout << 'L';
    else
        cout << 'I';
    return 0;
}