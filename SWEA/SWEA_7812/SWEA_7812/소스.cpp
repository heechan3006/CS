#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAXN 10000
using namespace std;

int map[MAXN];
bool visited[MAXN];

int N, M;
int ans = 0;
void dfs(int idx, int cnt) {
	if (idx >= N) return;
	if (cnt > M) return;
	else if (cnt == M) {
		ans++;
		return;
	}
	dfs(idx + 1, cnt + map[idx+1]);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case<=t; test_case++){
		ans = 0;
		memset(map, 0, sizeof(map));
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%d", &map[i]);
		}
		for (int i = 0 ; i< N; i++){
			dfs(i,map[i]);
		}
		printf("#%d %d\n", test_case,ans);
	}
	return 0;
}