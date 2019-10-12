#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int N;
int check[10001];
vector<char> v;

void go(int k) {
	for (int i = 0; i + k < N; i++) {
		string s = "";
		s += v[i];
		for (int j = 1; j <= k; j++) {
			s += v[j + i];
		}
		check[stoi(s)] = true;
	}
}
int check_num(int k) {
	for (int i = 0; i < pow(10, k); i++) {
		if (!check[i]) {
			return i;
		}
	}
	return -1;
}
int main() {
	int t;
	cin >> t;
	for (int test_case=1; test_case <=t ; test_case++){
		cin >> N;
		int tmp_c;
		v.clear();
		memset(check, 0, sizeof(check));
		for (int i = 0; i < N; i++) {
			scanf(" %1c", &tmp_c);
			v.push_back(tmp_c);
		}
		for (int k = 0; k < 4; k++) {
			go(k);
			int ans = check_num(k);
			if (ans != -1) {
				printf("#%d %d\n", test_case, ans);
				break;
			}
		}
	}
	return 0;
}