#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> dist;
vector<vector<pair<int, int> > > adj;
vector<int> inorder;
vector<vector<int> > info;
vector<bool> visited;
int N, M;
int s, e;
int findMaxPath(int cur) {
	if (visited[cur]) return 0;
	visited[cur] = true;
	int ans = 0;
	for (int i = 0; i < info[cur].size(); i++) {
		ans += findMaxPath(info[cur][i]);
		ans++;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	inorder = vector<int>(N + 1,0);
	adj = vector < vector<pair<int, int> > >(N + 1);
	dist = vector<int>(N + 1, 0);
	info = vector<vector<int> >(N + 1);
	visited = vector<bool>(N + 1, false);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		inorder[v]++;
	}
	cin >> s >> e;
	queue<int> q;
	q.push(s);
	while (q.size()) {
		int here = q.front();
		q.pop();
		if (here == e) break;
		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i].first;
			int next_weight = adj[here][i].second;
			inorder[next]--;
			if (dist[next] < dist[here] + next_weight) {
				dist[next] = dist[here] + next_weight;
				info[next].clear();
				info[next].push_back(here);
			}
			else if (dist[next] == dist[here] + next_weight) {
				info[next].push_back(here);
			}
			if (inorder[next] == 0) {
				q.push(next);
			}
			
		}
	}
	cout << dist[e] << "\n";
	cout << findMaxPath(e) << "\n";
	return 0;
}