#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test_case=1 ; test_case <= t; test_case++){
		string s;
		cin >> s;
		int cnt[26];
		int ans = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < s.size(); i++) {
			cnt[s[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			ans += (cnt[i] * (cnt[i] + 1))/2;
		}
		printf("#%d %d\n", test_case,ans);
	}
	return 0;
}