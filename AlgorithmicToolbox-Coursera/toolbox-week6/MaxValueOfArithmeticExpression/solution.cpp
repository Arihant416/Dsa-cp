#include <bits/stdc++.h>
using namespace std;

long long expEval(long a, long b, char op)
{
    if (op == '*')
        return a * b;
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
}

long long minOf5(long long x, long long a, long long b, long long c, long long d)
{
    return min(x, min(a, min(b, min(c, d))));
}

long long maxOf5(long long x, long long a, long long b, long long c, long long d)
{
    return max(x, max(a, max(b, max(c, d))));
}

long long evaluateForMaxVal(string &s)
{
    int len = s.length();
    int digits = (len + 1) / 2;
    long long arMin[digits][digits];
    long long arMax[digits][digits];
    memset(arMin, 0, sizeof(arMin));
    memset(arMax, 0, sizeof(arMax));
    for (int i = 0; i < digits; i++)
    {
        arMin[i][i] = stoll(s.substr(2 * i, 1));
        arMax[i][i] = stoll(s.substr(2 * i, 1));
    }
    for (int d = 0; d < digits; d++)
    {
        for (int i = 0; i < digits - d - 1; i++)
        {
            int j = i + d + 1;
            long long minn(INT_MAX), maxx(INT_MIN);
            for (int k = i; k < j; k++)
            {
                int index = 2 * k + 1;
                long long a(expEval(arMin[i][k], arMax[k + 1][j], s[index]));
                long long b(expEval(arMin[i][k], arMax[k + 1][j], s[index]));
                long long c(expEval(arMax[i][k], arMin[k + 1][j], s[index]));
                long long d(expEval(arMax[i][k], arMax[k + 1][j], s[index]));
                minn = minOf5(minn, a, b, c, d);
                maxx = maxOf5(maxx, a, b, c, d);
            }
            arMin[i][j] = minn;
            arMax[i][j] = maxx;
        }
    }
    return arMax[0][digits - 1];
}

int main()
{
    string s;
    cin >> s;
    cout << evaluateForMaxVal(s);
}