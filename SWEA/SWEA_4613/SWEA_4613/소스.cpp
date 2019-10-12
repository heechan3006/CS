#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>

using namespace std;

int N, M;
char map[51][51];
int color[51][3];
int ans = 2e9;
void dfs(int ptr, int col, int sum, int flag[]) {

	if (ptr == N - 1) {
		for (int i = 0; i < 3; i++) {
			if (flag[i] == 0) return;
		}
		if (sum < ans) ans = sum;
		return;
	}
	for (int j = col; j <= col + 1 && j < 3; j++) {
		int check = 0;
		if (flag[j] == 0) {
			check = 1;
			flag[j] = 1;
		}
		dfs(ptr + 1, j, sum + color[ptr + 1][j], flag);
		if (check == 1) {
			flag[j] = 0;
			check = 0;
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case<=t; test_case++){
		scanf("%d %d", &N, &M);
		memset(map, 0, sizeof(map));
		memset(color, 0, sizeof(color));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %1c", &map[i][j]);
			
			}
		}
		ans = 2e9;
		for (int i = 0; i < N; i++) {
			if (i == 0) {
				for (int j = 0; j < M; j++) {
					if (map[i][j] != 'W') {
						color[i][0]++;
					}
				
				}
			}
			else if (i == 1) {
				for (int j = 0; j < M; j++) {
					if (map[i][j] != 'W') {
						color[i][0]++;
					}
					if (map[i][j] != 'B') {
						color[i][1]++;
					}
				}
			}
			else if (i == N - 2) {
				for (int j = 0; j < M; j++) {
					if (map[i][j] != 'R') {
						color[i][2]++;
					}
					if (map[i][j] != 'B') {
						color[i][1]++;
					}
				}
			}
			else if (i == N - 1) {
				for (int j = 0; j < M; j++) {
					if (map[i][j] != 'R') {
						color[i][2]++;
					}
				}
			}
			else {
				for (int j = 0; j < M; j++) {
					if (map[i][j] != 'W') {
						color[i][0]++;
					}
					if (map[i][j] != 'B') {
						color[i][1]++;
					}
					if (map[i][j] != 'R') {
						color[i][2]++;
					}
				}
			}	
		}
		int flag[3] = { 1,0,0 };
		dfs(0, 0, color[0][0], flag);
		printf("#%d %d\n", test_case,ans);
	}
	return 0;
}