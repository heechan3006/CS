#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		int num= 0;
		
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') num++;
			else num--;
			if (num < 0) {
				break;
			}
		}
		
		if (num != 0) cout << "NO\n";
		else cout << "YES\n";
		
	}
	return 0;
}