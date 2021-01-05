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

int partition(int arr[], int left, int right, int X);

int findMedian(int arr[], int N);

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findKthSmallest(int arr[], int left, int right, int K)
{
    if (K > 0 && K <= right - left + 1)
    {
        int N = right - left + 1;
        int i, median[(N + 4) / 5];
        for (i = 0; i < N / 5; i++)
        {
            median[i] = findMedian(arr + left + i * 5, 5);
        }
        if (i * 5 < N)
        {
            median[i] = findMedian(arr + left + i * 5, N % 5);
            i++;
        }
        int medOfMed = (i == 1) ? median[i - 1] : findKthSmallest(median, 0, i - 1, i / 2);
        int pos = partition(arr, left, right, medOfMed);
        if (pos - left == K - 1)
            return arr[pos];
        if (pos - left > K - 1)
            return findKthSmallest(arr, left, pos - 1, K);
        return findKthSmallest(arr, pos + 1, right, K - pos + left - 1);
    }
    return -1;
}

void solve()
{
    int N, K;
    cin >> N >> K;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << findKthSmallest(arr, 0, N - 1, K);
}

int32_t main()
{
    flash;
    solve();
    return 0;
}

int partition(int arr[], int left, int right, int X)
{
    // Search X in arr[left...right] & move it to the end
    int i;
    for (i = left; i < right; i++)
    {
        if (arr[i] == X)
            break;
    }
    swap(&arr[i], &arr[right]);

    // Standard Partition Algo
    i = left;
    for (int j = left; j < right; j++)
    {
        if (arr[j] <= X)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

int findMedian(int arr[], int N)
{
    sort(arr, arr + N);
    return arr[N / 2];
}