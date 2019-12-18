#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int map[13][20];
int copy_map[13][20];
int num[13];
bool used[13];
int ans;
bool flag;
int N, M, K;
bool check() {
	for (int j = 0; j < M; j++) {
		int i = 0;
		int tmp = copy_map[i][j];
		int tmp_cnt = 0;

		while (i < N) {
			if (tmp_cnt >= K) break;
			if (tmp == copy_map[i++][j]) tmp_cnt++;
			else tmp_cnt = 0, i--,tmp = copy_map[i][j];
		}
		if (tmp_cnt < K) return false;
	}
	return true;
}
void dfs(int now, int cnt) {
	if (ans <= cnt || cnt>K) return;
	if (ans == 0) return;
	if (now == N) {
		memcpy(copy_map, map, sizeof(map));
		for (int i = 0; i < N; i++) {
			if (!num[i]) continue;
			for (int j = 0; j < M; j++) {
				copy_map[i][j] = num[i];
			}
		}
		if (check()) {
			if (ans > cnt) ans = cnt;
		}
		return;
	}
	
	num[now] = 0;
	dfs(now + 1, cnt);
	num[now] = 1;
	dfs(now + 1, cnt + 1);
	num[now] = 2;
	dfs(now + 1, cnt + 1);
	num[now] = 0;
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		cin >> N >> M >> K;
		ans = N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				map[i][j]++;
			}
		}

		dfs(0, 0);
		
		cout << "#"<<test_case<<" "<<ans << "\n";
		
	}
	return 0;
}