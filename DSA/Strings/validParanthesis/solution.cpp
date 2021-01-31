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

bool isOpening(char c)
{
    return c == '(' || c == '{' || c == '[';
}

bool isBalanced(string &s)
{
    stack<char> stack;
    if (s[0] == '}' || s[0] == ']' || s[0] == ')')
        return false;
    char x;
    for (char &c : s)
    {
        if (isOpening(c))
        {
            stack.push(c);
            continue;
        }
        if (stack.empty())
            return false;
        switch (c)
        {
        case ')':
            x = stack.top();
            stack.pop();
            if (x != '(')
                return false;
            break;
        case '}':
            x = stack.top();
            stack.pop();
            if (x != '{')
                return false;
            break;
        case ']':
            x = stack.top();
            stack.pop();
            if (x != '[')
                return false;
            break;
        }
    }
    return stack.empty();
}

int32_t main()
{
    flash;
    string s;
    cin >> s;
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced");
    return 0;
}