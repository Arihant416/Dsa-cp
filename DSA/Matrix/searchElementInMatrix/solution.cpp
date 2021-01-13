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

bool searchMatrix(vector<vi> &matrix, int rows, int cols, int target)
{
    if (!rows || !cols)
        return false;
    int start(0), end(rows * cols - 1);
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int element = matrix[mid / cols][mid % cols];
        if (target < element)
            end = mid - 1;
        else if (target > element)
        {
            start = mid + 1;
        }
        else
            return true;
    }
    return false;
}

int32_t main()
{
    flash;
    int rows, cols, targetElement;
    cin >> rows >> cols >> targetElement;
    vector<vi> matrix(rows, vi(cols));
    for (auto &i : matrix)
    {
        for (int &j : i)
        {
            cin >> j;
        }
    }
    if (searchMatrix(matrix, rows, cols, targetElement))
    {
        cout << "Yes, present\n";
    }
    else
    {
        cout << "Not found\n";
    }
    return 0;
}