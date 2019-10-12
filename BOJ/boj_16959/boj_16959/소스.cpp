#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 10
using namespace std;

int map[MAXN][MAXN];
int dist[3][MAXN][MAXN][MAXN*MAXN+1];
int N;
int sx, sy;
vector<pair<int,int> > dirs[3];
int horse_move[][2] = { {-2,-1},{-2,1},{1,2},{-1,2},{2,1},{2,-1},{1,-2},{-1,-2} };
int bishop[][2] = { {-1,-1},{-1,1},{1,1},{1,-1} };
int look[][2] = { {-1,0},{0,1},{1,0},{0,-1} };
struct node {
	int x;
	int y;
	int kind;
	int num;
};
int bfs() {
	memset(dist, -1, sizeof(dist));
	queue<node> q;
	int ans = 987654321;
	for (int i = 0; i < 3; i++) {
		q.push({ sx,sy,i,1});
		dist[i][sx][sy][1] = 0;
	}
	
	while (!q.empty()) {
		
		int cx = q.front().x;
		int cy = q.front().y;
		int kind = q.front().kind;
		int num = q.front().num;
		q.pop();
		if (num == N * N) {
			ans = min(ans, dist[kind][cx][cy][num]);
			continue;
		}
		
		for (int i = 0; i < 3; i++) {
			// move
			if (i == kind) {
				for (int k = 0; k < dirs[kind].size(); k++) {
					int nx = cx + dirs[kind][k].first;
					int ny = cy + dirs[kind][k].second;
					
					if (i == 0) {
						int n = num;
						if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
						if (map[nx][ny] == num + 1) {
							n += 1;
						}
						if (dist[i][nx][ny][n] != -1) continue;
						dist[i][nx][ny][n] = dist[i][cx][cy][num]+1;
						q.push({ nx,ny,i,n});
					}
					else {
						while (nx >= 0 && ny >= 0 && nx < N && ny < N) {
							int n = num;
							if (map[nx][ny] == n + 1) {
								n += 1;
							}
							if (dist[i][nx][ny][n] == -1) {
								dist[i][nx][ny][n] = dist[i][cx][cy][num]+1;
								q.push({ nx,ny,i,n});
							}
							
							nx += dirs[i][k].first;
							ny += dirs[i][k].second;
						}
					}
				}
			}
			else {
				if (dist[i][cx][cy][num]!=-1) continue;
				dist[i][cx][cy][num] = dist[kind][cx][cy][num]+1;
				q.push({ cx,cy,i,num });
			}
		}
	}
	
	
	return ans;
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				sx = i;
				sy = j;
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		dirs[0].push_back({ horse_move[i][0],horse_move[i][1] });
	}
	for (int i = 0; i < 4; i++) {
		dirs[1].push_back({ bishop[i][0],bishop[i][1] });
		dirs[2].push_back({ look[i][0],look[i][1] });
	}
	int ans = bfs();
	
	cout << ans << "\n";
	return 0;
	
}
