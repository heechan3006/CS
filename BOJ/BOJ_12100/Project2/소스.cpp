#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int map[20][20];
int copy_map[20][20];
int dirs[5];
int N;
int ans;
// 0 : 위 , 1 : 아래, 2 : 왼쪽, 3 : 오른쪽
void simulate(int dir) {
	
	if (dir == 0) {
		for (int j = 0; j < N; j++) {
			queue<int> q;
			for (int i = 0; i < N; i++) {
				if (copy_map[i][j]){
					q.push(copy_map[i][j]);
				}
				copy_map[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				if (copy_map[idx][j] == 0) {
					copy_map[idx][j] = now;
				}
				else if (copy_map[idx][j] == now) {
					copy_map[idx][j] *= 2;
					idx++;
				}
				else {
					copy_map[idx + 1][j] = now;
					idx++;
				}
				
			}
		}
	}
	else if (dir == 1) {
		for (int j = 0; j < N; j++) {
			queue<int> q;
			for (int i = N-1; i >= 0; i--) {
				if (copy_map[i][j]) {
					q.push(copy_map[i][j]);
				}
				copy_map[i][j] = 0;
			}
			int idx = N-1;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				if (copy_map[idx][j] == 0) {
					copy_map[idx][j] = now;
				}
				else if (copy_map[idx][j] == now) {
					copy_map[idx][j] *= 2;
					idx--;
				}
				else {
					copy_map[idx - 1][j] = now;
					idx--;
				}

			}
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < N; i++) {
			queue<int> q;
			for (int j = 0; j < N; j++) {
				if (copy_map[i][j]) {
					q.push(copy_map[i][j]);
				}
				copy_map[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				if (copy_map[i][idx] == 0) {
					copy_map[i][idx] = now;
				}
				else if (copy_map[i][idx] == now) {
					copy_map[i][idx] *= 2;
					idx++;
				}
				else {
					copy_map[i][idx+1] = now;
					idx++;
				}

			}
		}
	}
	else if (dir == 3) {
		for (int i = 0; i < N; i++) {
			queue<int> q;
			for (int j = N - 1; j >= 0; j--) {
				if (copy_map[i][j]) {
					q.push(copy_map[i][j]);
				}
				copy_map[i][j] = 0;
			}
			int idx = N - 1;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				if (copy_map[i][idx] == 0) {
					copy_map[i][idx] = now;
				}
				else if (copy_map[i][idx] == now) {
					copy_map[i][idx] *= 2;
					idx--;
				}
				else {
					copy_map[i][idx-1] = now;
					idx--;
				}

			}
		}
	}
}
void dfs(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < 5; i++) {
			simulate(dirs[i]);
		}
		int max_v = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				max_v = max(max_v, copy_map[i][j]);
			}
		}
		if (ans < max_v) ans = max_v;
		return;
	}
	for (int i = 0; i < 4; i++) {
		dirs[cnt] = i;
		dfs(cnt + 1);
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
	ans = 0;
	dfs(0);
	cout << ans << "\n";
	return 0;
}