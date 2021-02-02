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

int countReversals(string &s)
{
    int N = s.size();
    // Pretty Obvious if N is odd the string cannot be balanced
    if (N & 1)
        return -1;
    stack<char> stack;
    int invC(0);
    for (char c : s)
    {
        if (c == '{')
            stack.push(c);
        else
        {
            if (stack.empty())
            {
                invC++;
                stack.push('{');
            }
            else
            {
                stack.pop();
            }
        }
    }
    if (!stack.empty())
    {
        invC += stack.size() / 2;
    }
    return invC;
}

int32_t main()
{
    flash;
    int testCount;
    cin >> testCount;
    while (testCount--)
    {
        /* A string containing curly braces */
        string s;
        cin >> s;
        cout << countReversals(s) << endl;
    }
    return 0;
}