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

void printSpiral(vector<vi> &matrix, int i, int j, int rows, int cols)
{
    if (i >= rows || j >= cols)
    {
        return;
    }
    for (int x = i; x < cols; x++)
    {
        cout << matrix[i][x] << " ";
    }
    for (int x = i + 1; x < rows; x++)
    {
        cout << matrix[x][cols - 1] << " ";
    }
    if (rows - 1 != i)
    {
        for (int x = cols - 2; x >= j; x--)
        {
            cout << matrix[rows - 1][x] << " ";
        }
    }
    if (cols - 1 != j)
    {
        for (int x = rows - 2; x > i; x--)
        {
            cout << matrix[x][j] << " ";
        }
    }
    printSpiral(matrix, i + 1, j + 1, rows - 1, cols - 1);
}

void spiralTraversal(vector<vi> &matrix, int rows, int cols)
{
    printSpiral(matrix, 0, 0, rows, cols);
}

int32_t main()
{
    flash;

    int rows, cols;
    cin >> rows >> cols;
    vector<vi> matrix(rows, vi(cols));
    for (auto &i : matrix)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }
    spiralTraversal(matrix, rows, cols);
    return 0;
}