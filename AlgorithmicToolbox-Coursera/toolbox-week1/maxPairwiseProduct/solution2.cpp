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

ll maxProductPairwise(vl &A, int N)
{
    if (N < 2)
        return -1;
    if (N == 2)
        return A[0] * A[1];
    ll posA = INT_MIN, posB = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (A[i] >= posA)
        {
            posB = posA;
            posA = A[i];
        }
        else if (A[i] >= posB)
        {
            posB = A[i];
        }
    }
    return posA * posB;
}

int32_t main()
{
    flash;
    int N;
    cin >> N;
    vl A(N);
    for (auto &i : A)
        cin >> i;
    cout << maxProductPairwise(A, N);
    return 0;
}