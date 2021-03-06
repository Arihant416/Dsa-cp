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

string findMaxPossibleNumber(vi &A, int N)
{
    sort(all(A), [](const int &x, const int &y) -> bool {
        string xy = to_string(x) + to_string(y);
        string yx = to_string(y) + to_string(x);
        return xy.compare(yx) > 0 ? 1 : 0;
    });
    string res;
    for (int &i : A)
    {
        res += (to_string(i));
    }
    return res;
}

int32_t main()
{
    flash;
    int N;
    cin >> N;
    vi A(N);
    for (auto &i : A)
    {
        cin >> i;
    }
    cout << findMaxPossibleNumber(A, N);
    return 0;
}