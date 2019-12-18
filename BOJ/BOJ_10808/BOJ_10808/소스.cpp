#include <iostream>
using namespace std;

int num[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		num[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << num[i] << " ";
	}
	return 0;
}