#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAXN 1001
#define INF 987654321
using namespace std;
struct node {
	int num_2;
	int num_5;
	node() {};
	node(int _num_2, int _num_5) {
		num_2 = _num_2;
		num_5 = _num_5;
	}
} ;
node map[MAXN][MAXN];
node dist[MAXN][MAXN];

int N;


node dfs(int x, int y) {
	if (x < 1 || y < 1 || x > N || y > N) {
		return node(INF + 1, INF + 1);
	}
	if (map[x][y].num_2 == INF) {
		return node(INF + 1, INF + 1);
	}
	node &ans = dist[x][y];
	if (ans.num_2 != INF && ans.num_5 != INF) {
		return ans;
	}
	node l1 = dfs(x - 1, y);
	node l2 = dfs(x, y - 1);
	// 5 개수가 2 개수보다 적을수록 유리
	int l1_num_2 = map[x][y].num_2 + l1.num_2;
	int l1_num_5 = map[x][y].num_5 + l1.num_5;
	int l2_num_2 = map[x][y].num_2 + l2.num_2;
	int l2_num_5 = map[x][y].num_5 + l2.num_5;
	
	int min_l1, min_l2;
	if (l1_num_2 > l1_num_5) {
		min_l1 = l1_num_5;
	}
	else min_l1 = l1_num_2;
	if (l2_num_2 > l2_num_5) {
		min_l2 = l2_num_5;
	}
	else min_l2 = l2_num_2;
	if (min_l1 > min_l2) {
		ans.num_2 = l2_num_2;
		ans.num_5 = l2_num_5;
	}
	else {
		ans.num_2 = l1_num_2;
		ans.num_5 = l1_num_5;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<=t; test_case++){
		
		scanf("%d", &N);
		int tmp;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &tmp);
				if (tmp == 0) {
					map[i][j] = node(INF, INF);
					continue;
				}
				int num_5 = 0;
				while (tmp % 5 == 0) {
					num_5++;
					tmp /= 5;
				}
				int num_2 = 0;
				while (tmp % 2 == 0) {
					num_2++;
					tmp /= 2;
				}
				map[i][j] = node(num_2, num_5);
			}
		}
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				dist[i][j].num_2 = INF;
				dist[i][j].num_5 = INF;
			}
		}
		dist[1][1] = map[1][1];
		node ans = dfs(N, N);
		printf("#%d ", test_case);
		if (ans.num_2 > ans.num_5) {
			printf("%d\n", ans.num_5);
		}
		else {
			printf("%d\n", ans.num_2);
		}
	}
	return 0;
}
