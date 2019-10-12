/* 가로 M, 세로 N (1 <= N,M <= 100)
   0: 빈곳
   1: 벽
   (1,1), (N,M)은 항상 뚫려있음
   (N,M)으로 이동하기 위해 벽을 최소 몇개 부수어야 하는지 출력
   3 3
   011
   111
   110
   
   3
   
   4 2
   0001
   1000
   
   0
   
   6 6
   001111
   010000
   001111
   110001
   011010
   100010
   
   2*/
#include <iostream>
#include <queue>
#include <deque>

using namespace std;
#define MAXN 101
int N, M;
int map[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0 ,0 };

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
			dist[i][j] = -1;
		}
	}

	deque<pair<int, int>> q;
	q.push_back(make_pair(0, 0));
	dist[0][0] = 0;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop_front();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (dist[nx][ny] == -1) {
					if (map[nx][ny] == 0) {
						dist[nx][ny] = dist[cx][cy];
						q.push_front(make_pair(nx, ny));
					}
					else {
						dist[nx][ny] = dist[cx][cy] + 1;
						q.push_back(make_pair(nx, ny));
					}
				}
			}
		
		}
	}
	printf("%d", dist[N - 1][M - 1]);
	return 0;
}