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

int minOf3(int a, int b, int c)
{
    return min(a, min(b, c));
}

int computeEditDistanceRecursively(string &s, string &t, int s_size, int t_size)
{
    if (s_size == 0)
        return t_size;
    if (t_size == 0)
        return s_size;
    if (s[s_size - 1] == t[t_size - 1])
        return computeEditDistanceRecursively(s, t, s_size - 1, t_size - 1);
    int ins = computeEditDistanceRecursively(s, t, s_size, t_size - 1);
    int del = computeEditDistanceRecursively(s, t, s_size - 1, t_size);
    int rep = computeEditDistanceRecursively(s, t, s_size - 1, t_size - 1);
    return 1 + minOf3(ins, del, rep);
}

int32_t main()
{
    flash;
    string s, t;
    cin >> s >> t;
    cout << computeEditDistanceRecursively(s, t, s.size(), t.size());
    return 0;
}