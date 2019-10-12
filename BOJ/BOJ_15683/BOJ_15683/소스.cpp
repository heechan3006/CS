#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, M;
int map[9][9];
int copy_map[9][9];
vector<tuple<int, int,int>> v;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
vector<int> dirs;

void check(int x, int y, int dir) {
	int i = x;
	int j = y;
	while (0 <= i && i < N && 0 <= j && j < M) {
		if (map[i][j] == 6) break;
		copy_map[i][j] = map[x][y];
		i += dx[dir];
		j += dy[dir];
	}

}
int go(vector<tuple<int, int, int>> v, int index,vector<int> dirs) {
	if (v.size() == index) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < v.size(); i++) {
			int what, x, y;
			tie(what, x, y) = v[i];
			if (what == 1) {
				check(x, y, dirs[i]);
			}
			else if (what == 2) {
				check(x, y, dirs[i]);
				check(x, y, (dirs[i] + 2) % 4);
			}
			else if (what == 3) {
				check(x, y, dirs[i]);
				check(x, y, (dirs[i] + 1) % 4);
			}
			else if (what == 4) {
				check(x, y, dirs[i]);
				check(x, y, (dirs[i] + 1) % 4);
				check(x, y, (dirs[i] + 2) % 4);
			}
			else if (what == 5) {
				check(x, y, dirs[i]);
				check(x, y, (dirs[i] + 1) % 4);
				check(x, y, (dirs[i] + 2) % 4);
				check(x, y, (dirs[i] + 3) % 4);
			}
			
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_map[i][j] == 0) {
					cnt++;
				}
			}
		}
		return cnt;
	}
	int ans = 100;
	for (int i = 0; i < 4; i++) {
		dirs[index] = i;
		int temp = go(v, index + 1, dirs);
		if (ans > temp) {
			ans = temp;
		}
	}
	return ans;
}
int main() {
	scanf("%d%d", &N, &M);
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0 && map[i][j] != 6) {
				v.push_back({map[i][j], i,j });
				dirs.push_back(0);
			}
		}
	}

	int ans = go(v, 0, dirs);
	printf("%d\n", ans);

}