#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INF 1e9

int N;
int op[4];
int number[12];
int min_v;
int max_v;
void dfs(int now, int sum) {
	if (now == N - 1) {
		if (min_v > sum) min_v = sum;
		if (max_v < sum) max_v = sum;
		return;
	}
	if (op[0] > 0) {
		op[0]--;
		dfs(now + 1, sum + number[now + 1]);
		op[0]++;
	}
	if (op[1] > 0) {
		op[1]--;
		dfs(now + 1, sum - number[now + 1]);
		op[1]++;
	}
	if (op[2] > 0) {
		op[2]--;
		dfs(now + 1, sum * number[now + 1]);
		op[2]++;
	}
	if (op[3] > 0) {
		op[3]--;
		dfs(now + 1, sum / number[now + 1]);
		op[3]++;
	}
	
}
int main() {
	
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {

		scanf("%d", &N);
		for (int i = 0; i < 4; i++) {
			scanf("%d", &op[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &number[i]);
		}
		min_v = INF;
		max_v = -INF;
		dfs(0, number[0]);
		printf("#%d %d\n", test_case, max_v - min_v);
	}
	return 0;
}