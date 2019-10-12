#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAXN 500001
using namespace std;

int dist[2][MAXN];
int N, K;

int main() {
	scanf("%d%d", &N, &K);
	fill(&dist[0][0], &dist[0][MAXN], -1);
	fill(&dist[1][0], &dist[1][MAXN], -1);
	queue<pair<int, int>> q;
	q.push({ 0,N });
	dist[0][N] = 0;
	while (!q.empty()) {
		int cur = q.front().first;
		int cur_idx = q.front().second;
		q.pop();
		int arr[] = { cur_idx - 1, cur_idx + 1, cur_idx * 2 };
		for (int k = 0; k < 3; k++) {
			int next_idx = arr[k];
			if (next_idx < 0 || next_idx > MAXN - 1) continue;
			if (dist[1 - cur][next_idx] != -1) continue;
			dist[1 - cur][next_idx] = dist[cur][cur_idx] + 1;
			q.push({ 1 - cur,next_idx });
		}
	}
	int cnt = 0;
	int ans = 98765432;
	while (K <= MAXN - 1) {
		if (dist[cnt % 2][K] != -1 && dist[cnt % 2][K] <= cnt) ans = min(ans, cnt);
		cnt++;
		K += cnt;
	}
	if (ans == 98765432) printf("-1\n");
	else {
		printf("%d\n", ans);
	}
}
