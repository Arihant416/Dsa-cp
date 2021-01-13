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

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int r = 0;              // keeps track of row; starts at first row
        int c = m - 1;          // keeps track of column; starts at last column
        int max_row_index = -1; // keeps track of result row index

        // starting from top right corner
        // go left if you encounter 1
        // do down if you encounter 0
        while (r < n && c >= 0)
        {
            if (arr[r][c] == 1)
            {
                max_row_index = r;
                c--;
            }
            else
                r++;
        }
        return max_row_index;
    }
};

int32_t main()
{
    flash;
    int test;
    cin >> test;
    while (test--)
    {
        int N, M;
        cin >> N >> M;
        vector<vi> arr(N, vi(M));
        for (auto &i : arr)
        {
            for (auto &j : i)
                cin >> j;
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, N, M);
        cout << ans << endl;
    }
    return 0;
}