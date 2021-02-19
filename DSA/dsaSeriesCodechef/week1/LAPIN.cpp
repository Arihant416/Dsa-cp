#include <bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
string isLapindrome(string &s){
    string p,q;
    if(s.size() & 1){
        for(int i = 0; i < s.size()/2; i++){
            p.push_back(s[i]);
            q.push_back(s[s.size() - 1 - i]);
        }   
        sort(p.begin(),p.end());
        sort(q.begin(),q.end());
        return p == q ? yes: no;
    }
    else{
        for(int i = 0; i < s.size()/2; i++){
            p.push_back(s[i]);
            q.push_back(s[s.size() - i - 1]);
        }
        sort(p.begin(),p.end());
        sort(q.begin(),q.end());
        return p == q ? yes: no;
    }
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    cout << isLapindrome(s) << endl;
	}
	return 0;
}
