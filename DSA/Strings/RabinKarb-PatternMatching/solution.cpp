#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int prime = 97;
    const int MAX = 256;
    int strStr(string haystack, string needle)
    {
        int hay(0), ned(0), N = haystack.size(), M = needle.size(), hash = 1;
        for (int i = 0; i < M - 1; i++)
        {
            hash = (hash * MAX) % prime;
        }
        for (int i = 0; i < M; i++)
        {
            hay = (MAX * hay + haystack[i]) % prime;
            ned = (MAX * ned + needle[i]) % prime;
        }
        for (int i = 0; i < N - M + 1; i++)
        {
            if (hay == ned)
            {
                int j;
                for (j = 0; j < M; j++)
                {
                    if (haystack[i + j] != needle[j])
                        break;
                }
                if (j == M)
                    return i;
            }
            if (i < N - M)
            {
                hay = (MAX * (hay - haystack[i] * hash) + haystack[i + M]) % prime;
                hay = hay >= 0 ? hay : hay + prime;
            }
        }
        return -1;
    }
};

int main()
{
    string text, pat;
    getline(cin, text);
    getline(cin, pat);
    Solution ob;
    cout << ob.strStr(text, pat);
}