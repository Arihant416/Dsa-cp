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
    string findLongestPalindrome(string &s);
};

string Solution::findLongestPalindrome(string &s)
{
    // Base Case
    int low(0), maxlength(1), high(0), start(0);
    for (int i = 1; i < s.length(); i++)
    {
        // Taking center i-1,i
        low = i - 1;
        high = i;
        while (low >= 0 && high < s.size() && s[high] == s[low])
        {
            if (high - low + 1 > maxlength)
            {
                maxlength = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }
        // Taking only i as center
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < s.size() && s[high] == s[low])
        {
            if (high - low + 1 > maxlength)
            {
                maxlength = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }
    }
    return s.substr(start, maxlength);
}

int32_t main()
{
    flash;

    string s;
    cin >> s;
    Solution ob;
    cout << ob.findLongestPalindrome(s) << endl;
    return 0;
}