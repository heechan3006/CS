//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 50
using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N, L, R;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int sum = 0;
vector<pair<int, int>> v;
void dfs(int x, int y) {
	v.push_back({ x,y });
	sum += map[x][y];
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (!visited[nx][ny] && abs(map[nx][ny]-map[x][y])>=L && abs(map[nx][ny]-map[x][y])<=R) {
			dfs(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	while (1) {
		bool flag = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				v.clear();
				sum = 0;
				dfs(i, j);
				if (v.size() > 1) flag = true;
				int cnt = v.size();
				for (int k = 0; k < v.size(); k++) {
					map[v[k].first][v[k].second] = sum / cnt;
				}
			}
		}
		if (!flag) break;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}