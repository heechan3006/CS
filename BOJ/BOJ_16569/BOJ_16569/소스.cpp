#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 100 
#define INF 987654321
using namespace std;

int fire_dist[MAXN][MAXN];
int dist[MAXN][MAXN];
int map[MAXN][MAXN];
int N, M, V;
int sx, sy;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
struct node {
	int x;
	int y;
	int time;
};
struct res {
	int height;
	int time;
};
vector<node> mountain;
res bfs() {
	res ans;
	
	queue<pair<int, int>> fire_q;
	for (int i = 0; i < mountain.size(); i++) {
		fire_dist[mountain[i].x][mountain[i].y] = mountain[i].time;
		fire_q.push({ mountain[i].x,mountain[i].y });
	}
	while (!fire_q.empty()) {
		int x = fire_q.front().first;
		int y = fire_q.front().second;
		fire_q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (fire_dist[nx][ny] > fire_dist[x][y]+1) {
				fire_dist[nx][ny] = fire_dist[x][y]+1;
				fire_q.push({ nx,ny });
			}
		}
	}
	for (int i = 0; i < mountain.size(); i++) {
		fire_dist[mountain[i].x][mountain[i].y] = -1;
	}
	queue<pair<int, int>> q;
	
	q.push({sx,sy});
	ans.height = map[sx][sy];
	ans.time = 0;
	dist[sx][sy] = 0;
	while (!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (dist[nx][ny] != -1) continue;
			if (fire_dist[nx][ny] > dist[x][y] + 1) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
				if (map[nx][ny] > ans.height) {
					ans.height = map[nx][ny];
					ans.time = dist[nx][ny];
				}
			}
		}
	}
	
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> V;
	cin >> sx >> sy;
	sx--;
	sy--;
	memset(dist, -1, sizeof(dist));
	fill(&fire_dist[0][0], &fire_dist[N-1][M-1]+1, INF);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < V; i++) {
		int tmp_x, tmp_y, tmp_time;
		cin >> tmp_x >> tmp_y >> tmp_time;
		tmp_x--;
		tmp_y--;
		mountain.push_back({ tmp_x,tmp_y,tmp_time });
		
	}
	res ans = bfs();
	cout << ans.height << " "<<ans.time << "\n";
	return 0;
}