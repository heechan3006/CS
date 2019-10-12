#include <iostream>
#include <algorithm>
#define MAXN 300
using namespace std;

int N, M, R;
int sx, sy, ex, ey;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int map[MAXN][MAXN];

void rotate_arr(int k, int r) {
	while (r--) {
		for (int t = 0; t < k; t++) {
			int tmp = map[t][t];
			for (int j = t + 1; j < M - t; j++) {
				map[t][j - 1] = map[t][j];
			}
			for (int i = t + 1; i < N - t; i++) {
				map[i - 1][M - t - 1] = map[i][M - t - 1];
			}
			for (int j = M - t - 2; j >= t; j--) {
				map[N - t - 1][j + 1] = map[N - t - 1][j];
			}
			for (int i = N - t - 2; i > t; i--) {
				map[i + 1][t] = map[i][t];
			}
			map[t + 1][t] = tmp;
		}
	}
}
int main() {
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int k = min(N, M) / 2;
	rotate_arr(k, R);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}