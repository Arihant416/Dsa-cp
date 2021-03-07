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

int findMissingNumber(vi &A, int N)
{
    int number = 0;
    for (int i = 1; i <= N; i++)
    {
        number ^= i;
    }
    for (int &i : A)
    {
        number ^= i;
    }
    return number;
}
int findMissingNumberMath(vi &A, int N)
{
    long sum = N * (N + 1) / 2;
    long acc = accumulate(all(A), 0);
    return sum - acc;
}

int32_t main()
{
    flash;
    int N;
    cin >> N;
    vector<int> A(N - 1);
    for (int &i : A)
        cin >> i;
    cout << findMissingNumber(A, N) << endl;
    cout << findMissingNumberMath(A, N) << endl;
    return 0;
}