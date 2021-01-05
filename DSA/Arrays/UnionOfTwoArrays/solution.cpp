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

void findUnion(int A[], int B[], int sizeA, int sizeB)
{
    uimap mapA;
    for (int i = 0; i < sizeA; i++)
    {
        mapA[A[i]] = 1;
    }
    int count = 0;
    for (int i = 0; i < sizeB; i++)
    {
        mapA[B[i]] = 1;
    }
    cout << "Count of Union of A & B is " << mapA.size() << endl;
}

int32_t main()
{
    flash;
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    int A[sizeA], B[sizeB];
    for (int i = 0; i < sizeA; i++)
        cin >> A[i];
    for (int i = 0; i < sizeB; i++)
        cin >> B[i];
    findUnion(A, B, sizeA, sizeB);
    return 0;
}