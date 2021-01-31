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

vector<vi> dp;
int findMaxAmount(vi &weight, int N, int W)
{
    if (N == 0 || W == 0)
        return 0;
    if (dp[N][W] != INT_MIN)
    {
        return dp[N][W];
    }
    if (weight[N - 1] > W)
    {
        dp[N - 1][W] = findMaxAmount(weight, N - 1, W);
        return dp[N - 1][W];
    }
    else
    {
        dp[N - 1][W] = max(weight[N - 1] + findMaxAmount(weight, N - 1, W - weight[N - 1]), findMaxAmount(weight, N - 1, W));
        return dp[N - 1][W];
    }
}

int32_t main()
{
    flash;
    int W, N;
    cin >> W >> N;
    dp = vector<vector<int>>(N + 1, vi(W + 1, INT_MIN));
    vi weight(N);
    for (int &i : weight)
        cin >> i;
    cout << findMaxAmount(weight, N, W);
    return 0;
}