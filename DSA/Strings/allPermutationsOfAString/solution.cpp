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

int globalCounter = 0;

void findAllPermutations(string &s, string &partial, vector<bool> &chosen)
{
    if (partial.size() == s.size())
    {
        cout << partial << endl;
        globalCounter++;
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (!chosen[i])
        {
            chosen[i] = true;
            partial.PB(s[i]);
            findAllPermutations(s, partial, chosen);
            chosen[i] = false;
            partial.pop_back();
        }
    }
}

void printAllPermutations(string &s)
{
    globalCounter = 0;
    vector<bool> chosen(s.size(), false);
    string partial = "";
    findAllPermutations(s, partial, chosen);
    cout << globalCounter << endl;
    globalCounter = 0;
}

int32_t main()
{
    flash;
    string s;
    cin >> s;
    printAllPermutations(s);
    return 0;
}