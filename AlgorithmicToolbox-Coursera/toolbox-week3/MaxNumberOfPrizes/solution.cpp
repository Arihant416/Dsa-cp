#include <bits/stdc++.h>
using namespace std;

vector<int> optimal_numbers(int N)
{
    vector<int> res;
    for (int i = N, j = 1; i > 0; j++)
    {
        if (i <= 2 * j)
        {
            res.push_back(i);
            i -= i;
        }
        else
        {
            res.push_back(j);
            i -= j;
        }
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    auto res = optimal_numbers(N);
    cout << res.size() << endl;
    for (auto i : res)
        cout << i << " ";
    res.clear();
    return 0;
}