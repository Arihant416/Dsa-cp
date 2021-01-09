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

int findMinSwaps(vi &A, int N, int K)
{
    int count(0), invalid(0), result(INT_MAX);
    for (int i = 0; i < N; i++)
    {
        if (A[i] <= K)
            count++;
    }
    for (int i = 0; i < count; i++)
    {
        if (A[i] > K)
            invalid++;
    }
    int i(0), j(count - 1);
    while (j < N)
    {
        result = min(result, invalid);
        j++;
        if (A[i] > K)
            invalid--;
        if (j < N && A[j] > K)
            invalid++;
        i++;
    }
    return result;
}

void solve()
{
    int N, K;
    cin >> N;
    vi A(N);
    for (int &i : A)
    {
        cin >> i;
    }
    cin >> K;
    cout << findMinSwaps(A, N, K) << endl;
    A.clear();
}

int32_t main()
{
    flash;
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}