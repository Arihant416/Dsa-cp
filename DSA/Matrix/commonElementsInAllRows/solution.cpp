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

void print(vi &res)
{
    if (res.size() == 0)
    {
        cout << "No common elements found\n";
        return;
    }
    for (auto &i : res)
        cout << i << " ";
}

vi findCommonElementsfromEveryRow(vector<vi> &mat, int row, int col)
{
    vi res;
    uimap hash;
    for (int i = 0; i < col; i++)
        hash[mat[0][i]] = 1;
    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (hash[mat[i][j]] == i)
            {
                hash[mat[i][j]] = i + 1;
                if (i == row - 1)
                    res.PB(mat[i][j]);
            }
        }
    }
    return res;
}

int32_t main()
{
    flash;
    int row, col;
    cin >> row >> col;
    vector<vi> mat(row, vi(col));
    for (auto &i : mat)
        for (auto &j : i)
            cin >> j;
    auto res = findCommonElementsfromEveryRow(mat, row, col);
    print(res);
    return 0;
}