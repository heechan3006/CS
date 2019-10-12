#include <iostream>
#include <string>
#define MOD 1000000
using namespace std;

string s;
int D[5001];
int A[5001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (int i = 1; i <= s.length(); i++) {
		A[i] = s[i-1]-'0';
	}
	if (s.length() == 1 && s[0] == '0') {
		cout << 0 <<"\n";
		
	}
	else{
		D[0] = 1;
		for (int i = 1; i <= s.length(); i++) {
			if (1 <= A[i] && A[i] <= 9) {
				D[i] = (D[i] + D[i - 1]) % MOD;
			}
			if (i == 1) continue;
			int tmp = A[i] + A[i-1]*10;
			if (10 <= tmp && tmp <= 26) {
				D[i] = (D[i] + D[i - 2]) % MOD;
			}
		}
		cout << D[s.length()]<<"\n";
	}
	return 0;
}