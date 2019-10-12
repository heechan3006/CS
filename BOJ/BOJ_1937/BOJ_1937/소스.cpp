#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int D[501][501];
int A[501][501];
int N;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int go(int x, int y) {
	if (D[x][y] != -1) return D[x][y];
	D[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (A[nx][ny] > A[x][y]) {
			D[x][y] = max(D[x][y],go(nx, ny) + 1);	
		}
	}
	return D[x][y];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	memset(D, -1, sizeof(D));
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = go(i, j);
			if (ans < tmp) ans = tmp;
		}
	}
	cout << ans << "\n";
}
