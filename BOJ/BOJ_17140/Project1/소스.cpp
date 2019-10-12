#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100
using namespace std;

int map[MAXN][MAXN];

int R, C, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> K;
	R--;
	C--;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
			if (i == R && j == C && map[i][j] == K) {
				printf("0\n");
				return 0;
			}
		}
	}
	int len_row = 3;
	int len_col = 3;
	int ans = 0;
	while (1) {
		if (map[R][C] == K) {
			printf("%d\n", ans);
			break;
		}
		if (ans >= 100) {
			printf("-1\n");
			break;
		}
		ans++;
		bool flag = false;
		for (int i = 0; (i < MAXN)&&!flag; i++) {
			int cnt = 0;
			for (int j = 0; (j < MAXN)&&!flag; j++) {
				if (j == 0 && map[i][j] == 0) {
					flag = true;
					break;
				}
				if (map[i][j] == 0) break;

				cnt++;
			}
			len_col = max(len_col, cnt);
		}
		flag = false;
		for (int j = 0; (j < MAXN)&&!flag; j++) {
			int cnt = 0;
			for (int i = 0; (i < MAXN)&&!flag; i++) {
				if (i == 0 && map[i][j] == 0) {
					flag = true;
					break;
				}
				if (map[i][j] == 0) break;
				cnt++;
			}
			len_row = max(len_row, cnt);
		}
		vector<pair<int, int>> v[MAXN + 1];
		// R 연산
		if (len_row >= len_col) {
			
			for (int i = 0; i < len_row; i++) {
				int num_cnt[MAXN+1] = { 0, };
				for (int j = 0; j < len_col; j++) {
					num_cnt[map[i][j]]++;
				}
				for (int j = 1; j <= MAXN; j++) {
					if (num_cnt[j]) {
						v[i].push_back({ num_cnt[j],j });
					}
				}
			}
			for (int i = 0; i < len_row; i++) {
				for (int j = 0; j < len_col; j++) {
					map[i][j] = 0;
				}
			}
			for (int i = 0; i < len_row; i++) {
				sort(v[i].begin(), v[i].end());
			}
			for (int i = 0; i < len_row; i++) {
				int tmp = 0;
				for (int j = 0; j < v[i].size(); j++) {
					map[i][tmp++] = v[i][j].second;
					map[i][tmp++] = v[i][j].first;
					
					if (tmp >= MAXN) break;
				}
			}
		}
		// C 연산
		else {
			for (int j = 0; j < len_col; j++) {
				int num_cnt[MAXN + 1] = { 0, };
				for (int i = 0; i < len_row; i++) {
					num_cnt[map[i][j]]++;
				}
				for (int i = 1; i <= MAXN; i++) {
					if (num_cnt[i]) {
						v[j].push_back({ num_cnt[i],i });
					}
				}
			}
			for (int j = 0; j < len_col; j++) {
				for (int i = 0; i < len_col; i++) {
					map[i][j] = 0;
				}
			}
			for (int i = 0; i < len_col; i++) {
				sort(v[i].begin(), v[i].end());
			}
			for (int i = 0; i < len_col; i++) {
				int tmp = 0;
				for (int j = 0; j < v[i].size(); j++) {
					map[tmp++][i] = v[i][j].second;
					map[tmp++][i] = v[i][j].first;
					if (tmp >= MAXN) break;
				}
			}
		}
	}
	return 0;
}