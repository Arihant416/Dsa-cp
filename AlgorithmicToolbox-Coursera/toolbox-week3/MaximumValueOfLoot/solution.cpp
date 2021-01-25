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

bool mySortFunction(const pi &i, const pi &j)
{
    double a = (double)i.first / (double)i.second;
    double b = (double)j.first / (double)j.second;
    return a > b;
}

double findMaximumLoot(vi &value, vi &weight, int maxCapacity, int N)
{
    double result = 0;
    vector<pi> A;
    for (int i = 0; i < N; i++)
    {
        A.PB({value[i], weight[i]});
    }
    sort(all(A), mySortFunction);
    int curWeight(0);
    for (auto &i : A)
    {
        if (curWeight + i.second <= maxCapacity)
        {
            curWeight += i.second;
            result += i.first;
        }
        else
        {
            int left = maxCapacity - curWeight;
            result += i.first * ((double)left / (double)i.second);
        }
    }
    return result;
}

int32_t main()
{
    flash;

    int N, maxCapacity;
    cin >> N >> maxCapacity;
    vi value(N), weight(N);
    for (int i = 0; i < N; i++)
    {
        cin >> value[i] >> weight[i];
    }
    cout.precision(10);
    cout << findMaximumLoot(value, weight, maxCapacity, N) << endl;
    return 0;
}