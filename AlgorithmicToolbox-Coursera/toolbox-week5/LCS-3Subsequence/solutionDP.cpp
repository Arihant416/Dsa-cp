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

int maxOf3(int a, int b, int c)
{
    return max(a, max(b, c));
}

int findLCSofABC(vi &A, vi &B, vi &C, int a, int b, int c)
{
    int dp[a + 1][b + 1][c + 1];
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            for (int k = 0; k <= c; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if (A[i - 1] == B[j - 1] && A[i - 1] == C[k - 1])
                {
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                }
                else
                {
                    dp[i][j][k] = maxOf3(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]);
                }
            }
        }
    }
    return dp[a][b][c];
}

int32_t main()
{
    flash;
    int a, b, c;
    //Vector A
    cin >> a;
    vi A(a);
    for (auto &i : A)
        cin >> i;
    // Vector B
    cin >> b;
    vi B(b);
    for (auto &j : B)
        cin >> j;
    // Vector C
    cin >> c;
    vi C(c);
    for (auto &k : C)
        cin >> k;
    cout << findLCSofABC(A, B, C, a, b, c);
    return 0;
}