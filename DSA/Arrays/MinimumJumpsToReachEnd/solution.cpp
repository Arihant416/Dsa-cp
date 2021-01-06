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

int findMinimumJumps(int A[], int N)
{
    // Base Cases
    if (N <= 1)
        return 0;
    if (A[0] == 0)
        return -1;
    int maxRange(A[0]), step(A[0]), jump(1);
    for (int i = 1; i < N; i++)
    {
        if (i >= N - 1)
            return jump;
        maxRange = max(maxRange, A[i] + i);
        step--;
        if (step == 0)
        {
            jump++;
            if (maxRange <= i)
            {
                return -1;
            }
            step = maxRange - i;
        }
    }
    return -1;
}

int solve()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    return findMinimumJumps(A, N);
}

int32_t main()
{
    flash;

    int testCount;
    cin >> testCount;
    for (int i = 0; i < testCount; i++)
    {
        cout << solve() << endl;
    }

    return 0;
}