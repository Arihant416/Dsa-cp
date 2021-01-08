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

void print(vi &A)
{
    for (auto &i : A)
        cout << i << " ";
}
void rearrangeAlternatePositivesNegatives(vi &A, int N)
{
    int low(0), high(N - 1);
    while (low < high)
    {
        while (low <= N - 1 && A[low] > 0)
        {
            low++;
        }
        while (high >= 0 && A[high] < 0)
        {
            high--;
        }
        if (low < high)
        {
            swap(A[low], A[high]);
        }
    }
    if (low == 0 || low == N)
        return;
    int K = 0;
    while (K < N && low < N)
    {
        swap(A[K], A[low]);
        low++;
        K += 2;
    }
}

int32_t main()
{
    flash;

    int sizeA;
    cin >> sizeA;
    vi A(sizeA);
    for (auto &i : A)
    {
        cin >> i;
    }
    rearrangeAlternatePositivesNegatives(A, sizeA);
    print(A);
    return 0;
}

/*
Sample Case
SizeA: 6
Array A: 2 3 -5 -1 6 -10
Output: -1 3 -5 2 -10 6
*/