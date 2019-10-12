#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int map[20][20];
int dist[20][20][1<<11];
bool visited[10];
int W, H;
int sx, sy;
int room;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans;
int all;
bool flag = false;
struct node {
	int x;
	int y;
	int idx;
};

queue<node> q;
int bfs() {
	
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cur_idx = q.front().idx;
		q.pop();
		if (cur_idx == all){
			return dist[x][y][cur_idx];
		}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W || map[nx][ny] ==-1) continue;
			if (map[nx][ny] > 0) {
				if (!dist[nx][ny][cur_idx | (1 << (map[nx][ny] - 1))]) {
					q.push({ nx,ny,cur_idx | (1 << (map[nx][ny] - 1)) });
					dist[nx][ny][cur_idx | (1 << (map[nx][ny] - 1))] = dist[x][y][cur_idx] + 1;
				}
			}
			if (map[nx][ny]  == 0) {
				if (!dist[nx][ny][cur_idx]) {
					q.push({ nx,ny,cur_idx });
					dist[nx][ny][cur_idx] = dist[x][y][cur_idx] + 1;
				}
			}
			
		}
	}
	return -1;
}

int main() {
	
	while (1){
		
		flag = false;
		room = 0;
		scanf("%d%d", &W, &H);
		
		if (W == 0 && H == 0) break;
		
		vector<node> v;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				char tmp;
				scanf(" %1c", &tmp);
				if (tmp == 'o') {
					
					q.push({ i,j,0 });
				}
				else if (tmp == '*') {
					room++;
					map[i][j] = room;
					
					
				}
				else if (tmp == 'x') {
					map[i][j] = -1;
				}
			}
		}
		all = (1 << room) - 1;
		int ans = bfs();
		cout << ans << "\n";
		
		memset(dist, 0, sizeof(dist));
		memset(map, 0, sizeof(map));
		while (!q.empty()) q.pop();
	}
}