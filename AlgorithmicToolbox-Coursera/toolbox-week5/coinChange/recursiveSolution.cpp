#include <bits/stdc++.h>
using namespace std;

int findChangeRecursively(vector<int> &denominations, int target)
{
    if (target == 0)
        return 0;
    int minCoins = INT_MAX;
    for (auto &i : denominations)
    {
        if (target >= i)
        {
            int numCoins = findChangeRecursively(denominations, target - i);
            if (numCoins + 1 < minCoins)
            {
                minCoins = numCoins + 1;
            }
        }
    }
    return minCoins;
}

int main()
{
    int target;
    cin >> target;
    int numCoin;
    cin >> numCoin;
    vector<int> denominations(numCoin);
    for (auto &i : denominations)
        cin >> i;
    cout << findChangeRecursively(denominations, target);
}