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

ll getPisanoPeriod(ll M)
{
    int prev(0), current(1), result = 1;
    for (int i = 0; i < M * M; i++)
    {
        result = (prev + current) % M;
        prev = current;
        current = result;
        if (prev == 0 && current == 1)
            return i + 1;
    }
}

ll findfibNmodM(ll N, ll M)
{
    N = N % getPisanoPeriod(M);
    if (N <= 1)
        return N;
    int prev = 0, current(1), result = prev + current;
    for (int i = 1; i < N; i++)
    {
        result = (prev + current) % M;
        prev = current;
        current = result;
    }
    return current % M;
}

int32_t main()
{
    flash;
    ll N, M;
    cin >> N >> M;
    cout << findfibNmodM(N, M);
    return 0;
}