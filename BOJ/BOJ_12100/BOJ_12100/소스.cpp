#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N;
int map[20][20];
int copy_map[20][20];
bool check[20][20];
int ans;
void shift(int dir) {
	queue<int> q;
	if (dir == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (map[i][j]) {
					q.push(map[i][j]);
				}
				map[i][j] = 0;
			}
			int idx = N - 1;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				if (map[i][idx] == 0) {
					map[i][idx] = data;
				}
				else if (map[i][idx] == data) {
					map[i][idx] *= 2;
					idx--;
				}
				else {
					idx--;
					map[i][idx] = data;
				}
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j]) {
					q.push(map[i][j]);
				}
				map[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				if (map[i][idx] == 0) {
					map[i][idx] = data;
				}
				else if (map[i][idx] == data) {
					map[i][idx] *= 2;
					idx++;
				}
				else {
					idx++;
					map[i][idx] = data;
				}
			}
		}
	}
	else if (dir == 2) {
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (map[i][j]) {
					q.push(map[i][j]);
				}
				map[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				if (map[idx][j] == 0) {
					map[idx][j] = data;
				}
				else if (map[idx][j] == data) {
					map[idx][j] *= 2;
					idx++;
				}
				else {
					idx++;
					map[idx][j] = data;
				}
			}
		}
		
	}
	else if (dir == 3) {
		for (int j = 0; j < N; j++) {
			for (int i = N - 1; i >= 0; i--) {
				if (map[i][j]) {
					q.push(map[i][j]);
				}
				map[i][j] = 0;
			}
			int idx = N-1;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				if (map[idx][j] == 0) {
					map[idx][j] = data;
				}
				else if (map[idx][j] == data) {
					map[idx][j] *= 2;
					idx--;
				}
				else {
					idx--;
					map[idx][j] = data;
				}
			}
		}
	}
}

void dfs(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (ans < map[i][j]) ans = map[i][j];
			}
		}
		
		return;
	}
	int copy_map[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		shift(i);
		dfs(cnt+1);
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
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	ans = 0;
	dfs(0);
	cout << ans << "\n";
}