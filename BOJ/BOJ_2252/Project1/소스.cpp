#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> order;
int N, M;

void dfs(int here) {
	visited[here] = true;
	for (int there = 0; there < adj[here].size(); there++) {
		if (!visited[adj[here][there]]) {
			dfs(adj[here][there]);
		}
	}
	order.push_back(here);
}
vector<int> topologycalSort() {
	visited = vector<bool>(N+1, false);
	order.clear();
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	reverse(order.begin(), order.end());
	return order;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	adj = vector<vector<int> >(N+1);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	vector<int> ans = topologycalSort();
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}