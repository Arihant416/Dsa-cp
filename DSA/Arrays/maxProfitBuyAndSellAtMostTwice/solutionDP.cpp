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

int maxProfit(vi &price, int N)
{
    vector<int> profitCache(N, 0);
    int maxPrice = price[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        if (price[i] > maxPrice)
            maxPrice = price[i];
        profitCache[i] = max(profitCache[i + 1], maxPrice - price[i]);
    }
    int minPrice = price[0];
    for (int i = 1; i < N; i++)
    {
        if (price[i] < minPrice)
        {
            minPrice = price[i];
        }
        profitCache[i] = max(profitCache[i - 1], profitCache[i] + price[i] - minPrice);
    }
    return profitCache[N - 1];
}

int32_t main()
{
    flash;

    int N;
    cin >> N;
    vi price(N);
    for (auto &i : price)
    {
        cin >> i;
    }
    cout << maxProfit(price, N);
    return 0;
}