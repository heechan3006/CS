#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 500
using namespace std;

char map[MAXN][MAXN];
bool check[MAXN][MAXN];
int visited[MAXN][MAXN];
int N, M;
int cnt = 0;
vector<pair<int, int>> v;
void dfs(int x, int y) {
	check[x][y] = true;
	v.push_back({ x,y });
	int nx, ny;
	if (map[x][y] == 'U') {
		nx = x - 1;
		ny = y;
	}
	else if (map[x][y] == 'D') {
		nx = x + 1;
		ny = y;
	}
	else if (map[x][y] == 'L') {
		nx = x;
		ny = y - 1;
	}
	else {
		nx = x;
		ny = y + 1;
	}
	if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
		cnt += v.size();
		for (int i = 0; i < v.size(); i++) {
			visited[v[i].first][v[i].second] = 1;
		}
		return;
	}
	if (check[nx][ny]) {
		if (visited[nx][ny] == 1) {
			cnt += v.size();
			for (int i = 0; i < v.size(); i++) {
				visited[v[i].first][v[i].second] = 1;
			}
			return;
		}
		else {
			for (int i = 0; i < v.size(); i++) {
				visited[v[i].first][v[i].second] = -1;
			}
			return;
		}
	}
	
	
	dfs(nx, ny);

}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == false) {
				v.clear();
				dfs(i, j);
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}