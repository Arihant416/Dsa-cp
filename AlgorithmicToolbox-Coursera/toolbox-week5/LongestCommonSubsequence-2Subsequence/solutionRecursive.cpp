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

int findLCSRecursive(vi &A, vi &B, int N, int M)
{
    if (N == 0 || M == 0)
        return 0;
    if (A[N - 1] == A[M - 1])
        return 1 + findLCSRecursive(A, B, N - 1, M - 1);
    else
        return max(findLCSRecursive(A, B, N - 1, M), findLCSRecursive(A, B, N, M - 1));
}

int32_t main()
{
    flash;
    int N, M;
    cin >> N;
    vi A(N);
    for (auto &i : A)
        cin >> i;
    cin >> M;
    vi B(M);
    for (auto &i : B)
        cin >> i;
    cout << findLCSRecursive(A, B, N, M);
    return 0;
}