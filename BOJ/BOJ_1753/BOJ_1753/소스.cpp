#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define INF 987654321
#define MAXV 20000+1

using namespace std;
int V, E,start;
vector<pair<int, int>> graph[MAXV];
int dist[MAXV];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	cin >> start;
	
	for (int i = 0; i < E; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		graph[from].push_back({ to,w });
	}
	fill(dist, dist + V + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty()) {
		// 최소값을 가지고 있는 here노드
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int next_cost = graph[here][i].second;
			if (dist[next] > dist[here] + next_cost) {
				dist[next] = dist[here] + next_cost;
				pq.push({ -dist[next],next });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
			continue;
		}
		else{
			cout << dist[i] << "\n";
		}
	}
	return 0;
}