#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXN 101
using namespace std;

struct node {
	int x;
	int y;
	int s;
	int d;
	int z;
};
vector<node> map[MAXN][MAXN];
int R, C, M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
bool compare(node a, node b) {
	if (a.z > b.z) return true;
	return false;
}
int change_dir(int dir) {
	if (dir == 0) return 1;
	else if (dir == 1) return 0;
	else if (dir == 2) return 3;
	else return 2;
}
int main() {
	scanf("%d%d%d", &R, &C, &M);
	//map.resize(R + 1, vector<node> (C + 1));
	
	for (int i = 0; i < M; i++) {
		int x, y, s, d, z;
		scanf("%d%d%d%d%d", &x, &y, &s, &d, &z);
		d--;
		map[x][y].push_back({ x,y,s,d,z });
	}
	int ans = 0;
	for (int j =1 ; j <= C; j++){
		for (int i = 1; i <= R; i++) {
			if (map[i][j].size()) {
				ans += map[i][j][0].z;
				map[i][j].erase(map[i][j].begin());
				break;
			}
		}
		queue<node> q;
		for (int i = 1; i <= R; i++) {
			for (int k = 1; k <= C; k++) {
				if (map[i][k].size() > 0) {
					q.push({ map[i][k][0] });
				}
			}
		}
		for (int i = 1; i <= R; i++) {
			for (int k =1; k <= C; k++){
				map[i][k].clear();
			}
		}
		
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int s = q.front().s;
			int d = q.front().d;
			int z = q.front().z;
			int tmp_s = s;
			q.pop();
			while (tmp_s-- > 0) {
				x += dx[d];
				y += dy[d];
				if (x <= 0 || y <= 0 || x > R || y > C) {
					d = change_dir(d);
					x += 2*dx[d];
					y += 2*dy[d];
				}
			}
			map[x][y].push_back({ x,y,s,d,z });
			
		}
		for (int i = 1; i <= R; i++) {
			for (int k = 1; k <= C; k++) {
				if (map[i][k].size() > 1) {
					sort(map[i][k].begin(), map[i][k].end(), compare);
					map[i][k].erase(map[i][k].begin() + 1, map[i][k].end());
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
