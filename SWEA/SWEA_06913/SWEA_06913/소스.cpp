#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int map[20][20];
int score[20];

int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}
		memset(score, 0, sizeof(score));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				score[i] += map[i][j];
			}
		}
		int ans = 0;
		int score_cnt = 0;
		for (int i = 0; i < n; i++) {
			if (ans < score[i]) {
				ans = score[i];
				score_cnt = 1;
			}
			else if (ans == score[i]) {
				score_cnt++;
			}
		}
		printf("#%d %d %d\n", test_case, score_cnt, ans);
	}
	return 0;
}