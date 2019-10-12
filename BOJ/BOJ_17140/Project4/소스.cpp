#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAXN 100
using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];

int R, C, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> K;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	if (map[R - 1][C - 1] == K) {
		cout << "0\n";
		return 0;
	}
	int time = 0;
	int max_row, max_col;
	while (1) {
		if (map[R - 1][C - 1] == K) {
			cout << time << "\n";
			return 0;
		}
		if (time >= 100) {
			cout << "-1\n";
			return 0;
		}
		max_row = 0;
		max_col = 0;
		bool flag = false;
		for (int j = 0; j < MAXN && !flag; j++) {
			int row = 0;
			
			for (int i = 0; i < MAXN; i++) {
				if (i == 0 && map[i][j] == 0) {
					flag = true;
					break;
				}
				if (map[i][j] == 0) break;
				row++;
			}
			if (row > max_row) max_row = row;
		}
		flag = false;
		for (int i = 0; i < MAXN && !flag; i++) {
			int col = 0;
			for (int j = 0; j < MAXN; j++) {
				if (j == 0 && map[i][j] == 0) {
					flag = true;
					break;
				}
				if (map[i][j] == 0) break;
				col++;
			}
			if (col > max_col) max_col = col;
		}
		if (max_row >= max_col) {
			for (int i = 0; i < max_row; i++) {
				int num[MAXN + 1] = { 0, };
				vector<pair<int, int> >v;
				int max_v = 0;
				for (int j = 0; j < max_col; j++) {
					if (!map[i][j]) continue;
					num[map[i][j]] += 1;
					max_v = max(max_v, map[i][j]);
					map[i][j] = 0;
				}
				for (int j = 1; j <= max_v; j++) {
					if (!num[j]) continue;
					v.push_back({ num[j],j });
				}
				sort(v.begin(), v.end());
				
				int idx = 0;
				for (int j = 0; j < min((int)v.size(),MAXN/2); j++) {
					map[i][idx++] = v[j].second;
					map[i][idx++] = v[j].first;
				}
			}
		}
		else {
			for (int j = 0; j < max_col; j++) {
				int num[MAXN + 1] = { 0, };
				vector<pair<int, int> >v;
				int max_v = 0;
				for (int i = 0; i < max_row; i++) {
					if (!map[i][j]) continue;
					num[map[i][j]] += 1;
					max_v = max(max_v, map[i][j]);
					map[i][j] = 0;
				}
				for (int i = 1; i <= max_v; i++) {
					if (!num[i]) continue;
					v.push_back({ num[i],i });
				}
				sort(v.begin(), v.end());
				int idx = 0;
				for (int i = 0; i < min((int)v.size(),MAXN/2); i++) {
					map[idx++][j] = v[i].second;
					map[idx++][j] = v[i].first;
					
				}
			}
		}
		time++;
	}
	return 0;
}