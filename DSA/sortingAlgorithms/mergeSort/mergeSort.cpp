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

void mergeUtil(vi &A, int low, int mid, int high)
{
    int N1 = mid - low + 1, N2 = high - mid;
    vi L(N1), R(N2);
    for (int i = 0; i < N1; i++)
        L[i] = A[low + i];
    for (int j = 0; j < N2; j++)
        R[j] = A[mid + j + 1];
    int i(0), j(0), k(low);
    while (i < N1 && j < N2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
        }
        k++;
    }
    while (i < N1)
    {
        A[k++] = L[i++];
    }
    while (j < N2)
    {
        A[k++] = R[j++];
    }
}

void mergeSort(vi &A, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        mergeUtil(A, low, mid, high);
    }
}
void print(vi &A)
{
    for (auto &i : A)
    {
        cout << i << " ";
    }
}
int32_t main()
{
    flash;
    int N;
    cin >> N;
    vi A(N);
    for (auto &i : A)
        cin >> i;
    mergeSort(A, 0, N - 1);
    print(A);
    return 0;
}