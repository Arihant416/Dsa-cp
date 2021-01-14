/*
Author : Arihant Jain
github:https://github.com/Arihant416
linkedin : https://www.linkedin.com/in/arihant416


Question - Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of the only set bit. If there are 0 or more than 1 set bit the answer should be -1. Position of  set bit '1' should be counted starting with 1 from LSB side in binary representation of the number.



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
    int findPosition(int N)
    {
        if (__builtin_popcount(N) == 1)
        {
            /* code */
            int index = 1;
            while (N)
            {
                if (N & 1)
                    return index;
                index++;
                N >>= 1;
            }
        }
        /* Since multiple/0 ones possible*/
        return -1;
    }
};

int32_t main()
{
    flash;
    int N;
    cin >> N;
    Solution ob;
    cout << ob.findPosition(N) << endl;
    return 0;
}