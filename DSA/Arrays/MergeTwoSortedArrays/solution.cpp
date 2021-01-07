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

int nextGap(int currentGap)
{
    if (currentGap <= 1)
        return 0;
    return currentGap / 2 + (currentGap % 2);
}

void merge(int A[], int B[], int sizeA, int sizeB)
{
    int i, j, currentGap = sizeA + sizeB;
    for (currentGap = nextGap(currentGap); currentGap > 0; currentGap = nextGap(currentGap))
    {
        for (i = 0; i + currentGap < sizeA; i++)
        {
            if (A[i] > A[i + currentGap])
            {
                swap(A[i], A[i + currentGap]);
            }
        }
        for (j = currentGap > sizeA ? currentGap - sizeA : 0; i < sizeA && j < sizeB; i++, j++)
        {
            if (A[i] > B[j])
                swap(A[i], B[j]);
        }
        if (j < sizeB)
        {
            for (j = 0; j + currentGap < sizeB; j++)
            {
                if (B[j] > B[j + currentGap])
                {
                    swap(B[j], B[currentGap]);
                }
            }
        }
    }
}

int32_t main()
{
    flash;

    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    int A[sizeA], B[sizeB];
    for (int i = 0; i < sizeA; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < sizeB; i++)
    {
        cin >> B[i];
    }
    merge(A, B, sizeA, sizeB);
    for (int i = 0; i < sizeA; i++)
    {
        cout << A[i] << " ";
    }
    for (int i = 0; i < sizeB; i++)
    {
        cout << B[i] << " ";
    }
    return 0;
}