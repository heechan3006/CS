#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100

using namespace std;

int map[MAXN][MAXN];
int R, C, K;
int main() {
	cin >> R >> C >> K;
	R--;
	C--;
	bool flag = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
			if (i == R && j == C && map[i][j] == K) {
				flag = true;
			}
		}
	}
	int row = 3;
	int col = 3;
	
	int time = 0;
	while (!flag) {

		time++;
		if (time > MAXN) {
			printf("-1\n");
			return 0;
		}
		vector < pair<int, int>> v[MAXN];
		if (row >= col) {
			for (int i = 0; i< row; i++){
				int cnt_row[MAXN+1] = { 0, };
				for (int j = 0; j < col; j++) {
					cnt_row[map[i][j]]++;
				}
				for (int j = 1; j <= MAXN; j++) {
					if (cnt_row[j]) {
						v[i].push_back({ cnt_row[j],j });
					}
				}
			}
			
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					map[i][j] = 0;
				}
			}
			for (int i = 0; i < row; i++) {
				sort(v[i].begin(), v[i].end());
			}
			for (int i = 0; i < row; i++) {
				int tmp = 0;
				for (int j = 0; j < v[i].size(); j++) {
					map[i][tmp++] = v[i][j].second;
					if (tmp == MAXN) break;
					map[i][tmp++] = v[i][j].first;
					if (tmp == MAXN) break;
				}
				col = max(col, tmp);
			}
		
		}
		else {
			for (int j = 0; j < col; j++) {
				int cnt_col[MAXN + 1] = { 0, };
				for (int i = 0; i < row; i++) {
					cnt_col[map[i][j]]++;
				}
				for (int i = 1; i <= MAXN; i++) {
					if (cnt_col[i]) {
						v[j].push_back({ cnt_col[i],i });
					}
				}
			}
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					map[i][j] = 0;
				}
			}
			for (int i = 0; i < col; i++) {
				sort(v[i].begin(), v[i].end());
			}
			for (int i = 0; i < col; i++) {
				int tmp = 0;
				for (int j = 0; j < v[i].size(); j++){
					map[tmp++][i] = v[i][j].second;
					if (tmp == MAXN) break;
					map[tmp++][i] = v[i][j].first;
					if (tmp == MAXN) break;
				}
				row = max(row, tmp);
			}
		}
		if (map[R][C] == K) {
			flag = true;
			break;
		}
	}
	printf("%d\n", time);
	return 0;
}
