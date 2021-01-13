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

int maxAreaOfHistogram(vi &rect, int len)
{
    stack<int> s;
    int maxArea = 0, topp, areaWithTop, i(0);
    while (i < len)
    {
        if (s.empty() || rect[s.top()] <= rect[i])
            s.push(i++);
        else
        {
            topp = s.top();
            s.pop();
            areaWithTop = rect[topp] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, areaWithTop);
        }
    }
    while (!s.empty())
    {
        topp = s.top();
        s.pop();
        areaWithTop = rect[topp] * (s.empty() ? i : i - s.top() - 1);
        maxArea = max(areaWithTop, maxArea);
    }
    return maxArea;
}

int maxAreaOfRectangle(vector<vi> &mat, int N, int M)
{
    vi temp(M, 0);
    int maxArea = 0;
    int curArea = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j] == 0)
                temp[j] = 0;
            else
            {
                temp[j] += mat[i][j];
            }
        }
        curArea = maxAreaOfHistogram(temp, M);
        maxArea = max(curArea, maxArea);
    }
    return maxArea;
}

int32_t main()
{
    flash;
    int N, M;
    cin >> N >> M;
    vector<vi> mat(N, vi(M));
    for (auto &i : mat)
        for (auto &j : i)
            cin >> j;
    cout << maxAreaOfRectangle(mat, N, M);
    return 0;
}