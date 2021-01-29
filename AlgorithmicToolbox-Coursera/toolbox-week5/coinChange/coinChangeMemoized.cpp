/*
Author : Arihant Jain
github:https://github.com/Arihant416
linkedin : https://www.linkedin.com/in/arihant416
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned ll
#define PB push_back
#define MP make_pair
#define flash ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define vi vector<int>
#define vl vector<ll>
#define vll vector<ull>
#define mpi map<int, int>
#define mpl map<ll, ll>
#define mpll map<ull, ull>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define all(a) begin(a), end(a)
#define maxEl(a) *max_element(all(a))
#define minEl(a) *min_element(all(a))
#define uimap unordered_map<int, int>
#define ulmap unordered_map<ll, ll>
#define mppii map<pi, int>

int coinChangeUtil(vi &coins, int amount, vi &dp)
{
    if (amount < 0)
        return -1;
    if (amount == 0)
        return 0;
    if (dp[amount] != 0)
        return dp[amount];
    int res(INT_MAX);
    for (int coin : coins)
    {
        int currentValue = coinChangeUtil(coins, amount - coin, dp);
        if (currentValue >= 0 && currentValue < res)
        {
            res = currentValue + 1;
        }
    }
    dp[amount] = (res == INT_MAX ? -1 : res);
    return dp[amount];
}

int coinChangeMemoized(vi &coins, int amount)
{
    vi dp(100001, 0);
    if (amount < 1)
        return 0;
    return coinChangeUtil(coins, amount, dp);
}

int32_t main()
{
    flash;
    int amount;
    cin >> amount;
    int numCoins;
    cin >> numCoins;
    vector<int> coins(numCoins, 0);
    for (int &i : coins)
        cin >> i;
    cout << coinChangeMemoized(coins, amount);
    return 0;
}