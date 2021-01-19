/*
Author : Arihant Jain
github:https://github.com/Arihant416
linkedin : https://www.linkedin.com/in/arihant416

Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

Insert
Remove
Replace
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.

Example 2:

Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)


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
    Solution() {}
    int editDistance(string &str1, string &str2);
    ~Solution() {}
};

int minOf3(int A, int B, int C)
{
    return min(A, min(B, C));
}

int Solution::editDistance(string &str1, string &str2)
{
    int size1 = str1.size(), size2 = str2.size(), prev;
    vi lookup(size2 + 1, 0);
    for (int i = 1; i <= size2; i++)
        lookup[i] = i;
    for (int i = 1; i <= size1; i++)
    {
        prev = lookup[0];
        lookup[0] = i;
        for (int j = 1; j <= size2; j++)
        {
            int currentScore = lookup[j];
            if (str1[i - 1] == str2[j - 1])
            {
                lookup[j] = prev;
            }
            else
            {
                lookup[j] = 1 + minOf3(lookup[j - 1], lookup[j], prev);
            }
            prev = currentScore;
        }
    }
    return lookup[size2];
}

int32_t main()
{
    flash;
    int testCount;
    cin >> testCount;
    while (testCount--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        Solution ob;
        cout << ob.editDistance(str1, str2) << endl;
    }
    return 0;
}