#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101];
bool visited[101][101];
int M, N, K;
vector<int> v;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int cnt;
int dfs(int x, int y) {
	
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if (visited[nx][ny] || map[nx][ny]) continue;
		cnt = dfs(nx, ny) + 1;
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N >> K;
	for (int k = 0; k < K; k++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				map[i][j] = 1;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && !map[i][j]) {
				cnt = 1;
				int sum = dfs(i, j);
				v.push_back(sum);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	return 0;
}