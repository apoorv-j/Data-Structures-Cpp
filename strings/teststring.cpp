#include <iostream>
#include <algorithm>
using namespace std;

void removeDuplicate(char *a, int n)
{
    int i = 0, j = 1;
    while (j < n)
    {
        if (a[i] == a[j])
            j++;
        else
        {
            a[++i] = a[j++];
        }
    }
    // cout << j;
    a[i + 1] = '\0';
}
int main()
{
    char s[] = "ccoooding";
    removeDuplicate(s, sizeof(s) / sizeof(char));
    cout << s;
    return 0;
}