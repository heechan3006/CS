#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAXV 100 + 1

using namespace std;

vector<pair<int, int>> graph[MAXV];
//int D[MAXV][MAXV];
int N, M;
vector<int> dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	vector<int> D(N + 1,INF);
	D[start] = 0;
	while (!pq.empty()) {
		int cur_cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second+cur_cost;
			if (D[next] > next_cost) {
				D[next] = next_cost;
				pq.push({ -next_cost,next });
			}
		}
	}
	return D;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		graph[from].push_back({ to,w });
	}
	for (int i = 1; i <= N; i++){
		vector<int> dist = dijkstra(i);
		for (int j = 1; j < dist.size(); j++) {
			if (dist[j] == INF) cout << 0 << " ";
			else cout << dist[j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
