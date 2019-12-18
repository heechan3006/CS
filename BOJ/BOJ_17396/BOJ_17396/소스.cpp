#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
const int MAXN = 100000;
const long long INF = 1e18;
using namespace std;

long long dist[MAXN];
int is_possible[MAXN];
bool visited[MAXN];
priority_queue<pair<long long,int> > pq;
int N, M;
vector<pair<int, int> > adj[MAXN];

void dijkstra() {
	for (int i = 0; i < N; i++) {
		dist[i] = INF;
	}
	pq.push({ 0,0 });
	dist[0] = 0;
	while (!pq.empty()) {
		long long cur_w = -pq.top().first;
		int cur = pq.top().second;
		
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			long long next_w = adj[cur][i].second + cur_w;
			if (dist[next] > next_w) {
				dist[next] = next_w;
				pq.push({ -dist[next],next });
			}
		}
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> is_possible[i];
	}
	is_possible[N - 1] = 0;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (is_possible[u] || is_possible[v]) continue;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}
	dijkstra();
	if (dist[N - 1] == INF) cout << "-1\n";
	else {
		cout << dist[N-1] << "\n";
	}
	
	return 0;
}

