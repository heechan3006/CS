#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#define MAXN 700
#define OFFSET 300
using namespace std;
bool visited[MAXN][MAXN];

struct info {
	int x;
	int y;
	int deact_time;
	int act_time;
};

int map[MAXN][MAXN];
int N, M, K;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
queue<info> q[11];
void init() {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			map[i][j] = 0;
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case= 1; test_case<= t; test_case++){
		init();
		scanf("%d%d%d", &N, &M, &K);
		for (int i = OFFSET; i < N+OFFSET; i++) {
			for (int j = OFFSET; j < M+OFFSET ; j++){
				int tmp;
				scanf("%d", &tmp);
				map[i][j] = tmp;
				if (map[i][j] > 0){
					q[tmp].push({i,j,tmp,tmp});

				}
			}
		}
		
		while (K--){
			for (int i = 10; i >= 1; i--) {
				int q_size = q[i].size();
				while (q_size--) {

					int x = q[i].front().x;
					int y = q[i].front().y;
					int deact_time = q[i].front().deact_time;
					int act_time = q[i].front().act_time;
				
					q[i].pop();
					// 비활성 대기
					if (deact_time > 0) {
						q[i].push({ x,y,deact_time - 1,act_time});
					}
					//비활성 -> 활성 후, 번식

					else if (deact_time == 0 && 0< act_time && act_time <= map[x][y] ) {
						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (map[nx][ny] != 0) continue;
							map[nx][ny] = map[x][y];
							q[i].push({ nx,ny,map[x][y] ,map[x][y]});
						}
						q[i].push({ x,y,deact_time,act_time - 1});
					}
					
				}
			}
		}
		int ans = 0;
		for (int i = 10; i >= 1; i--) {
			while (!q[i].empty()) {
				int act = q[i].front().act_time;
				int deact = q[i].front().deact_time;
				q[i].pop();
				if (act != 0 || deact != 0)	ans++;
				
			}
		}
		printf("#%d %d\n", test_case,ans);
	}
	return 0;
}