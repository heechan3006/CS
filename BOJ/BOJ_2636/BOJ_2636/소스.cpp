#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAXN 100
using namespace std;

int N,M;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j]) cnt++;
		}
	}
	int time = 0;
	while (1){
		time++;
		memset(visited, false, sizeof(visited));
		queue<pair<int, int>> q;
		vector<pair<int, int>> v;
		q.push({ 0,0 });
		visited[0][0] = true;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visited[nx][ny]) continue;
				if (map[nx][ny] == 0) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
				else {
					visited[nx][ny] = true;
					v.push_back({ nx,ny });
				}
			}
		}
		if (cnt != 0) {
			for (int i = 0; i < v.size(); i++) {
				map[v[i].first][v[i].second] = 0;
				cnt--;
			}
			if (cnt == 0) {
				printf("%d\n", time);
				printf("%d\n", v.size());
				break;
			}
		}
	}
	return 0;
}
