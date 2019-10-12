#include <iostream>

using namespace std;

int n;
int map[101][101];
long long dist[101][101];

int cnt;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	dist[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) continue;
			if (i+map[i][j] < n) dist[i + map[i][j]][j] += dist[i][j];
			if (j+map[i][j] < n) dist[i][j + map[i][j]] += dist[i][j];
		}
	}
	
	cout << dist[n-1][n-1]<< '\n';
	return 0;
}