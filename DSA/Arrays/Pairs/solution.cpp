/*
Author : Arihant Jain
github:https://github.com/Arihant416
linkedin : https://www.linkedin.com/in/arihant416


Question statement: 
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K
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

int countPairsWithSumK(vi A, int N, int K)
{
    int count(0);
    uimap hash;
    for (int i = 0; i < N; i++)
    {
        hash[A[i]]++;
    }
    for (int i = 0; i < N; i++)
    {
        if (hash.count(K - A[i]))
        {
            if (K - A[i] == A[i])
            {
                hash[A[i]]--;
                count += hash[K - A[i]];
            }
            else
            {
                count += hash[K - A[i]];
                hash[A[i]]--;
            }
        }
    }
    return count;
}

int32_t main()
{
    flash;
    int N, K;
    cin >> N >> K;
    vi A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cout << countPairsWithSumK(A, N, K);
    return 0;
}