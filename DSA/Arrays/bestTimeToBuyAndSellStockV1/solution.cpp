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
#define all(prices) begin(prices), end(prices)
#define maxEl(prices) *max_element(all(prices))
#define minEl(prices) *min_element(all(prices))
#define uimap unordered_map<int, int>
#define ulmap unordered_map<ll, ll>
#define mppii map<pi, int>

int findBestTime(vi &prices, int N)
{
    if (N <= 1)
        return 0;
    if (N == 2)
        return prices[1] > prices[0] ? prices[1] - prices[0] : 0;
    int buy = prices[0];
    int maxPrice(0);
    for (int i = 1; i < N; i++)
    {
        buy = min(buy, prices[i]);
        maxPrice = max(maxPrice, prices[i] - buy);
    }
    return maxPrice;
}

int32_t main()
{
    flash;

    int N;
    cin >> N;
    vi prices(N);
    for (int i = 0; i < N; i++)
        cin >> prices[i];
    cout << findBestTime(prices, N);
    return 0;
}