#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 50
using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];

int N, M, R, C, L;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
unsigned int num[] = { 0,15,12,3,5,9,10,6 };
int bfs() {
	queue<pair<int, int> > q;
	q.push({ R,C });
	visited[R][C] = true;
	int ans = 1;
	int cnt = 1;
	while (!q.empty()) {
		int q_size = q.size();
		if (cnt == L) break;
		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				
				if (!(num[map[x][y]] & (1<<k))) continue;
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visited[nx][ny]) continue;
				if (map[nx][ny] > 0 && map[nx][ny] < 4) {
					if (num[map[nx][ny]] & (1 << k)) {
						visited[nx][ny] = true;
						ans++;
						q.push({ nx,ny });
					}
				}
				else if (map[nx][ny]>=4) {
					if ((~(num[map[nx][ny]])%15) & (1 << k)) {
						visited[nx][ny] = true;
						ans++;
						q.push({ nx,ny });
					}
				}
			}
		}
		cnt++;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	freopen("input.txt", "r", stdin);
	cin >> t;

	for (int test_case = 1; test_case <= t; test_case++) {
		memset(visited, false, sizeof(visited));
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		cout << "#"<<test_case<<" "<<bfs() << "\n";
	}
	
	return 0;
}