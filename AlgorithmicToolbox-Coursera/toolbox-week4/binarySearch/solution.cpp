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

int binarySearch(vi &A, int N, int num)
{
    int low = 0, high = N - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == num)
            return mid;
        else if (A[mid] < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int32_t main()
{
    flash;
    int N;
    cin >> N;
    vi A(N);
    for (int &i : A)
        cin >> i;
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int num;
        cin >> num;
        cout << binarySearch(A, N, num) << " ";
    }
    return 0;
}