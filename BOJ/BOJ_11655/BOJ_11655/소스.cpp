#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char s[101];
	cin.getline(s,sizeof(s));
	string ans = "";
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			ans += (s[i] + 13 - 'a') % 26 + 'a';
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			ans += (s[i] + 13 - 'A') % 26 + 'A';
		}
		else ans += s[i];
	}
	cout << ans ;
	return 0;
}