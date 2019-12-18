#include <iostream>
#include <cstring>
using namespace std;

int num[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(num, -1, sizeof(num));
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (num[s[i] - 'a'] == -1) num[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << num[i] << " ";
	}
	return 0;
}