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

int solve(int I, int N, int Q)
{
    if (N % 2 == 0)
    {
        return N / 2;
    }
    else
    {
        if (I == 1)
        {
            if (Q == 1)
            {
                return int(N / 2);
            }
            else
            {
                return int(N / 2) + 1;
            }
        }
        else
        {
            if (Q == 1)
            {
                return int(N / 2) + 1;
            }
            else
            {
                return int(N / 2);
            }
        }
    }
}

int32_t main()
{
    flash;
    int tests;
    cin >> tests;
    while (tests--)
    {
        int numGames;
        cin >> numGames;
        while (numGames--)
        {
            int I, N, Q;
            cin >> I >> N >> Q;
            cout << solve(I, N, Q) << endl;
        }
    }
    return 0;
}