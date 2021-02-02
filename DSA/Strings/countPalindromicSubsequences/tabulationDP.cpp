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

int countPalindromicSubs(string s)
{
    int N = s.size();
    int dp[2][N];
    memset(dp, 0, sizeof(dp));
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i; j < N; j++)
        {
            if (i == j)
                dp[i % 2][j] = 1;
            else if (s[i] == s[j])
                dp[i % 2][j] = dp[1 - i % 2][j] + dp[i % 2][j - 1] + 1;
            else
                dp[i % 2][j] = dp[1 - i % 2][j] + dp[i % 2][j - 1] - dp[1 - i % 2][j - 1];
        }
    }
    return dp[0][N - 1];
}

int32_t main()
{
    flash;

    string s;
    cin >> s;
    cout << countPalindromicSubs(s);
    return 0;
}