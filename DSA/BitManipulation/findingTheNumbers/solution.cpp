/*
Author : Arihant Jain
github:https://github.com/Arihant416
linkedin : https://www.linkedin.com/in/arihant416


Question : Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers  (in ascending order).

Link - https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1

Test Cases 
1:
    Input: 
    2
    1 2 3 2 1 4
    Output:
    3 4 
    Explanation: 3 and 4 occur exactly once.

2. 
    Input:
    1
    2 1 3 2
    Output:
    1 3
    Explanation: 1 3 occur exactly once.

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
    vi singleNumber(vi &A, int N)
    {
        int diff = 0;
        for (auto i : A)
            diff ^= i;
        diff &= -diff;
        vi res = {0, 0};
        for (int i : A)
        {
            if ((i & diff) == 0)
            {
                res[0] ^= i;
            }
            else
            {
                res[1] ^= i;
            }
        }
        sort(all(res));
        return res;
    }
};

int32_t main()
{
    flash;
    int N;
    cin >> N;
    vi A(2 * N + 2);
    for (int &i : A)
        cin >> i;
    Solution object;
    auto res = object.singleNumber(A, N);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}