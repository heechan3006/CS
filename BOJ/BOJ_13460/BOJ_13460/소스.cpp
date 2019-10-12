#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
char map[11][11];
bool check[11][11][11][11];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
queue<pair<pair<int, int>, pair<int, int>>> q;

int bfs(int red_x, int red_y, int blue_x, int blue_y) {
	q.push(make_pair(make_pair(red_x, red_y), make_pair(blue_x, blue_y)));
	check[red_x][red_y][blue_x][blue_y] = true;
	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int tmp_rx = q.front().first.first;
			int tmp_ry = q.front().first.second;
			int tmp_bx = q.front().second.first;
			int tmp_by = q.front().second.second;
			q.pop();
			// red
			if (map[tmp_rx][tmp_ry] == 'O' && map[tmp_rx][tmp_ry] != map[tmp_bx][tmp_by]) {
				return cnt;
			}
			for (int k = 0; k < 4; k++) {
				int rx = tmp_rx;
				int ry = tmp_ry;
				int bx = tmp_bx;
				int by = tmp_by;
				while (map[rx + dx[k]][ry + dy[k]] != '#' && map[rx][ry] != 'O') {
					rx = rx + dx[k];
					ry = ry + dy[k];
				}
				while (map[bx + dx[k]][by + dy[k]] != '#' && map[bx][by] != 'O') {
					bx = bx + dx[k];
					by = by + dy[k];
				}
				if (rx == bx && ry == by) {
					if (map[rx][ry] == 'O') continue;
					if (abs(rx - tmp_rx) + abs(ry - tmp_ry) < abs(bx - tmp_bx) + abs(by - tmp_by)) {
						bx -= dx[k];
						by -= dy[k];
					}
					else {
						rx -= dx[k];
						ry -= dy[k];
					}
					/*
					if (k == 0) {
						if (tmp_by > tmp_ry) ry -= 1;
						else by -= 1;
					}
					else if (k == 1) {
						if (tmp_by > tmp_ry) by += 1;
						else ry += 1;
					}
					else if (k == 2) {
						if (tmp_bx > tmp_rx) rx -= 1;
						else bx -= 1;
					}
					else {
						if (tmp_bx > tmp_rx) by += 1;
						else rx += 1;
					}*/

				}
				if (check[rx][ry][bx][by]) continue;
				
				check[rx][ry][bx][by] = true;
				q.push(make_pair(make_pair(rx, ry), make_pair(bx, by)));

			}
		}
		if (cnt == 10) return -1;
		cnt += 1;
	}
	return -1;
}
int main() {
	int red_x, red_y,blue_x,blue_y;
	cin >> n >> m;
	
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'R') {
				red_x = i;
				red_y = j;
			}
			else if (map[i][j] == 'B') {
				blue_x = i;
				blue_y = j;
			}
			
		}
	}
	cout << bfs(red_x, red_y, blue_x, blue_y) << '\n';
	
}