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
    for (int &i : A)
        cout << i << " ";
}

void rev(vi &A, int from_index, int N)
{
    int i = from_index, j = N - 1;
    while (i < j)
    {
        swap(A[i++], A[j--]);
    }
}

void nextPermuation(vi &A, int N)
{
    int index = N - 2;
    while (index >= 0 && A[index + 1] <= A[index])
    {
        index--;
    }
    if (index >= 0)
    {
        int j = N - 1;
        while (j >= 0 && A[j] <= A[index])
        {
            j--;
        }
        swap(A[j], A[index]);
    }
    rev(A, index + 1, N);
}

int32_t main()
{
    flash;

    int N;
    cin >> N;
    vi A(N);
    for (auto &i : A)
        cin >> i;
    nextPermuation(A, N);
    print(A);
    return 0;
}