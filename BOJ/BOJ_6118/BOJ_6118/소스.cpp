#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> ans;
int N, M;
void bfs() {
	queue<pair<int, int> > q;
	q.push({ 0,0 });
	visited[0] = true;
	int max_dist = 0;
	while (!q.empty()) {
		int here = q.front().first;
		int depth = q.front().second;
		q.pop();
		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			if (visited[next]) continue;
			visited[next] = true;
			if (max_dist < depth + 1) {
				max_dist = depth + 1;
				ans.clear();
				ans.push_back(next);
			}
			else if (max_dist == depth + 1) {
				ans.push_back(next);
			}
			q.push({ next,depth + 1 });
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d %d %d", ans[0]+1, max_dist, ans.size());

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
	bfs();
	return 0;
}
