#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory.h>

#define MAX_N 100001

using namespace std;
int N;
bool visited[MAX_N];
vector<pair<int, int>> node[MAX_N];
int ans = 0;
int end_point = 0;
void dfs(int now, int weight) {
	if (visited[now]) return;
	visited[now] = true;
	if (ans < weight) {
		ans = weight;
		end_point = now;
	}
	for (int i = 0; i < node[now].size(); i++) {
		int next = node[now][i].first;
		int next_weight = node[now][i].second;
		dfs(next, weight + next_weight);
	}
}
int main() {
	scanf("%d", &N);
	int u, weight;
	int idx;
	for (int i = 1; i <= N; i++) {
		scanf("%d",&idx);
		while (1) {
			scanf("%d", &u);
			if (u == -1) break;
			scanf("%d", &weight);
			node[idx].push_back({ u,weight });
			node[u].push_back({ idx,weight });
		}
	}
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	ans = 0;
	dfs(end_point, 0);
	printf("%d\n", ans);
}