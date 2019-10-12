#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int map[1001][1001];
int dist[1001][1001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dist[i][j] = max(dist[i - 1][j], dist[i][j - 1]) + map[i][j];
		}
	}
	cout << dist[n][m] << '\n';
	return 0;
}