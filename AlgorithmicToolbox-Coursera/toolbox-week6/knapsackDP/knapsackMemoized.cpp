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

int findMaxMemoized(vi &w, vi &v, int W, int N)
{
    if (N == 0 || W == 0)
    {
        return 0;
    }
    if (dp[N][W] != 0)
    {
        return dp[N][W];
    }
    if (w[N - 1] > W)
    {
        dp[N - 1][W] = findMaxMemoized(w, v, W, N - 1);
        return dp[N - 1][W];
    }
    else
    {
        int one = v[N - 1] + findMaxMemoized(w, v, W - w[N - 1], N - 1);
        int two = findMaxMemoized(w, v, W, N - 1);
        dp[N - 1][W] = max(one, two);
        return dp[N - 1][W];
    }
}

int32_t main()
{
    flash;
    int N, W;
    cin >> N >> W;
    dp = vector<vi>(N + 1, vi(W + 1, 0));
    vi w(N), v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << findMaxMemoized(w, v, W, N);
    return 0;
}