#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define MAXN 50
using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
int N, M;
void Copy_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}
int main() {
	
	scanf("%d%d", &N, &M);
	char tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &tmp);
			if (tmp == 'W') {
				map[i][j] = 1;
				copy_map[i][j] = 1;
			}
			else {
				map[i][j] = 0;
				copy_map[i][j] = 0;
			}
		}
	}
	int ans = N * M;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int res1 = 0;
			int res2 = 0;
			//
			for (int x1 = i; x1 < i + 8; x1++) {
				for (int y1 = j; y1 < j + 8; y1++) {
					
					if ((x1 % 2 == 0 && y1 % 2 == 0) || (x1 % 2 == 1 && y1 % 2 == 1)) {
						if (map[x1][y1] == 1) res2++;
						if (map[x1][y1] == 0) res1++;
					}
					else{
						if (map[x1][y1] == 1) res1++;
						if (map[x1][y1] == 0) res2++;
					}
					
				}
			}
			ans = min(ans, min(res1, res2));
		}
	}
	printf("%d", ans);
	return 0;
}