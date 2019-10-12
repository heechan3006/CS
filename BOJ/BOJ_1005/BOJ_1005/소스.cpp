#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 1000 + 1
using namespace std;

int N, M;

int cost[MAXN];
int deg[MAXN];
int dist[MAXN];
int W;
vector<int> graph[MAXN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		memset(deg, 0, sizeof(deg));
		memset(dist, 0, sizeof(dist));
		memset(cost, 0, sizeof(cost));
		for (int i = 0; i < MAXN; i++) {
			graph[i].clear();
		}
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			deg[v]++;
		}
		cin >> W;
		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (deg[i] == 0) {
				q.push(i);
				dist[i] = cost[i];
			}
		}
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur == W) break;
			for (int j = 0; j < graph[cur].size(); j++) {
				int next = graph[cur][j];
				deg[next]--;
				if (deg[next] == 0) {
					q.push(next);
				}
				if (dist[next] < dist[cur]+cost[next]) {
					dist[next] = dist[cur] + cost[next];
				}
			}
		}
		cout << dist[W] << "\n";
	}
	return 0;
}

