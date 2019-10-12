#include <iostream>
#include <cstring>
#include <vector>
#define MAX_N 37
using namespace std;
int info[MAX_N][MAX_N];
//bool visited[MAX_N][MAX_N];
int N, M;
int airport;
int ret_order[MAX_N];
struct Node {
	char loc;
	int time;
	int point;
};
int ret;
Node node[MAX_N];

void dfs(int now, int point, int time, int num, int order[MAX_N], bool visited[MAX_N], int day) {

	int next_idx = 0;
	int next_time = 10e6;
	int next_point = 0;
	for (int i = 1; i <= N; i++) {
		if (node[i].loc == 'P' && !visited[i]){
			next_time = time + info[now][i] + node[i].time;
			next_point = point + node[i].point;
			
			if (next_time > 540) continue;
			if (day == M) {
				int port_back_time = next_time + info[airport][i];
				if (port_back_time <= 540) {
					next_idx = i;
					order[num] = i;
					visited[i] = true;
					dfs(next_idx, next_point, next_time, num + 1, order, visited, day);
					visited[i] = false;
					order[num] = 0;
				}
			}
			else {
				next_idx = i;
				order[num] = i;
				visited[i] = true;
				dfs(next_idx, next_point, next_time, num + 1, order, visited, day);
				visited[i] = false;
				order[num] = 0;
			}
		}
	}

	if (next_idx == 0) {
		if (day == M) {
			if (time + info[airport][now] <= 540) {
				if (ret < point) {
					for (int i = 1; i <= N; i++) {
						ret_order[i] = order[i];
					}
					ret = point;
				}
			}
		}
		else {
			for (int i = 1; i <= N; i++) {
				if (node[i].loc == 'H') {
					if (time + info[now][i] <= 540) {
						order[num] = i;
						dfs(i, point, 0, num + 1, order, visited, day + 1);
						order[num] = 0;
					}
				}
			}
		}
	}
}
int main() {
	freopen("input (2).txt", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<=t; test_case++){
		scanf("%d %d", &N, &M);
		memset(info, 0, sizeof(info));
		memset(ret_order, 0, sizeof(ret_order));
		for (int i = 0; i < MAX_N; i++) {
			node[i].point = node[i].time = node[i].loc = 0;
		}
		//memset(visited, false, sizeof(visited));
	
		for (int i = 1; i <= N; i++) {
			for (int j = i+1; j <= N; j++) {
				scanf("%d", &info[i][j]);
				info[j][i] = info[i][j];
			}
		}
		char tmp_loc;
		int tmp_time;
		int tmp_score;
	
		for (int i = 1; i <= N; i++){
			cin >> tmp_loc;
			if (tmp_loc == 'P') {
				cin >> tmp_time >> tmp_score;
				node[i].loc = tmp_loc;
				node[i].time = tmp_time;
				node[i].point = tmp_score;
			}
			else {
				if (tmp_loc == 'A') {
					airport = i;
				}
				node[i].loc = tmp_loc;
			}
		}
		ret = 0;
		int order[MAX_N] = { 0, };
		bool visited[MAX_N] = { 0, };
		dfs(airport,0,0,1,order,visited,1);
		if (ret == 0) {
			printf("#%d %d \n", test_case,ret);
		}
		else {
			printf("#%d %d ",test_case, ret);
			for (int i = 1; i <= N; i++) {
				if (ret_order[i] == 0) continue;
				printf("%d ", ret_order[i]);
			}
			printf("%d\n", airport);
		}
	}
	return 0;
}