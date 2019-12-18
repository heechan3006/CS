#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 500;

long long cache[MAXN][MAXN];
int map[MAXN][MAXN];
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
long long go(int x, int y) {
	if (x == N - 1 && y == M - 1) return 1;
	long long& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (map[x][y] > map[nx][ny]) {
			ret += go(nx, ny);
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	cout << go(0, 0) << "\n";
}