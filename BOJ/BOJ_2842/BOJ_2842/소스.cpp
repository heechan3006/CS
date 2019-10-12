#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char map[51][51];
int weight[51][51];
bool visited[51][51];
int min_value = 98765432;
int max_value = 0;
int sx, sy;
int N;
int cnt = 0;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
vector<pair<int,int>> v;
vector<int> sv;

void dfs(int x, int y, int min_v, int max_v) {
	visited[x][y] = true;
	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (!visited[nx][ny] && (min_v <= weight[nx][ny] && weight[nx][ny] <= max_v)) {
			dfs(nx, ny, min_v, max_v);
		}
	}
}
bool DFS(int min_v, int max_v) {
	if (min_v > weight[sx][sy] || weight[sx][sy] > max_v) return false;
	memset(visited, false, sizeof(visited));
	dfs(sx, sy, min_v, max_v);
	for (int i = 0; i < v.size(); i++) {
		if (!visited[v[i].first][v[i].second]) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	sv.resize(N * N);
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'K') {
				v.push_back({ i,j });
			}
			else if (map[i][j] == 'P') {
				sx = i;
				sy = j;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> weight[i][j];
			sv[i * N + j] = weight[i][j];

		}
	}
	sort(sv.begin(), sv.end());
	sv.erase(unique(sv.begin(), sv.end()), sv.end());
	int low, high, mid;
	int ans = 98765432;
	for (int i = 0; i < sv.size(); i++){
		low = i;
		high = sv.size() - 1;
		
		while (low <= high) {
			mid = (low + high) / 2;
			if (DFS(sv[i],sv[mid])) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
		if (DFS(sv[i], sv[low])) {
			ans = min(ans, sv[low] - sv[i]);
		}
	}
	cout << ans << "\n";
}