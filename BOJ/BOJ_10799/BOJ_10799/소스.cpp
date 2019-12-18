#include <iostream>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int cnt = 0;
	bool flag = false;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			cnt++;
			flag = true;
		}
		else if (s[i] == ')' && flag) {
			flag = false;
			cnt--;
			ans += cnt;
		}
		else if (s[i] == ')' && !flag) {
			ans++;
			cnt--;
		}
	}
	cout << ans << "\n";
	return 0;
}