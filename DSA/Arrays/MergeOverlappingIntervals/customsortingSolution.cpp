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

static bool comparator(const pi &A, const pi &B)
{
    return A.first < B.first;
}

vector<pi> mergeIntervals(vector<pi> &Intervals, int numberOfIntervals)
{
    sort(Intervals.begin(), Intervals.end(), comparator);
    int index = 0;
    for (int i = 1; i < numberOfIntervals; i++)
    {
        if (Intervals[index].second >= Intervals[i].first)
        {
            Intervals[index].second = max(Intervals[index].second, Intervals[i].second);
            Intervals[index].first = min(Intervals[index].first, Intervals[i].first);
        }
        else
        {
            index++;
            Intervals[index] = Intervals[i];
        }
    }
    return {Intervals.begin(), Intervals.begin() + index + 1};
}

int32_t main()
{
    flash;
    int numberOfIntervals;
    cin >> numberOfIntervals;
    vector<pi> Intervals;
    for (int i = 0; i < numberOfIntervals; i++)
    {
        int start, end;
        cin >> start >> end;
        Intervals.PB(MP(start, end));
    }
    for (auto &i : mergeIntervals(Intervals, numberOfIntervals))
    {
        cout << i.first << " " << i.second << ", ";
    }
    return 0;
}