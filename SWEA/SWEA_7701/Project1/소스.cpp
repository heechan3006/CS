#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int N;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		vector<string> book[55];
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			book[s.length()-1].push_back(s);
		}
		cout << "#" << test_case << "\n";
		for (int i = 0; i < 50; i ++ ) {
			sort(book[i].begin(), book[i].end());
			int len = book[i].size();
			if (len != 0) {
				cout << book[i][0] << "\n";
				for (int j = 1; j < len; j++) {
					if (book[i][j] != book[i][j - 1]) {
						cout << book[i][j] << "\n";
					}
				}
			}
		}
		
	}
	return 0;
}