#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define INF 987654321
#define MAXV 100 + 1
using namespace std;

int N, S, D, M;
long long dist[MAXV];
int money[MAXV];
vector<pair<int, int>> graph[MAXV];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S >> D >> M;
	
	for (int i = 0; i < M; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		graph[from].push_back({ to,-w });
	}
	fill(dist, dist + N + 1, -INF);
	for (int i = 0; i < N; i++) {
		cin >> money[i];
	}
	dist[S] = money[S];
	bool flag = false;
	for (int i = 0; i < N+100; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < graph[j].size(); k++) {
				pair<int, int> node = graph[j][k];
				if (dist[j] != -INF && dist[node.first] < dist[j] + node.second + money[node.first]) {
					dist[node.first] = dist[j] + node.second + money[node.first];
					if (i >= N - 1) dist[node.first] = INF;
				}
				else if (dist[j] == INF) dist[node.first] = INF;
			}
		}
	}
	if (dist[D] == -INF) {
		cout << "gg\n";
	}
	else if (dist[D] == INF) cout << "Gee\n";
	else cout << dist[D] << "\n";
	
	return 0;
}

