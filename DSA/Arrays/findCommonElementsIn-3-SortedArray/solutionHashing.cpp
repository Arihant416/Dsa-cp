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
    vector<int> findCommonElements(vi &A, vi &B, vi &C, int sizeA, int sizeB, int sizeC)
    {
        uimap hashA, hashB;
        vi res;
        for (int &i : A)
            hashA[i] = 1;
        for (int &i : B)
        {
            if (hashA.find(i) != hashB.end())
                hashB[i] = 1;
        }
        for (int i : C)
        {
            if (hashB.find(i) != hashB.end())
            {
                res.PB(i);
                hashB.erase(i);
            }
        }
        return res;
    }
};

int32_t main()
{
    flash;
    int sA, sB, sC;
    cin >> sA >> sB >> sC;
    vi A(sA), B(sB), C(sC);
    for (int &i : A)
        cin >> i;
    for (int &i : B)
        cin >> i;
    for (int &i : C)
        cin >> i;
    Solution ob;
    for (auto &i : ob.findCommonElements(A, B, C, sA, sB, sC))
        cout << i << " ";
    return 0;
}