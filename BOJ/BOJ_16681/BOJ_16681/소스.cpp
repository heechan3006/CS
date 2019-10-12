#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAXN 100000 + 1
#define INF 1e12
#define ll long long
using namespace std;

ll dist[2][MAXN];
int height[MAXN];
int N, M, D, E;
vector<pair<int, int> > adj[MAXN];
void dijkstra(int mode) {
	priority_queue<pair<ll, int> > pq;
	if (mode == 0) {
		dist[0][1] = 0;
		pq.push({ 0,1 });
	}
	else {
		dist[1][N] = 0;
		pq.push({ 0,N });
	}
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[mode][now] < cost) continue;
		for (int i = 0; i < adj[now].size(); i++) {
			ll next_cost = cost + (ll)adj[now][i].second;
			int next = adj[now][i].first;
			if (dist[mode][next] > next_cost && height[next] > height[now]) {
				dist[mode][next] = next_cost;
				pq.push({ -dist[mode][next],next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> D >> E;
	for (int i = 1; i <= N; i++) {
		cin >> height[i];
		dist[0][i] = dist[1][i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({ v,d });
		adj[v].push_back({ u,d });
	}
	dijkstra(0);
	dijkstra(1);
	ll ans = -INF;
	for (int i = 2; i < N; i++) {
		if (dist[0][i] != INF && dist[1][i] != INF) {
			ans = max(ans,height[i] * E - D * (dist[0][i] + dist[1][i]));
		}	
	}
	if (ans == -INF) cout << "Impossible\n";
	else {
		cout << ans << "\n";
	}
	
	return 0;
}