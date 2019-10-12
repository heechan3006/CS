#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int adj[101][101];
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			adj[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[j][k]);
			}
		}
	}
	int ans = 0;
	for (int i = 2; i <= N; i++) {
		if (adj[1][i] != INF) ans++;
	}
	cout << ans << "\n";
	return 0;
}