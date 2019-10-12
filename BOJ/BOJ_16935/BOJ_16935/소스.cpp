#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 100
using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
int order[1000];
int N, M, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		cin >> order[i];
	}
	for (int t = 0; t < R; t++) {
		memcpy(copy_map, map, sizeof(map));
		
		// 상하 반전
		if (order[t] == 1) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					copy_map[N - i - 1][j] = map[i][j];
				}
			}
		}
		// 좌우 반전
		else if (order[t] == 2) {
			for (int j = 0; j < M; j++) {
				for (int i = 0; i < N; i++) {
					copy_map[i][M - j - 1] = map[i][j];
				}
			}
		}
		else if (order[t] == 3) {
			memset(copy_map, 0, sizeof(copy_map));
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					copy_map[j][N - i - 1] = map[i][j];
				}
			}
			memset(map, 0, sizeof(map));
			int tmp = N;
			N = M;
			M = tmp;
		}
		else if (order[t] == 4) {
			memset(copy_map, 0, sizeof(copy_map));
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					copy_map[M - j - 1][i] = map[i][j];
				}
			}
			memset(map, 0, sizeof(map));
			int tmp = N;
			N = M;
			M = tmp;
		}
		else if (order[t] == 5) {
		
			for (int i = 0; i < N / 2; i++) {
				for (int j = 0; j < M / 2; j++) {
					copy_map[i][j] = map[i + N / 2][j];
					copy_map[i + N / 2][j] = map[i + N / 2][j + M/2];
					copy_map[i + N / 2][j + M / 2] = map[i][j + M / 2];
					copy_map[i][j + M / 2] = map[i][j];
					copy_map[i][j + M / 2 ] = map[i][j];
				}
			}
		}
		else{
			
			for (int i = 0; i < N / 2; i++) {
				for (int j = 0; j < M / 2; j++) {
					copy_map[i][j] = map[i][j + M / 2];
					copy_map[i][j + M / 2] = map[i + N / 2][j + M / 2];
					copy_map[i + N / 2][j + M / 2] = map[i + N / 2][j];
					copy_map[i + N / 2][j] = map[i][j];
				}
			}
		}
		memcpy(map, copy_map, sizeof(map));
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << copy_map[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}