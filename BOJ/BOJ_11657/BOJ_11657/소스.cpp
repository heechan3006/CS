#include <iostream>
#include <vector>
#define MAXV 501
#define INF 987654321
using namespace std;


int dist[MAXV];
int N, M, A, B, C;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	vector<pair<int, int>> v[MAXV];
	
	for (int i = 0; i < MAXV; i++) {
		dist[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
		
	}
	dist[1] = 0;
	bool cycle = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < v[j].size(); k++){
				if (dist[j] != INF && dist[v[j][k].first]> v[j][k].second+dist[j]) {
					
					dist[v[j][k].first] = dist[j] + v[j][k].second;
					if (i == N) cycle = true;
				}
			}
		}
	}
	if (cycle) cout << -1 << "\n";
	else{
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) cout << -1 << "\n";
			else cout << dist[i] << "\n";
		}
	}
	return 0;
}
