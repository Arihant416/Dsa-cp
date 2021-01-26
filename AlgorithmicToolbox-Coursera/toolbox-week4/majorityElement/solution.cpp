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

int getCandidate(vi &A, int N)
{
    int majorityIndex = 0;
    int count = 1;
    for (int i = 1; i < N; i++)
    {
        if (A[i] == A[majorityIndex])
            count++;
        else
            count--;
        if (count == 0)
        {
            majorityIndex = i;
            count = 1;
        }
    }
    return A[majorityIndex];
}

bool hasMajorityElement(vi &A, int N)
{
    int candidate = getCandidate(A, N);
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        count += (A[i] == candidate ? 1 : 0);
    }
    return count > N / 2;
}

int32_t main()
{
    flash;
    int N;
    cin >> N;
    vi A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << hasMajorityElement(A, N) << endl;
    return 0;
}