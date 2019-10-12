#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

int map[10][10];
int N;
bool used[10][10];
int ans;
void dfs(int x, int y, int cnt) {
	if (cnt == 3) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (used[i][j]) sum += map[i][j];
			}
		}
		if (ans > sum) ans = sum;
		return;
	}
	for (int i = x; i < N-1; i++) {
		for (int j = 1 ; j < N - 1; j++) {
			if (i - 1 < 0 || j - 1 < 0 || i + 1 >= N || j + 1 >= N) continue;
			if (used[i - 1][j] || used[i][j - 1] || used[i][j + 1] || used[i + 1][j] || used[i][j]) continue;
			used[i - 1][j] = used[i][j - 1] = used[i][j + 1] = used[i + 1][j] = used[i][j] = true;
			dfs(i, j, cnt + 1);
			used[i - 1][j] = used[i][j - 1] = used[i][j + 1] = used[i + 1][j] = used[i][j] = false;
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
	ans = INF;
	dfs(1, 1, 0);
	cout << ans << "\n";
	return 0;
}