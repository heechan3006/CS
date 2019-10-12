#include <iostream>
#include <cstring>

int N;
int map[11][11];
int s[2][2];
int xy[12][2];
int visit[11];
int min;

void dfs(int prev, int next, int sum, int cnt) {
	if (sum >= min) {
		return;
	}
	if (cnt == N) {
		if (sum + map[prev][next] + abs(xy[next][0] - s[1][0]) + abs(xy[next][1] - s[1][1]) < min)
		{
			min = sum + map[prev][next] + abs(xy[next][0] - s[1][0]) + abs(xy[next][1] - s[1][1]);
			return;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(next, i, sum + map[prev][next], cnt + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<=t; test_case++){
		memset(map, 0, sizeof(map));
		memset(s, 0, sizeof(s));
		memset(xy, 0, sizeof(xy));
		memset(visit, 0, sizeof(visit));
		scanf("%d", &N);
		scanf("%d%d%d%d", &xy[0][0], &xy[0][1], &s[1][0], &s[1][1]);
		for (int i = 1; i <= N; i++) {
			scanf("%d%d", &xy[i][0], &xy[i][1]);
		}
		for (int i = 0; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				map[i][j] = abs(xy[i][0] - xy[j][0]) + abs(xy[i][1] - xy[j][1]);
				map[j][i] = map[i][j];
			}
		}
		min = 10e5;
		for (int i = 1; i <= N; i++) {
			visit[i] = 1;
			dfs(0, i, 0, 1);
			visit[i] = 0;
		}
		printf("#%d %d\n", test_case, min);
	}
	return 0;
}