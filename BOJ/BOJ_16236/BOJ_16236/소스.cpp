#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
	int d;
	int x;
	int y;
};
bool compare(node a, node b) {
	if (a.d <= b.d) {
		if (a.d == b.d) {
			if (a.x <= b.x) {
				if (a.x == b.x) {
					if (a.y < b.y) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
int N;
int map[20][20];
int dist[20][20];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	cin >> N;
	int sx, sy;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sx = i;
				sy = j;
				map[sx][sy] = 0;
				
			}
		}
	}
	int level = 2;
	int cnt = 0;
	int time = 0;
	while (1){
		memset(dist, -1, sizeof(dist));
		q.push({ sx,sy });
		dist[sx][sy] = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (dist[nx][ny] != -1) continue;
				if (map[nx][ny] <= level) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
		vector<node> v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (0 < map[i][j] && map[i][j] < level && dist[i][j] != -1) {
					v.push_back({ dist[i][j],i,j });
				}
			}
		}
		if (!v.size()) break;
		sort(v.begin(), v.end(),compare);
		map[v[0].x][v[0].y] = 0;
		sx = v[0].x;
		sy = v[0].y;
		cnt++;
		time += v[0].d;
		if (cnt == level) {
			level++;
			cnt = 0;
		}
		
	}
	printf("%d\n", time);
	return 0;
}
