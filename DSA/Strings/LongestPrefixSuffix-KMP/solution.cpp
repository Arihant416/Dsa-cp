#include <bits/stdc++.h>
using namespace std;

int findLongestPrefixSuffix(string &s)
{
    int len = s.size(), l(0), i(1);
    vector<int> lps(len, 0);
    while (i < len)
    {
        if (s[i] == s[l])
        {
            ++l;
            lps[i++] = l;
        }
        else
        {
            if (l != 0)
                l = lps[l - 1];
            else
            {
                lps[i++] = 0;
            }
        }
    }
    return lps.back();
}

int main()
{
    string s;
    cin >> s;
    cout << findLongestPrefixSuffix(s);
}