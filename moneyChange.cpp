#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int money;
    cout << "Money Amount :";
    cin >> money;
    int n = sizeof(coins) / sizeof(int);
    cout << "coins used : ";
    while (money > 0)
    {
        auto cAdd = upper_bound(coins, coins + n, money);
        int cIndex = cAdd - coins;
        // cout << cIndex << " ";
        money = money - coins[cIndex - 1];
        // cout << "Money : " << money << " ";
        cout << coins[cIndex - 1] << ", ";
    }
    cout << endl;

    return 0;
}