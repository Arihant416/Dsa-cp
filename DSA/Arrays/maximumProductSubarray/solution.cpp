/*
Author : Arihant Jain
github:https://github.com/Arihant416
linkedin : https://www.linkedin.com/in/arihant416


Question Statement : Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray
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

ll maximumProductSubarray(vl A, int N)
{
    ll minProduct(A[0]), maxProduct(A[0]), ans(A[0]);
    for (int i = 1; i < N; i++)
    {
        if (A[i] < 0)
            swap(maxProduct, minProduct);
        maxProduct = max<ll>(maxProduct * A[i], A[i]);
        minProduct = min<ll>(minProduct * A[i], A[i]);
        ans = max(maxProduct, ans);
    }
    return ans;
}

int32_t main()
{
    flash;

    ll N;
    cin >> N;
    vl A(N);
    for (auto &i : A)
    {
        cin >> i;
    }
    cout << maximumProductSubarray(A, N);

    return 0;
}