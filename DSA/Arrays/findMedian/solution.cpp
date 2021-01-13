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
    int find_median(vi &V, int N)
    {
        if (N == 1)
            return V[0];
        if (N == 2)
            return (V[0] + V[1]) / 2;
        sort(all(V));
        if (N & 1)
            return V[N / 2];
        return (V[N / 2] + V[N / 2 - 1]) / 2;
    }
};

void solve()
{
    int N;
    cin >> N;
    vi V(N);
    for (auto &i : V)
        cin >> i;
    Solution ob;
    cout << ob.find_median(V, N) << endl;
}

int32_t main()
{
    flash;
    int testCount;
    cin >> testCount;
    while (testCount--)
    {
        solve();
    }
    return 0;
}