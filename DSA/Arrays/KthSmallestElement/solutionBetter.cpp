/*
Author : Arihant Jain
github:https://github.com/Arihant416
linkedin : https://www.linkedin.com/in/arihant416
*/
#include<bits/stdc++.h>
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
#define uimap unordered_map<int,int>
#define ulmap unordered_map<ll, ll>
#define mppii map< pi, int>


int findKthSmallest(vi& A,int left, int right, int K)
{
    priority_queue<int>pq;
    int i = 0;
    int N = right+1;
    while(i < K)
    {
        pq.push(A[i]);
        i++;
    }
    while(i != N)
    {
        if(pq.top() > A[i])
        {
            pq.pop();
            pq.push(A[i]);
        }
        ++i;
    }
    return pq.top();
}

void solve()
{
    int size, K;
    cin >> size >> K;
    vi A(size);
    for(int i = 0; i < size; i++)
    {
        cin >> A[i];
    }
    cout << findKthSmallest(A, 0, size-1, K);
}

int32_t main() {
    flash;
    solve();
    return 0;
}