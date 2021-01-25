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

struct Interval
{
    int start, end;
};

vi getPoints(vector<Interval> &segments, int N)
{
    sort(all(segments), [](const Interval &segment1, const Interval &segment2) -> bool { return segment1.end < segment2.end; });
    vi res;
    int point = segments[0].end;
    res.PB(point);
    for (size_t i = 1; i < N; i++)
    {
        if (point < segments[i].start || point > segments[i].end)
        {
            point = segments[i].end;
            res.PB(point);
        }
    }
    return res;
}

int32_t main()
{
    flash;
    int N;
    cin >> N;
    vector<Interval> segments(N);
    for (auto &i : segments)
    {
        cin >> i.start >> i.end;
    }
    auto res = getPoints(segments, N);
    cout << res.size() << endl;
    for (auto &i : res)
        cout << i << " ";
    return 0;
}