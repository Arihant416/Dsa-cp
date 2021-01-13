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

int findMedianOfAB(vi &A, vi &B, int sizeA, int sizeB)
{
    int i(0), j(0), count, l1(-1), l2(-1);
    if ((sizeA + sizeB) & 1)
    {
        for (count = 0; count <= (sizeA + sizeB) / 2; count++)
        {
            if (i != sizeA && j != sizeB)
            {
                l1 = (A[i] > B[j]) ? B[j++] : A[i++];
            }
            else if (i < sizeA)
            {
                l1 = A[i++];
            }
            else
            {
                l1 = B[j++];
            }
        }
        return l1;
    }
    else
    {
        for (count = 0; count <= (sizeA + sizeB) / 2; count++)
        {
            l2 = l1;
            if (i != sizeA && j != sizeB)
            {
                l1 = (A[i] > B[j]) ? B[j++] : A[i++];
            }
            else if (i < sizeA)
            {
                l1 = A[i++];
            }
            else
            {
                l1 = B[j++];
            }
        }
        return (l1 + l2) / 2;
    }
    return 0;
}

int32_t main()
{
    flash;
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    vi A(sizeA), B(sizeB);
    for (int &i : A)
        cin >> i;
    for (int &i : B)
        cin >> i;
    cout << findMedianOfAB(A, B, sizeA, sizeB);
    return 0;
}