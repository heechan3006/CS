#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 801
#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[MAXN];
int dist[MAXN];
int N, E;
int D1, D2;
int dijkstra(int start,int finish) {
	fill(dist, dist + N + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cur_cost = -pq.top().first;
		int cur = pq.top().second;		
		pq.pop();
		if (dist[cur] < cur_cost) continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cur_cost;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ -dist[next],next });
			}
		}
	}
	return dist[finish];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		graph[from].push_back({ to,w });
		graph[to].push_back({ from,w });
	}
	
	cin >> D1 >> D2;
	
	int path1 = dijkstra(1, D1) + dijkstra(D1, D2) + dijkstra(D2, N);
	int path2 = dijkstra(1, D2) + dijkstra(D2, D1) + dijkstra(D1, N);
	
	if (path1 < path2 && path1 < INF) {
		cout << path1 << "\n";
	}
	else if (path1 > path2 && path2 < INF) {
		cout << path2 << "\n";
	}
	else cout << -1 << "\n";
	
	return 0;
}