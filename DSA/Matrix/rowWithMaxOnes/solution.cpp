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
    static int bs(vector<int> &a, int N)
    {
        vector<int>::iterator lower, upper;
        lower = lower_bound(a.begin(), a.end(), 1);
        upper = upper_bound(a.begin(), a.end(), 1);
        return upper - lower;
    }
    int rowWithMax1s(vector<vector<int>> &arr, int n, int m)
    {
        int count = 0;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][m - 1] == 0)
                continue;
            else
            {
                int onecount = bs(arr[i], m);
                if (count < onecount)
                {
                    count = onecount;
                    index = i;
                }
            }
        }
        return index;
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