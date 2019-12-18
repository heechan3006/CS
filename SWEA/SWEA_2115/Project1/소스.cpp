#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAXN 10

using namespace std;

int N, M, C;
int map[MAXN][MAXN];
int max_v,tmp;
void dfs(int x, int y, int end_y,int sum,int total_sum) {
	if (sum > C) return;
	if (sum == C) {
		tmp = total_sum;
		return;
	}
	if (total_sum> tmp) tmp = total_sum;
	for (int i = y; i < end_y; i++) {
		dfs(x, i + 1, end_y, sum+map[x][i],total_sum + map[x][i] * map[x][i]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				tmp = 0;
				dfs(i, j, j + M, 0,0);
				max_v = tmp;
				for (int ii = i; ii < N; ii++) {
					for (int jj = 0; jj <= N - M; jj++) {
						if (i == ii && jj < j + M) continue;
						
						tmp = 0;
						dfs(ii, jj, jj + M,0, 0);
						if (ans < max_v+tmp) ans = max_v+tmp;
					}
				}
			}
		}
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	
	return 0;
}