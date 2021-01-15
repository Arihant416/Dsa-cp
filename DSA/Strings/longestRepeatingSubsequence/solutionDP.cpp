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

class Solution
{
public:
    int findLengthOfLongestRepeatingSubsequence(string &s);
};

int Solution::findLengthOfLongestRepeatingSubsequence(string &s)
{
    int N = s.size();
    int dp[N + 1][N + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (s[i - 1] == s[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[N][N];
}

int32_t main()
{
    flash;
    string s;
    cin >> s;
    Solution ob;
    cout << ob.findLengthOfLongestRepeatingSubsequence(s) << endl;
    return 0;
}