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

int calculateMaxValue(vector<pi> &wv, int N, int W)
{
    vi dp(W + 1, 0);
    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (wv[j].first <= i)
            {
                dp[i] = max(dp[i], dp[i - wv[j].first] + wv[j].second);
            }
        }
    }
    return dp[W];
}

int32_t main()
{
    flash;
    int N, W;
    cin >> N >> W;
    vector<pi> wv(N);
    for (int i = 0; i < N; i++)
    {
        cin >> wv[i].first >> wv[i].second;
    }
    cout << calculateMaxValue(wv, N, W);
    return 0;
}