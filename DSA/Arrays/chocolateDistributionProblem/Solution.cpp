/*
Author : Arihant Jain
github:https://github.com/Arihant416
linkedin : https://www.linkedin.com/in/arihant416

Question Statement:
    Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 

    1) Each student gets one packet.
    2) The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.
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

int findMinDiff(vi &A, int N, int M)
{
    if (N == 0 || M == 0)
        return 0;
    sort(all(A));
    int i(0);
    int minDiff = INT_MAX;
    while (i + M - 1 < N)
    {
        minDiff = min(minDiff, A[i + M - 1] - A[i]);
        i++;
    }
    return minDiff;
}

int32_t main()
{
    flash;
    int testCount;
    cin >> testCount;
    while (testCount--)
    {
        int N, M;
        cin >> N;
        vi A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        cin >> M;
        cout << findMinDiff(A, N, M) << endl;
    }
    return 0;
}