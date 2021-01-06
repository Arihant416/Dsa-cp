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
    int findSmallestDifferencePossible(vi &A, int N, int K)
    {
        vector<pair<int, int>> v;
        vector<int> taken(N);

        // we will store all possible heights in a vector
        for (int i = 0; i < N; i++)
        {
            if (A[i] - K >= 0)
            {
                v.push_back({A[i] - K, i});
            }
            v.push_back({A[i] + K, i});
        }
        sort(v.begin(), v.end());
        int elements_in_range = 0;
        int left = 0;
        int right = 0;

        // By two pointer we will traverse v and whenever we will get a range
        // in which all towers are included, we will update the answer.
        while (elements_in_range < N && right < v.size())
        {
            if (taken[v[right].second] == 0)
            {
                elements_in_range++;
            }
            taken[v[right].second]++;
            right++;
        }
        int ans = v[right - 1].first - v[left].first;
        while (right < v.size())
        {
            if (taken[v[left].second] == 1)
            {
                elements_in_range--;
            }
            taken[v[left].second]--;
            left++;

            while (elements_in_range < N && right < v.size())
            {
                if (taken[v[right].second] == 0)
                {
                    elements_in_range++;
                }
                taken[v[right].second]++;
                right++;
            }

            if (elements_in_range == N)
            {
                ans = min(ans, v[right - 1].first - v[left].first);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

int32_t main()
{
    flash;
    int N, K;
    cin >> N >> K;
    vi A(N);
    for (auto &i : A)
    {
        cin >> i;
    }
    Solution object;
    cout << object.findSmallestDifferencePossible(A, N, K);
    return 0;
}