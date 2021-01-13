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
    int findMedian(vector<vi> &matrix, int row, int col)
    {
        int mint = INT_MAX, maxt = INT_MIN;
        for (int i = 0; i < row; i++)
        {
            mint = min(mint, matrix[i][0]);
            maxt = max(maxt, matrix[i][col - 1]);
        }
        int hash = (row * col + 1) / 2;
        while (mint < maxt)
        {
            int mid = mint + (maxt - mint) / 2;
            int x = 0;
            for (int i = 0; i < row; i++)
            {
                x += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (x < hash)
                mint = mid + 1;
            else
                maxt = mid;
        }
        return mint;
    }
};

int32_t main()
{
    flash;
    int row, col;
    cin >> row >> col;
    vector<vi> matrix(row, vi(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    Solution obj;
    cout << obj.findMedian(matrix, row, col) << endl;
    return 0;
}