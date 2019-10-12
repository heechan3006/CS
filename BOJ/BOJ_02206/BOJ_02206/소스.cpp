#include <iostream>
#include <queue>
#include <tuple>

#define MAXN 1000
using namespace std;

int N, M;
int map[MAXN][MAXN];
int dist[MAXN][MAXN][2];
int dx[] = { 0,0, 1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	queue<tuple<int, int, int>> q;
	dist[0][0][0] = 1;
	q.push(make_tuple(0, 0, 0));
	while (!q.empty()) {
		int cx, cy, flag;
		tie(cx, cy, flag) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				continue;
			}
			
			if (map[nx][ny] == 0 && dist[nx][ny][flag] == 0) {
					
				dist[nx][ny][flag] = dist[cx][cy][flag] + 1;
				q.push(make_tuple(nx, ny,flag));
			}
			if (flag == 0 && map[nx][ny] == 1 && dist[nx][ny][flag + 1] == 0) {
				dist[nx][ny][flag + 1] = dist[cx][cy][flag] + 1;
				q.push(make_tuple(nx, ny, flag+1));
				
			}
			
			
		}
		

	}
	if (dist[N - 1][M - 1][0] != 0 && dist[N - 1][M - 1][1] != 0) {
		printf("%d", min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]));
	}
	else if (dist[N - 1][M - 1][0] != 0) {
		printf("%d", dist[N - 1][M - 1][0]);
	}
	else if (dist[N - 1][M - 1][1] != 0) {
		printf("%d", dist[N - 1][M - 1][1]);
	}
	else {
		cout << -1;
	}
	return 0;
}