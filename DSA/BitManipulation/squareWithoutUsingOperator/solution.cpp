/*
Author : Arihant Jain
github:https://github.com/Arihant416
linkedin : https://www.linkedin.com/in/arihant416

Given an integer n, calculate the square of a number without using *, / and pow(). 

    Examples : 

    Input: n = 5
    Output: 25

    Input: 7
    Output: 49

    Input: n = 12
    Output: 144

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

ll square(ll N)
{
    if (N == 0)
        return 0;

    if (N < 0)
        N = -N;

    // Floor(N/2) using Right Shift
    int num = N >> 1;

    // If N is even
    if (N % 2 == 0)
    {
        return (square(num) << 2);
    }
    else
    {
        return ((square(num) << 2) + (num << 2) + 1);
    }
}

int32_t main()
{
    flash;
    ll N;
    cin >> N;
    cout << square(N) << endl;
    return 0;
}