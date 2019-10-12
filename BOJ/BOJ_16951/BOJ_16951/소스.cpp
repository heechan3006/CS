#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 1000
using namespace std;

int N, K;
int map[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	int cnt = 1000;
	
	for (int i = 0; i < N; i++) {
		vector<int> tmp(N);
		tmp[i] = map[i];
		bool flag = true;
		for (int j = i - 1; j >= 0; j--) {
			tmp[j] = tmp[j + 1] - K;
			if (tmp[j] < 1) {
				flag = false;
				break;
			}
		}
		for (int j = i + 1; j < N; j++) {
			tmp[j] = tmp[j - 1] + K;
			if (tmp[j] < 1) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		int tmp_cnt = 0;
		for (int j = 0; j < N; j++) {
			if (tmp[j] != map[j]) tmp_cnt++;
		}
		cnt = min(cnt, tmp_cnt);
	}
	cout << cnt << "\n";
	return 0;
}