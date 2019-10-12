#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define MAXN 1001
#define INF 1e9

using namespace std;

vector<pair<int, int> > adj[MAXN];
int dist[MAXN];
int path[MAXN];
int N,M;
int s, e;
vector<int> ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({ v,d });
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	
	cin >> s >> e;
	
	priority_queue<pair<int, int> > pq;
	pq.push({ 0,s });
	dist[s] = 0;
	while (!pq.empty()) {
		int now_dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		//if (now == e) break;
		if (dist[now] < now_dist) continue;
		for (int i = 0; i < adj[now].size(); i++) {
			int next_dist = adj[now][i].second + now_dist;
			int next = adj[now][i].first;
			if (dist[next] > next_dist) {
				dist[next] = next_dist;
				path[next] = now;
				pq.push({ -dist[next],next });
			}
		}
	}
	
	cout << dist[e] << "\n";
	while (e) {
		ans.push_back(e);
		e = path[e];
	}
	cout << ans.size() << "\n";
	for (int i = ans.size()-1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	return 0;
}
