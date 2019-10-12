#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAXV 100 + 1

using namespace std;

vector<vector<int>> graph;
//int D[MAXV][MAXV];
int N, M;
vector<int> dijkstra(int start) {
	vector<bool> visited(N + 1, false);
	vector<int> D(N + 1, INF);
	D[start] = 0;

	while (1) {
		int m = INF, node = -1;

		for (int j = 1; j <= N; j++) {
			if (!visited[j] && (m > D[j])) {
				m = D[j];
				node = j;
			}
		}
		if (m == INF) break;
		visited[node] = true;
		for (int j = 1; j <= N; j++) {
			if (visited[j]) continue;
			int via = D[node] + graph[node][j];
			if (D[j] > via) {
				D[j] = via;
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
	graph.assign(N+1, vector<int>(N+1, INF));
	for (int i = 0; i < M; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		if (graph[from][to] == 0) {
			graph[from][to] = w;
		}
		else {
			graph[from][to] = min(graph[from][to], w);
		}
	}
	for (int i = 1; i <= N; i++) {
		vector<int> dist = dijkstra(i);
		for (int j = 1; j < dist.size(); j++) {
			if (dist[j] == INF) cout << 0 << " ";
			else cout << dist[j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
