#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 15;
int adj[MAXN][MAXN];
int cache[1 << MAXN][MAXN][10];
int N;

int dp(int visited, int here, int cost, int cnt) {
	
	int& ret = cache[visited][here][cost];
	if (ret != 0) return ret;
	ret = cnt;
	for (int i = 0; i < N; i++) {
		if (visited & (1 << i) || adj[here][i] < cost) continue;
		ret = max(ret, dp(visited | (1 << i), i, adj[here][i], cnt + 1));
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %1d", &adj[i][j]);
		}
	}
	
	printf("%d\n",dp(1, 0, 0, 1));
	
	return 0;
}