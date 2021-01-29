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

int findLCSMemoization(string &s, string &t, int N, int M, vector<vi> &dp)
{
    if (N == 0 || M == 0)
        return 0;
    if (dp[N - 1][M - 1] != 0)
        return dp[N - 1][M - 1];
    if (s[N - 1] == t[M - 1])
    {
        dp[N - 1][M - 1] = 1 + findLCSMemoization(s, t, N - 1, M - 1, dp);
        return dp[N - 1][M - 1];
    }
    else
    {
        dp[N - 1][M - 1] = max(findLCSMemoization(s, t, N - 1, M, dp), findLCSMemoization(s, t, N, M - 1, dp));
        return dp[N - 1][M - 1];
    }
}

int32_t main()
{
    flash;
    string s, t;
    cin >> s >> t;
    vector<vi> dp(s.size(), vi(t.size(), 0));
    cout << findLCSMemoization(s, t, s.size(), t.size(), dp);
    return 0;
}