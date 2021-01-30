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

int findMaxValRecursive(vi &weight, vi &value, int W, int N)
{
    if (N == 0 || W == 0)
        return 0;
    if (weight[N - 1] > W)
        return findMaxValRecursive(weight, value, W, N - 1);
    else
    {
        return max(value[N - 1] + findMaxValRecursive(weight, value, W - weight[N - 1], N - 1), findMaxValRecursive(weight, value, W, N - 1));
    }
}

int32_t main()
{
    flash;
    int N, W;
    cin >> N >> W;
    vi weight(N), value(N);
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }
    cout << findMaxValRecursive(weight, value, W, N);
    return 0;
}