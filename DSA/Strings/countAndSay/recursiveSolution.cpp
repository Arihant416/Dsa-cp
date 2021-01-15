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
    string countAndSayRecursive(int N);
};

string Solution::countAndSayRecursive(int N)
{
    // Base Case
    if (N == 1)
        return "1";
    string result, temp = countAndSayRecursive(N - 1); // Recursive call
    auto c = temp[0];
    int count = 1;
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] == c)
        {
            count++;
        }
        else
        {
            result += to_string(count);
            result.PB(c);
            c = temp[i];
            count = 1;
        }
    }
    result += to_string(count);
    result.push_back(c);
    return result;
}

int32_t main()
{
    flash;

    int N;
    cin >> N;
    Solution ob;
    cout << ob.countAndSayRecursive(N);
    return 0;
}