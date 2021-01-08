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

vector<int> findMajorityElementNK(vi A, int N, int K)
{
    vi ans;
    uimap hash;
    for (auto i : A)
        hash[i]++;
    for (auto i : hash)
    {
        if (i.second > N / K)
        {
            ans.PB(i.first);
        }
    }
    return ans;
}

int32_t main()
{
    flash;

    int N, K;
    cin >> N >> K;
    vi A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vi res = findMajorityElementNK(A, N, K);
    for (auto &i : res)
    {
        cout << i << " ";
    }
    return 0;
}