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

int findKthSmallest(const vector<vi> &mat, int N, int K);

int32_t main()
{
    flash;
    int N, K;
    cin >> N >> K;
    vector<vi> mat(N, vi(N));
    for (auto &i : mat)
        for (auto &j : i)
            cin >> j;
    cout << findKthSmallest(mat, N, K);
    return 0;
}

int findKthSmallest(const vector<vi> &mat, int N, int K)
{
    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;
    for (int i = 0; i < N; i++)
    {
        // {mat[i][j], {i, j}}
        pq.push(MP(mat[0][i], MP(0, i)));
    }
    --K;
    while (K--)
    {
        auto top = pq.top();
        pq.pop();
        int i = top.second.first;
        int j = top.second.second;
        if (i + 1 < N)
        {
            ++i;
            pq.push({mat[i][j], {i, j}});
        }
    }
    return pq.top().first;
}