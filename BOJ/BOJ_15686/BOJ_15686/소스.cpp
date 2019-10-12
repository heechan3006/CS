#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int map[50][50];
int copy_map[50][50];
int dist[50][50];
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<int> d(50);
vector<pair<int, int>> v;
vector<pair<int, int>> home;
int ans = 98765432;
int solve() {
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < d.size(); i++) {
		if (!d[i]) {
			copy_map[v[i].first][v[i].second] = 0;
		}
		else {
			q.push({ v[i].first,v[i].second });
			dist[v[i].first][v[i].second] = 0;
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx,ny });
		}
	}
	int sum = 0;
	for (int i = 0; i < home.size(); i++) {
		sum += dist[home[i].first][home[i].second];
	}
	return sum;
}
int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
			else if (map[i][j] == 1) {
				home.push_back({ i,j });
			}
		}
	}
	sort(v.begin(), v.end());
	d.resize(v.size());
	for (int i = 0; i < M; i++) {
		d[i] = 1;
	}
	sort(d.begin(), d.end());
	do {		
		int sum = solve();
		if (ans > sum) ans = sum;
	} while (next_permutation(d.begin(), d.end()));
	printf("%d\n", ans);
	return 0;
}