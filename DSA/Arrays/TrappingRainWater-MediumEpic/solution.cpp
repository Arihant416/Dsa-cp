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

ll a[10000000];
ll TrappingWater(ll n)
{
    vector<pl> hash(n);
    hash[0] = {a[0], a[0]};
    hash[n - 1] = {a[n - 1], a[n - 1]};
    for (int i = 1; i < n; i++)
    {
        hash[i].first = max(a[i], hash[i - 1].first);
    }
    for (int j = n - 2; j > 0; --j)
    {
        hash[j].second = max(a[j], hash[j + 1].second);
    }
    ll res(0);
    for (int i = 0; i < n; i++)
    {
        res += abs(a[i] - min(hash[i].first, hash[i].second));
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << TrappingWater(n) << endl;
    }
    return 0;
}