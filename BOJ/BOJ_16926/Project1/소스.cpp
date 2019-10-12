#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 300

using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
int N, M, R;
void rotate(int t) {
	vector<int> v;
	vector<pair<int, int>> coord;
	for (int i = t; i < N - 1 - t; i++) {
		v.push_back(map[i][t]);
		coord.push_back({ i,t });
	}
	for (int j = t; j < M - 1 - t; j++) {
		v.push_back(map[t][j]);
		coord.push_back({ N - 1-t ,j });
	}
	
	for (int i = N - 1 - t; i > t; i--) {
		v.push_back(map[i][M - 1 - t]);
		coord.push_back({ i,M - 1 - t });
	}

	for (int j = M - 1 - t; j > t; j--) {
		v.push_back(map[t][j]);
		coord.push_back({ t,j });
	}
	for (int i = 0; i < v.size(); i++) {
		int x = coord[(i + R) % v.size()].first;
		int y = coord[(i + R) % v.size()].second;
		map[x][y] = v[i];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < min(N, M) / 2; i++) {
		rotate(i);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}