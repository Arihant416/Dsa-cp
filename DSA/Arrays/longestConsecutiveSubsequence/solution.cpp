/*
Author : Arihant Jain
github:https://github.com/Arihant416
linkedin : https://www.linkedin.com/in/arihant416

Basic Idea - Can be done using Brute force in O(N^2) time complexity.
Better Way - Can be done using hashing or a Lookup table of size (max_element of Array) in O(N) time & O(MAX) space

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

int longestConsecutiveSubsequence(vl &A, int N)
{
    vi lookup(maxEl(A) + 1, 0);
    for (auto i : A)
        lookup[i] = 1;
    int currentCount(0), maxLength(0);
    for (int i : lookup)
    {
        if (i)
            currentCount++;
        else
        {
            maxLength = max(maxLength, currentCount);
            currentCount = 0;
        }
    }
    return max(maxLength, currentCount);
}

int32_t main()
{
    flash;
    int N;
    cin >> N;
    vl A(N);
    for (auto &i : A)
        cin >> i;
    cout << longestConsecutiveSubsequence(A, N) << endl;
    return 0;
}