#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char map[51][51];
bool visited[51][51][64];
int N, M;
int sx, sy;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
struct node {
	int x;
	int y;
	int cnt;
	int key;
};
int bfs(int x, int y) {
	queue<node> q;
	q.push({ x,y,0,0 });
	visited[x][y][0] = true;
	while (!q.empty()) {
		int q_size = q.size();
		while (q_size--){
			int cx = q.front().x;
			int cy = q.front().y;
			int cur_cnt = q.front().cnt;
			int cur_key = q.front().key;
			if (map[cx][cy] == '1') {
				return cur_cnt;
			}
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if ((map[nx][ny] == '.'||map[nx][ny]=='0'||map[nx][ny] =='1') && !visited[nx][ny][cur_key]) {
					visited[nx][ny][cur_key] = true;
					q.push({ nx,ny,cur_cnt + 1,cur_key });
				}
				else if ('a' <= map[nx][ny] && map[nx][ny] <= 'f' && !visited[nx][ny][cur_key|(1<<(map[nx][ny]-'a'))]) {
					visited[nx][ny][cur_key | (1 << (map[nx][ny] - 'a'))] = true;
					q.push({ nx,ny,cur_cnt + 1,cur_key | (1 << (map[nx][ny] - 'a')) });
				}
				else if ('A' <= map[nx][ny] && map[nx][ny] <= 'F' && !visited[nx][ny][cur_key]) {
					if ((1 << map[nx][ny] - 'A') & cur_key) {
						visited[nx][ny][cur_key] = true;
						q.push({ nx,ny,cur_cnt + 1,cur_key });
					}
				}
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	
	
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '0') {
				sx = i;
				sy = j;
			}
		}
	}
	int ans = bfs(sx, sy);
	cout << ans << "\n";
}
