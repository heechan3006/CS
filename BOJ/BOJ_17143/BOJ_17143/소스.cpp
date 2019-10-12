#include <iostream>
#include <queue>
#include <vector>

#define MAXN 101
using namespace std;
struct shark {
	int s;
	int d;
	int z;
};
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };
vector<shark> map[MAXN][MAXN];
int R, C, M, r, c, s, d, z;
void move_shark(queue<pair<pair<int, int>, shark>> q) {
	int nx, ny;
	while (!q.empty()) {
		int cur_s = q.front().second.s;
		int cur_d = q.front().second.d;
		int cur_z = q.front().second.z;
		int x = q.front().first.first;
		int y = q.front().first.second;
		q.pop();
		nx = x;
		ny = y;
		for (int i = 0; i < cur_s; i++) {
			
			if (cur_d == 1 || cur_d == 2) {
				int next = nx + dx[cur_d];
				if (!(1 <= next && next <= R)) {
					if (cur_d == 1) cur_d = 2;
					else if (cur_d == 2) cur_d = 1;
				}
				nx += dx[cur_d];
			}
			if (cur_d == 3 || cur_d == 4) {
				int next = ny + dy[cur_d];
				if (!(1 <= next && next <= C)) {
					if (cur_d == 3) cur_d = 4;
					else if (cur_d == 4) cur_d = 3;
				}
				ny += dy[cur_d];
			}
		}
		if (map[nx][ny].size()) {
			if (map[nx][ny][0].z < cur_z) {
				map[nx][ny].clear();
				map[nx][ny].push_back({ cur_s,cur_d,cur_z });
			}
		}
		else {
			map[nx][ny].push_back({ cur_s,cur_d,cur_z });
		}
	}
}
int main() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		map[r][c].push_back({ s,d,z });
	}
	int ans = 0;
	
	for (int j = 1; j <= C; j++) {
		for (int i = 1; i <= R; i++) {
			if (map[i][j].size()) {
				ans += map[i][j][0].z;
				map[i][j].clear();
				
				break;
			}
		}
		queue < pair<pair<int, int>, shark>> q;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j].size()) {
					q.push({ { i,j }, { map[i][j][0] } });
					map[i][j].clear();
				}
			}
		}
		move_shark(q);
	}
	printf("%d\n", ans);
}
