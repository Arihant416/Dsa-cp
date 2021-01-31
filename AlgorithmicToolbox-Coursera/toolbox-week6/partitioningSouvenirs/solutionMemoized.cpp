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

map<string, int> cache;

bool checker(vi &A, int N, int sub1, int sub2, int sub3, int j)
{
    string s = to_string(sub1) + "_" + to_string(sub2) + to_string(j);
    if (j == N)
    {
        if (sub1 == sub2 && sub2 == sub3)
            return true;
        else
            return false;
    }
    if (cache.find(s) != cache.end())
        return cache[s];
    else
    {
        int p = checker(A, N, sub1 + A[j], sub2, sub3, j + 1);
        int q = checker(A, N, sub1, sub2 + A[j], sub3, j + 1);
        int r = checker(A, N, sub1, sub2, sub3 + A[j], j + 1);
        return cache[s] = max(p, max(q, r));
    }
}

bool isPartitionPossible(vi &A, int N)
{
    int sum = accumulate(all(A), 0);
    int sub1(0), sub2(0), sub3(0);
    if (sum % 3 != 0 || N < 3)
        return false;
    if (checker(A, N, sub1, sub2, sub3, 0) == 1)
        return true;
    else
        return false;
}

int32_t main()
{
    flash;
    int N;
    cin >> N;
    vi A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    cout << isPartitionPossible(A, N);
    return 0;
}