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

int counterUtil(string &s, int i, int j, vector<vi> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == j)
        return dp[i][j] = 1;
    if (s[i] == s[j])
    {
        return dp[i][j] = counterUtil(s, i + 1, j, dp) + counterUtil(s, i, j - 1, dp) + 1;
    }
    else
    {
        return dp[i][j] = counterUtil(s, i + 1, j, dp) + counterUtil(s, i, j - 1, dp) - counterUtil(s, i + 1, j - 1, dp);
    }
}

int countPalindromicSubs(string &s)
{
    int n = s.size();
    vector<vi> dp(n, vi(n, -1));
    return counterUtil(s, 0, s.size() - 1, dp);
}

int32_t main()
{
    flash;
    int testCount;
    cin >> testCount;
    while (testCount--)
    {
        string s;
        cin >> s;
        cout << countPalindromicSubs(s) << endl;
    }
    return 0;
}