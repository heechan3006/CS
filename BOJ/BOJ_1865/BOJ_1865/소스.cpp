#include <iostream>
#include <vector>
#include <cstring>
#define INF 987654321
#define MAXV 505

using namespace std;

vector<pair<int, int>> graph[MAXV];
int dist[MAXV];
int N, M, W;
int S, E, T;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		for (int i = 0; i < MAXV; i++) {
			graph[i].clear();
			dist[i] = INF;
		}
		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			graph[S].push_back({ E,T });
			graph[E].push_back({ S,T });
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			graph[S].push_back({ E,-T });
		}
		dist[1] = 0;
		bool cycle = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < graph[j].size(); k++) {
					pair<int,int> node = graph[j][k];
					if (dist[j] != INF && dist[node.first] > dist[j] + node.second) {
						dist[node.first] = dist[j] + node.second;
						if (i == N) {
							cycle = true;
						}
					}
				}
			}
		}
		if (cycle) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}