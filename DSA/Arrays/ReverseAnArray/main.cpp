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
#define minEl(a) *max_element(all(a))
#define uimap unordered_map<int,int>
#define ulmap unordered_map<ll, ll>
#define mppii map< pi, int>

void reverseUtil(vi& array,const int& length)
{
    for(int i = 0; i < length/2; i++)
    {
        swap(array[i], array[length-i-1]);
    }
}

void print(vi& array, const int &length)
{
    for(auto &i : array)
    {
        cout << i <<" ";
    }
}
void solve()
{
    int array_size;
    cin >> array_size;
    vi array(array_size);
    for(int &i: array)
    {
        cin >> i;
    }
    reverseUtil(array, array_size);
    print(array, array_size);
}
int32_t main() {
    flash;
    solve();
    return 0;
}