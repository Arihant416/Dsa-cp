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

int solve(vi &coins, int amount, int numCoins)
{
    int dp[amount + 1];
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        dp[i] = INT_MAX;
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i)
            {
                int value = dp[i - coin];
                if (value != INT_MAX && value + 1 < dp[i])
                {
                    dp[i] = value + 1;
                }
            }
        }
    }
    return dp[amount];
}

int32_t main()
{
    flash;
    int amount;
    cin >> amount;
    int numCoins;
    cin >> numCoins;
    vi coins(numCoins);
    for (int &i : coins)
        cin >> i;
    cout << solve(coins, amount, numCoins);
    return 0;
}