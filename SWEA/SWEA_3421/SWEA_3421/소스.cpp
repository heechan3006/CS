#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, M;
int no[21];
bool check[21];
int cnt;
void dfs(int idx, int info) {
	if (idx == N) {
		cnt++;
		return;
	}
	if (!(no[idx] & info)) dfs(idx + 1, info | (1 << idx));
	dfs(idx + 1, info);
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case <= t; test_case++){
		scanf("%d %d", &N, &M);
	
		cnt = 0;
		for (int i = 0; i < N; i++) no[i] = 0;
		for (int i = 0; i < M; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			u--;
			v--;
			no[u] |= (1 << v);
			no[v] |= (1 << u);
		}
		dfs(0, 0);

		printf("%d\n", cnt);
	}
	return 0;
}