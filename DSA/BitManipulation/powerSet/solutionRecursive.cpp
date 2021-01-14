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

void recursiveUtil(string &s, string partial, vector<string> &result, int index)
{
    result.PB(partial);
    for (int i = index; i < s.length(); i++)
    {
        partial.PB(s[i]);
        recursiveUtil(s, partial, result, i + 1);
        partial.pop_back();
    }
}

vector<string> findAllPossibleSubStringsUtil(string &s)
{
    vector<string> result;
    string partial;
    int index = 0;
    recursiveUtil(s, partial, result, index);
    return result;
}

void print(vector<string> &res)
{
    for (auto &i : res)
    {
        cout << i << " ";
    }
}

void findAllPossibleSubStrings(string &s)
{
    auto res = findAllPossibleSubStringsUtil(s);
    print(res);
}

int32_t main()
{
    flash;
    string s;
    cin >> s;
    findAllPossibleSubStrings(s);

    return 0;
}