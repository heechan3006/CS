#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAXN 15
using namespace std;
struct node {
	int d;
	int y;
	int x;
};
int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
bool used[MAXN];
int N, M, D;
int num_of_enemy = 0;

int ans;
bool compare(node a, node b) {
	if (a.d <= b.d) {
		if (a.d == b.d) {
			if (a.y < b.y) return true;
			return false;
		}
		return true;
	}
	return false;
}
int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
int attack(vector<pair<int, int>>& bow) {
	vector<node> enemy[3];
	int res = 0;
	for (int k = 0; k < bow.size(); k++){
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_map[i][j] ) {
					int d = dist(bow[k].first, bow[k].second, i, j);
					if (d <= D){
						enemy[k].push_back({ d,j,i });
					}
				}
			}
		}
	}
	for (int i = 0; i < bow.size(); i++) {
		sort(enemy[i].begin(), enemy[i].end(), compare);
	}
	for (int i = 0; i < bow.size(); i++) {
		if (!enemy[i].size()) continue;
		if (copy_map[enemy[i][0].x][enemy[i][0].y]) res++;
		copy_map[enemy[i][0].x][enemy[i][0].y] = 0;
	}
	return res;
}
int move() {
	int tmp_cnt = 0;
	for (int j = 0; j < M; j++) {
		for (int i = N-1; i > 0; i--) {
			if (copy_map[i][j] == 1 && i == N - 1) {
				tmp_cnt++;
			}
			copy_map[i][j] = copy_map[i - 1][j];
		}
		copy_map[0][j] = 0;
	}
	return tmp_cnt;
}
void dfs(int now, int cnt) {
	if (cnt == 3) {
		vector<pair<int, int>> bow;
		for (int i = 0; i < M; i++) {
			if (used[i]) {
				bow.push_back({ N,i });
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		int tmp_cnt = num_of_enemy;
		int sum = 0;
		while (tmp_cnt > 0){
			int res = attack(bow);
			int res_1 = move();
			tmp_cnt = tmp_cnt-(res_1+res);
			sum += res;
		}
		if (ans < sum) ans = sum;
		return;
		
	}
	for (int i = now; i < M; i++) {
		if (!used[i]) {
			used[i] = true;
			dfs(i, cnt + 1);
			used[i] = false;
		}
	}

}
int main() {
	scanf("%d%d%d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) num_of_enemy++;
		}
	}
	ans = 0;
	dfs(0, 0);
	printf("%d", ans);
	return 0;
}
