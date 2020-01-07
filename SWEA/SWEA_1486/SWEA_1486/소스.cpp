#include <stdio.h>

#define MAXN 20
#define INF 987654321

int person[MAXN];
int N, B;
int ans;

void dfs(int idx, int sum) {
	if (sum >= ans) return;
	if (sum >= B) {
		if (ans > sum) ans = sum;
		return;
	}
	if (idx >= N) {
		return;
	}
	dfs(idx + 1,sum + person[idx]);
	dfs(idx + 1, sum);
}
int main() {
	
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		ans = INF;
		scanf("%d%d", &N, &B);
		for (int i = 0; i < N; i++) {
			scanf("%d", &person[i]);
		}
		dfs(0, 0);
		printf("#%d %d\n", test_case, ans - B);
	}
	return 0;
}