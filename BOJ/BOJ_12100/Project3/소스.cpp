#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 20
using namespace std;

int map[MAXN][MAXN];

int N;
int ans = 0;
void move(int mode) {
	// right
	if (mode == 0) {
		for (int i = 0; i < N; i++) {
			queue<int> q;
			for (int j = N - 1; j >= 0; j--) {
				if (map[i][j] == 0) continue;
				q.push(map[i][j]);
				map[i][j] = 0;
			}
			int idx = N - 1;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				if (map[i][idx] == 0) {
					map[i][idx] = now;
				}
				else if (map[i][idx] == now) {
					map[i][idx] *= 2;
					idx--;
				}
				else {
					map[i][idx - 1] = now;
					idx--;
				}
			}
		}
	}
	// left
	else if (mode == 1) {
		for (int i = 0; i < N; i++) {
			queue<int> q;
			for (int j = 0; j <  N; j++) {
				if (map[i][j] == 0) continue;
				q.push(map[i][j]);
				map[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				if (map[i][idx] == 0) {
					map[i][idx] = now;
				}
				else if (map[i][idx] == now) {
					map[i][idx] *= 2;
					idx++;
				}
				else {
					map[i][idx + 1] = now;
					idx++;
				}
				
			}
		}
	}
	// up
	else if (mode == 2) {
		for (int j = 0; j < N; j++) {
			queue<int> q;
			for (int i = 0; i < N; i++) {
				if (map[i][j] == 0) continue;
				q.push(map[i][j]);
				map[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				if (map[idx][j] == 0) {
					map[idx][j] = now;
				}
				else if (map[idx][j] == now) {
					map[idx][j] *= 2;
					idx++;
				}
				else {
					map[idx+1][j] = now;
					idx++;
				}
			}
		}
	}
	// down
	else if (mode == 3) {
		for (int j = 0; j < N; j++) {
			queue<int> q;
			for (int i = N-1; i >= 0; i--) {
				if (map[i][j] == 0) continue;
				q.push(map[i][j]);
				map[i][j] = 0;
			}
			int idx = N-1;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				if (map[idx][j] == 0) {
					map[idx][j] = now;
				}
				else if (map[idx][j] == now) {
					map[idx][j] *= 2;
					idx--;
				}
				else {
					map[idx-1][j] = now;
					idx--;
				}
			}
		}
	}
}
void dfs(int now) {
	if (now == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > ans) ans = map[i][j];
			}
		}
		return;
	}
	int copy_map[MAXN][MAXN];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		move(i);
		dfs(now + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = copy_map[i][j];
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0);
	cout << ans << "\n";
	return 0;
}