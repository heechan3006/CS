#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int A[30];
int N, S;
int cnt = 0;
void dfs(int now, int sum) {
	if (sum+A[now] == S) {
		cnt++;
	}
	if (now == N - 1) return;
	dfs(now + 1, sum + A[now]);
	dfs(now + 1, sum);
}
int main() {
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	dfs(0, 0);
	printf("%d\n", cnt);
	return 0;
}