#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


int map[20][20];
bool visited[20][20][20][20];
int N, M, C;
int ans;
int get_honey(int x, int y) {
	int end_idx = (1 << M);
	int res = 0;
	for (int i = 1; i < end_idx; i++) {
		int sum_sq = 0;
		int sum = 0;
		for (int j = 0; j < M; j++) {
			if ((1 << j) & i) {
				sum_sq += map[x][y + M - 1 - j]* map[x][y + M - 1 - j];
				sum += map[x][y + M - 1 - j];
			}
		}
		if (res < sum_sq && sum <=C) res = sum_sq;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		memset(visited, false, sizeof(visited));
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		ans = 0;
		for (int x1 = 0; x1 < N; x1++) {
			for (int y1 = 0; y1 + M <= N; y1++) {
				for (int x2 = x1; x2 < N; x2++) {
					for (int y2 = 0; y2 + M <= N; y2++) {
						if (x1 == x2 && y2 <= y1 + M-1) continue;
						if (visited[x1][y1][x2][y2]) continue;
						visited[x1][y1][x2][y2] = true;
						visited[x2][y2][x1][y1] = true;
						int honey_1 = get_honey(x1, y1);
						int honey_2 = get_honey(x2, y2);
						if (ans < honey_1 + honey_2) ans = honey_1 + honey_2;
					}
				}
			}
		}
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	return 0;
}