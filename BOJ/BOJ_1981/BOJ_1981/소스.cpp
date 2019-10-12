#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
bool visited[101][101];
int min_value = 98765432;
int max_value = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int N;
bool BFS(int diff) {
	for (int i = min_value; i <= max_value; i++) {
		memset(visited, true, sizeof(visited));
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (i <= map[j][k] && map[j][k] <= i + diff) visited[j][k] = false;
			}
		}
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			if (visited[cx][cy]) continue;
			visited[cx][cy] = true;
			if (cx == N-1 && cy == N-1) return true;
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				q.push({ nx,ny });
			}
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (min_value > map[i][j]) min_value = map[i][j];
			if (max_value < map[i][j]) max_value = map[i][j];
		}
	}
	int low = 0;
	int high = max_value - min_value;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (BFS(mid)) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << high+1 << "\n";
	return 0;
}