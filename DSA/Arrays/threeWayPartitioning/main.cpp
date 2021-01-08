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
void partitionThreeWaysInPlace(vi &A, int N, int a, int b)
{
    if (a > b)
        swap(a, b);
    int low(0), high(N - 1);
    for (int i = 0; i <= high;)
    {
        if (A[i] < a)
        {
            swap(A[i++], A[low++]);
        }
        else if (A[i] > b)
        {
            swap(A[i], A[high--]);
        }
        else
        {
            i++;
        }
    }
}

int32_t main()
{
    flash;

    int N, value1, value2;
    cin >> N >> value1 >> value2;
    vi A(N);
    for (auto &i : A)
        cin >> i;
    partitionThreeWaysInPlace(A, N, value1, value2);
    print(A);
    return 0;
}