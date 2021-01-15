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
    string findLongestPalindromeUsingDP(string &s);
};

string Solution::findLongestPalindromeUsingDP(string &s)
{
    int N = s.size(), maxLength = 1;
    if (N == 1)
        return s;
    vector<vector<bool>> table(N, vector<bool>(N, false));
    // All substrings of Length 1 are palindromic in nature
    for (int i = 0; i < N; i++)
        table[i][i] = true;

    // Checking for length 2
    int start = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            table[i][i + 1] = true;
            maxLength = 2;
            start = i;
        }
    }

    // Checking for substrings with length > 2

    // Here len is length of substring
    for (int len = 3; len <= N; ++len)
    {
        // i is the starting index
        for (int i = 0; i < N - len + 1; i++)
        {
            // j is end index
            int j = i + len - 1;
            if (table[i + 1][j - 1] && s[i] == s[j])
            {
                table[i][j] = true;
                if (len > maxLength)
                {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }
    return s.substr(start, maxLength);
}

int32_t main()
{
    flash;

    string s;
    cin >> s;
    Solution ob;
    cout << ob.findLongestPalindromeUsingDP(s) << endl;
    return 0;
}