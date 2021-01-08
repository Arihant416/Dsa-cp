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

int smallestSubarrayLength(vl &A, ll N, ll X)
{
    if (N == 1)
        return A[0] > X ? 1 : -1;
    if (maxEl(A) > X)
        return 1;
    int currentSum(0), start(0), end(0), minLength(N + 1);
    while (end < N)
    {
        while (currentSum <= X && end < N)
        {
            currentSum += A[end++];
        }
        while (currentSum > X && start < N)
        {
            if (end - start < minLength)
            {
                minLength = end - start;
            }
            currentSum -= A[start++];
        }
    }
    return minLength;
}

int32_t main()
{
    flash;
    int T;
    cin >> T;
    while (T--)
    {
        ll N, X;
        cin >> N >> X;
        vl A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        cout << smallestSubarrayLength(A, N, X) << endl;
    }

    return 0;
}