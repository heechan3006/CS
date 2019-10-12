#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAXN 51
using namespace std;

char map[MAXN][MAXN];
int weight[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N;
vector<int> v;
vector<pair<int, int>> house;
int sx, sy;
int ans;
int cnt = 0;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int dfs(int x, int y, int min_v, int max_v) {
	
	visited[x][y] = true;
	if (weight[x][y] < min_v || weight[x][y] > max_v) return 0;
	int ret = map[x][y] == 'K';
	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (!visited[nx][ny]) {
			ret += dfs(nx, ny, min_v, max_v);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'P') {
				sx = i, sy = j;
			}
			else if (map[i][j] == 'K') {
				cnt++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> weight[i][j];
			v.push_back(weight[i][j]);
		}
	}
	ans = 987654321;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int low=0, high=0,mid;
	while (1) {
		memset(visited, false, sizeof(visited));
		if (dfs(sx, sy, v[low], v[high]) == cnt) {
			ans = min(ans, v[high] - v[low]);
			low++;
		}
		else if (++high == v.size()) {
			break;
		}
	}

	cout << ans << "\n";
	return 0;
}