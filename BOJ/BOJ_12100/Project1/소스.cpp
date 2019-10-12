#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[20][20];
int used[5];
int copy_map[20][20];
int N;
int ans = 0;

int go() {
	// 1 : up, 2 : down, 3: left, 4 : right
	int cnt = 0;
	while (cnt <= 4) {
		queue<int> q;
		if (used[cnt] == 1) {
			for (int j = 0; j < N; j++) {
				for (int i = 0; i < N; i++) {
					if (copy_map[i][j]) {
						q.push(copy_map[i][j]);
					}
					copy_map[i][j] = 0;
				}
				int idx = 0;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					if (copy_map[idx][j] == 0) {
						copy_map[idx][j] = cur;
						
					}
					else if (copy_map[idx][j] == cur) {
						copy_map[idx][j] *= 2;
						idx++;
					}
					else if (copy_map[idx][j] != cur) {
						idx++;
						copy_map[idx][j] = cur;
					}
				}
			}
		}
		else if (used[cnt] == 2) {
			for (int j = 0; j < N; j++) {
				for (int i = N-1; i >= 0; i--) {
					if (copy_map[i][j]) {
						q.push(copy_map[i][j]);
					}
					copy_map[i][j] = 0;
				}
				int idx = N-1;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					if (copy_map[idx][j] == 0) {
						copy_map[idx][j] = cur;

					}
					else if (copy_map[idx][j] == cur) {
						copy_map[idx][j] *= 2;
						idx--;
					}
					else if (copy_map[idx][j] != cur) {
						idx--;
						copy_map[idx][j] = cur;
					}
				}
			}
		}
		else if (used[cnt] == 3) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (copy_map[i][j]) {
						q.push(copy_map[i][j]);
					}
					copy_map[i][j] = 0;
				}
				int idx = 0;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					if (copy_map[i][idx] == 0) {
						copy_map[i][idx] = cur;

					}
					else if (copy_map[i][idx] == cur) {
						copy_map[i][idx] *= 2;
						idx++;
					}
					else if (copy_map[i][idx] != cur) {
						idx++;
						copy_map[i][idx] = cur;
					}
				}
			}
		}
		else if (used[cnt] == 4) {
			for (int i = 0; i < N; i++) {
				for (int j = N - 1; j >= 0; j--) {
					if (copy_map[i][j]) {
						q.push(copy_map[i][j]);
					}
					copy_map[i][j] = 0;
				}
				int idx = N - 1;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					if (copy_map[i][idx] == 0) {
						copy_map[i][idx] = cur;

					}
					else if (copy_map[i][idx] == cur) {
						copy_map[i][idx] *= 2;
						idx--;
					}
					else if (copy_map[i][idx] != cur) {
						idx--;
						copy_map[i][idx] = cur;
					}
				}
			}
		}
		cnt++;
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (res < copy_map[i][j]) res = copy_map[i][j];
		}
	}
	return res;
}
void dfs(int cnt) {
	if (cnt >= 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		int sum = go();
		if (ans < sum) ans = sum;
		return;
	}
	for (int i = 1; i <= 4; i++) {
		if (!used[cnt]) {
			used[cnt] = i;
			dfs(cnt + 1);
			used[cnt] = 0;
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}