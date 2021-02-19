#include <iostream>
using namespace std;

int reverse(int num){
    int rev =0 ;
    while(num){
        int rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }
    return rev;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int num;
	    cin >> num;
	    cout << reverse(num) << endl;
	}
	return 0;
}
