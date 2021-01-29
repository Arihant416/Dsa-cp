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

void print(vl &res)
{
    cout << res.size() - 1 << endl;
    for (auto &i : res)
        cout << i << " ";
}
vl primitiveCalc(ll N)
{
    vl result, A(N + 1);
    for (int i = 1; i < A.size(); i++)
    {
        A[i] = A[i - 1] + 1;
        if (i % 2 == 0)
            A[i] = min(A[i], 1 + A[i / 2]);
        if (i % 3 == 0)
            A[i] = min(A[i], A[i / 3] + 1);
    }
    int index = N;
    while (index > 1)
    {
        result.PB(index);
        if (A[index - 1] == A[index] - 1)
            index -= 1;
        else if (index % 2 == 0 && A[index / 2] == A[index] - 1)
            index /= 2;
        else
        {
            index /= 3;
        }
    }
    result.PB(1);
    reverse(all(result));
    return result;
}

void solve(ll N)
{
    auto res = primitiveCalc(N);
    print(res);
}

int32_t main()
{
    flash;
    ll N;
    cin >> N;
    solve(N);
    return 0;
}