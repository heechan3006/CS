#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;

bool visited[1001];
vector<vector<int>> node(1001);
void dfs(int now) {
	visited[now] = true;
	for (auto it = node[now].begin(); it != node[now].end(); it++) {
		int next = (*it);
		if (visited[next]) continue;
		dfs(next);
	}
}
int main() {
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(node[i].begin(), node[i].end());
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		dfs(i);
		cnt++;
	}
	printf("%d\n", cnt);
}