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

ll getPisanoPeriod(int num)
{
    ll prev = 0, current = 1, res(prev + current);
    for (int i = 0; i < num * num; i++)
    {
        res = (current + prev) % num;
        prev = current;
        current = res;
        if (prev == 0 && res == 1)
            return i + 1;
    }
}

ll solve(ll N)
{
    ll remainder = N % getPisanoPeriod(10);
    ll f0 = 0, f1 = 1, res = remainder;
    for (int i = 1; i < remainder; i++)
    {
        res = (f0 + f1) % 10;
        f0 = f1;
        f1 = res;
    }
    return res % 10;
}

ll squareLastDigit(ll N)
{
    return (solve(N + 1) * solve(N)) % 10;
}

int32_t main()
{
    flash;
    ll N;
    cin >> N;
    cout << squareLastDigit(N);
    return 0;
}