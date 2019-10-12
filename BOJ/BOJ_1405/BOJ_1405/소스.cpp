#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int visited[30][30];

double dir[4];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int N, e, w, s, n;
double ret;
double dfs(int x, int y, int level) {
	if (level == 0) return 1;
	double ret = 0;
	visited[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (visited[nx][ny]) continue;
		ret += dfs(nx, ny, level - 1) * dir[k];
	}
	visited[x][y] = 0;
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%d", &N);
	for (int i = 0; i < 4; i++) {
		int tmp_dir;
		scanf("%d", &tmp_dir);
		dir[i] = double(tmp_dir) / 100;
	}

	
	printf("%.9lf\n", dfs(15, 15, N));
	return 0;
}