#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> cost;

int N, K;
int target;


int minimumTime(int w) {
	
	if (visited[w]) return cost[w];
	visited[w] = true;
	int res = 0;
	for (int i = 0; i < adj[w].size(); i++) {

		res = max(res, minimumTime(adj[w][i]));
	}
	return cost[w] += res;
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
		visited = vector<bool>(N, false);
		for (int i = 0; i < N; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < K; i++) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			adj[v].push_back(u);
		}
		cin >> target;
		target--;
		
		cout << minimumTime(target) << "\n";
	}

	return 0;
}