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

ll globalCounter(0);

void merge(vl &A, int left, int mid, int right);
void mergeSort(vl &A, int left, int right);

int findInversionCount(vl &A, int N)
{
    mergeSort(A, 0, N - 1);
    ll result = globalCounter;
    globalCounter = 0;
    return result;
}

int32_t main()
{
    flash;

    int N;
    cin >> N;
    vl A(N);
    for (auto &i : A)
        cin >> i;
    cout << findInversionCount(A, N);
    return 0;
}

void merge(vl &A, int left, int mid, int right)
{
    int N1(mid - left + 1), N2(right - mid);
    vl L(N1), R(N2);
    for (int i = 0; i < N1; i++)
    {
        L[i] = A[i + left];
    }
    for (int j = 0; j < N2; j++)
    {
        R[j] = A[j + 1 + mid];
    }
    int i(0), j(0), k(left);
    while (i < N1 && j < N2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
            // Global Counter incremented for Inversion count
            globalCounter += N1 - i;
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

void mergeSort(vl &A, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}