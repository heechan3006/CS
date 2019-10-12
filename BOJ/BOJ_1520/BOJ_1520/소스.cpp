#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int map[1001][1001];
int D[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int go(int x, int y) {
	if (x == N - 1 && y == M - 1) return 1;
	if (D[x][y] != -1) return D[x][y];
	D[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (map[nx][ny] < map[x][y]) {
			D[x][y] += go(nx, ny);
		}
	}
	return D[x][y];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	memset(D, -1, sizeof(D));
	
	cout << go(0, 0) << "\n";

}