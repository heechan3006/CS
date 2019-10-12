#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 500 + 1
#define INF 987654321

using namespace std;
int dist[MAXN];
int N, M;
int S, D;

vector<pair<int, int>> graph[MAXN];
vector<pair<int, int>> trace[MAXN];
void bfs(int last) {
	queue<int> q;
	q.push(last);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < trace[here].size(); i++) {
			int next = trace[here][i].first;
			
			for (int j = 0; j < graph[next].size(); j++) {
				if (graph[next][j].first == here) {
					graph[next][j].second = -1;
				}
			}
			q.push(next);
		}
	}
	
}
int dijkstra(int start) {
	fill(dist, dist + N + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int next_cost = graph[here][i].second+cost;
			if (graph[here][i].second == -1) continue;
			if (dist[next] > next_cost) {
				trace[next].clear();
				dist[next] = next_cost;
				trace[next].push_back({ here,dist[next] });
				pq.push({ -dist[next],next });
			}
			else if (dist[next] == next_cost) {
				trace[next].push_back({ here,dist[next] });
			}
		}
	}
	return dist[D];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (1){
		cin >> N >> M ;
		if (N == 0 && M == 0) break;
		for (int i = 0; i < MAXN; i++) {
			graph[i].clear();
			trace[i].clear();
		}
		cin >> S >> D;
		for (int i = 0; i < M; i++) {
			int from, to, w;
			cin >> from >> to >> w;
			graph[from].push_back({ to,w });
		}
		dijkstra(S);
		bfs(D);
		int ans = dijkstra(S);
		if (ans == INF) cout << -1 << "\n";
		else cout << ans << "\n";
	}
	return 0;
}
