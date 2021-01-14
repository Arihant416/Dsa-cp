/*
Author : Arihant Jain
github:https://github.com/Arihant416
linkedin : https://www.linkedin.com/in/arihant416

Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. The task is consider set bits of y in range [l, r] and set these bits in x also. Examples :

    Input  : x = 10, y = 13, l = 2, r = 3
    Output : x = 14
    Binary representation of 10 is 1010 and 
    that of y is 1101. There is one set bit
    in y at 3’rd position (in given range). 
    After we copy this bit to x, x becomes 1110
    which is binary representation of 14.

    Input  : x = 8, y = 7, l = 1, r = 2
    Output : x = 11
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

void setBitsInRangeLR(int &x, int y, int l, int r)
{
    if (l < 1 || r > 32)
        return;

    for (int i = l; i <= r; i++)
    {
        int mask = 1 << (i - 1);
        if (y & mask)
        {
            x = x | mask;
        }
    }
}

int32_t main()
{
    flash;

    int x, y, l, r;
    cin >> x >> y >> l >> r;
    cout << "x before setting bits in range " << x << endl;
    setBitsInRangeLR(x, y, l, r);
    cout << "x after setting bits in range " << x << endl;
    return 0;
}