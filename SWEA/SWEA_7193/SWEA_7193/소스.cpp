#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
char input[10000000 + 1];
using namespace std;
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=1;test_case<=t; test_case++){
		cin >> N >> input;

		char tmp;
		int ans = 0;
		int len = strlen(input);
		for (int i = 0; i < len; i++) {
			ans += (input[i] - '0');
		}
		
		ans = ans % (N - 1);
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}