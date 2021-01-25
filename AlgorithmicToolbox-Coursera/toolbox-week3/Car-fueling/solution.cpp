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

int minRefill(vi &A, int D, int M)
{
    A.PB(D);
    int left = D, noStop = 0, covered = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (left == 0)
            break;
        else if (A[i + 1] - A[i] > M)
            return -1;
        else if (covered + M >= A[i] && covered + M < A[i + 1])
        {
            covered = A[i];
            noStop++;
            left = D - A[i];
        }
    }
    return noStop;
}

int32_t main()
{
    flash;
    int d;
    cin >> d;
    int m;
    cin >> m;
    int n;
    cin >> n;
    vi A(n);
    for (int &i : A)
        cin >> i;
    cout << minRefill(A, d, m);
    return 0;
}