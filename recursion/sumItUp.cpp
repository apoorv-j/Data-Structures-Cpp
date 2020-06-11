/* 
You are given an array of numbers and a target number(T) , 
print all unique combinations in the array whose sum equals the target number T. 
Note that each number in the array may only be used once in the combination.
 */
#include <bits/stdc++.h>
using namespace std;

void getPermutation(int *arr, int *out, int sum, int i, int n, int target, set<int *> &s)
{
    if (i == n)
        return;

    if (sum == target)
    {
        arr[i] = '\0';
        s.insert(out);
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    set<int[]> s;
    int t;
    cin >> t;
    int temp[n] = {0};
    getPermutation(arr, temp, 0, 0, n, t, s);
    for (auto it : s)
    {
        for (int i = 0; i < it[i] != '\0'; i++)
        {
            cout << it[i] << " ";
        }
        cout << endl;
    }

    return 0;
}