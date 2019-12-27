#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 50;

char adj[MAXN][MAXN];
bool visited[MAXN];

int num[MAXN];

int N;
int bfs(int idx) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int> > q;
	q.push({ idx,0 });
	visited[idx] = true;
	int ret = 0;
	while (!q.empty()) {
		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();
		if (depth == 2) break;
		for (int i = 0; i < N; i++) {
			if (cur == i) continue;
			if (adj[cur][i] == 'Y' && !visited[i]) {
				visited[i] = true;
				ret++;
				q.push({ i,depth + 1 });
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %1c", &adj[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans,bfs(i));
	}
	
	printf("%d\n", ans);
	return 0;
}
