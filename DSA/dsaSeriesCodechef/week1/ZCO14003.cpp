#include<bits/stdc++.h>
using namespace std;
#define ll  long long int

ll solve(vector<ll>& budget, int customerCount)
{
    ll ans = 0;
    sort(budget.begin(), budget.end());
    reverse(budget.begin(), budget.end());
    for(int i = 0; i < customerCount ; i++){
        ans = max(ans, budget[i] * (i+1));
    }
    return ans;
}

int main()
{
    int customerCount;
    cin >> customerCount;
    vector<ll>budget(customerCount);
    for(int i = 0; i < customerCount; i++){
        cin >> budget[i];
    }
    cout << solve(budget, customerCount);
}