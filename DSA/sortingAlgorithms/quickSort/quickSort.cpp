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

int partition(vi &A, int low, int high)
{
    int i = low - 1;
    int pivot = A[high];
    for (int j = low; j < high; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(A[j], A[i]);
        }
    }
    swap(A[high], A[i + 1]);
    return i + 1;
}

void quickSort(vi &A, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(A, low, high);
        quickSort(A, low, pivot - 1);
        quickSort(A, pivot + 1, high);
    }
}
void print(vi &A)
{
    for (auto &i : A)
        cout << i << " ";
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
    quickSort(A, 0, N - 1);
    print(A);
    return 0;
}