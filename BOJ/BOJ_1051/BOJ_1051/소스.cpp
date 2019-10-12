#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int map[51][51];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int min_len = min(N, M);
	int max_v = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 1; k < min_len; k++) {
				if (i + k >= N || j + k >= M) continue;
				if (map[i][j] == map[i][j + k] && map[i][j] == map[i + k][j] && map[i][j] == map[i + k][j + k]) {
					max_v = max(max_v, (k + 1) * (k + 1));
				}
			}
		}
	}
	printf("%d", max_v);
	return 0;
}
