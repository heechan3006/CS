#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adj;
int N, M;
vector <bool> visited;

int bfs() {
	int ans = 0;
	queue<pair<int, int> > q;
	q.push({ 0, 0 });
	visited[0] = true;
	while (!q.empty()) {
		int here = q.front().first;
		int depth = q.front().second;
		if (depth == 1 || depth == 2) ans++;
		q.pop();
		if (depth > 2) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			if (visited[there]) continue;
			visited[there] = true;
			q.push({ there,depth + 1 });
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	adj = vector<vector<int> >(N);
	visited = vector<bool>(N, false);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	cout << bfs() << "\n";
	return 0;

}