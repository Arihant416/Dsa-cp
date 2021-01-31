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

int wordBreak(string A, vector<string> &B)
{
    //code here
    set<string> d;
    for (auto &i : B)
        d.insert(i);
    int len = A.size();
    vector<bool> dp(len + 1, false);
    dp[0] = true;
    for (int i = 1; i <= len; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j] && d.find(A.substr(j, i - j)) != d.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[len];
}

int32_t main()
{
    flash;
    int N;
    cin >> N;
    vector<string> dict(N);
    for (auto &word : dict)
        cin >> word;
    string line;
    cin >> line;
    cout << wordBreak(line, dict);
    return 0;
}