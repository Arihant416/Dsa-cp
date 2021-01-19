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
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        // code here
        next_permutation(arr.begin(), arr.end());
        return arr;
    }
    void print(vi &A)
    {
        for (auto &i : A)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

void solve(vi &A, int N)
{
    Solution ob;
    auto res = ob.nextPermutation(N, A);
    ob.print(res);
}

int32_t main()
{
    flash;
    int testCount;
    cin >> testCount;
    while (testCount--)
    {
        int N;
        cin >> N;
        vi A(N);
        for (int &i : A)
            cin >> i;
        solve(A, N);
    }
    return 0;
}