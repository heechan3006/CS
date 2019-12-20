#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<vector<int> > outadj;
vector<bool> visited;
vector<int> cost;
vector<int> dist;
vector<int> order;

int N, K;
int target;

void dfs(int here) {
	visited[here] = true;
	for (int there = 0; there < adj[here].size(); there++) {
		int next = adj[here][there];
		if (!visited[next]) {
			dfs(next);
		}
	}
	order.push_back(here);
}
int get_ans() {
	
	for (int i = 0; i < order.size(); i++) {
		int here = order[i];
		dist[here] = cost[here];
		for (int j = 0; j < outadj[here].size(); j++) {
			int next = outadj[here][j];
			if (dist[here] < dist[next] + cost[here]) {
				dist[here] = dist[next] + cost[here];
			}
		}
		if (here == target) break;
	}
	return dist[target];
}
void topologicalSort() {
	order.clear();
	visited = vector<bool>(N, false);
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dist[i] = cost[i];
			dfs(i);
		}
	}
	reverse(order.begin(), order.end());
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> N >> K;
		cost = vector<int>(N, 0);
		adj = vector<vector<int> >(N);
		outadj = vector<vector<int> >(N);
		dist = vector<int>(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < K; i++) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			adj[u].push_back(v);
			outadj[v].push_back(u);
		}
		cin >> target;
		target--;
		topologicalSort();
		
		cout << get_ans() << "\n";
	}
	
	return 0;
}