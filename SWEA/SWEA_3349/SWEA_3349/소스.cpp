#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int W, H, N;

int map[10001][10001];
bool visited[10001][10001];
int dx[] = { 0,0,1,-1,-1,1 };
int dy[] = { 1,-1,0,0,-1,1 };
vector<pair<int, int>> v;

int bfs(int x, int y,int cnt) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		if (cx == v[cnt+1].first && cy == v[cnt+1].second) return map[cx][cy];
		q.pop();
		for (int k = 0; k < 6; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 1 || nx > H || ny < 1 || ny > W) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			map[nx][ny] = map[cx][cy] + 1;
			q.push({ nx,ny });
			
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case= 1; test_case<=t; test_case++){
		scanf("%d %d %d", &W, &H, &N);
		for (int i = 0; i < N; i++) {
			int tmp_x, tmp_y;
			scanf("%d %d", &tmp_y, &tmp_x);
			v.push_back({ tmp_x,tmp_y });
		}
		int ans = 0;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < v.size()-1; i++) {
			memset(visited, false, sizeof(visited));
			ans = bfs(v[i].first, v[i].second,i);
		}
		printf("#%d %d\n", test_case,ans);
	}
	return 0;
}