#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 31
#define INF 987654321
using namespace std;

char map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N, M;
int ans;
int total_num;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int> > v;
void dfs(int x, int y, int d, int cnt, int num_dir) {
	if (ans < num_dir) return;
	if (cnt == total_num) {
		if (ans > num_dir) ans = num_dir;
		return;
	}
	int nx = x + dx[d];
	int ny = y + dy[d];
	if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && map[nx][ny] == '.') {
		visited[nx][ny] = true;
		dfs(nx, ny, d, cnt + 1, num_dir);
		visited[nx][ny] = false;
	}
	else {
		for (int k = 0; k < 4; k++) {
			if (k == d) continue;
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] == '.') {
				visited[nx][ny] = true;
				dfs(nx, ny, k, cnt + 1, num_dir + 1);
				visited[nx][ny] = false;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int idx = 1;
	while (cin >> N >> M) {
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		ans = INF;
		v.clear();
		total_num = 0;
		for (int i = 0; i < N; i++) {
			cin >> map[i];
			for (int j = 0; j < M; j++) {
				if (map[i][j] == '.') {
					v.push_back({ i,j });
					total_num++;
				}
			}
		}
		
		if (total_num == 1) {
			ans = 0;
		}
		else {
			for (int i = 0; i < v.size(); i++) {

				for (int k = 0; k < 4; k++) {
					visited[v[i].first][v[i].second] = true;
					dfs(v[i].first, v[i].second, k, 1, 1);
					visited[v[i].first][v[i].second] = false;
				}

			}
			if (ans == INF) ans = -1;
		}
		cout << "Case " << idx << ": " << ans << "\n";;
		idx++;
	}
	return 0;
}