#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int t;
bool check[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int test_case = 1; test_case<= t; test_case++){
		memset(check, false, sizeof(check));
		string s;
		cin >> s;
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (!check[s[i] - '0']) {
				check[s[i] - '0'] = true;
				cnt++;
			}
		}
		cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;
}
