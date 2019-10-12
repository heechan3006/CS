#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define MAXN 1001
using namespace std;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N, M;
int L, R;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1, };
int sx, sy;
struct node {
	int x;
	int y;
	int l_cnt;
	int r_cnt;
};
int main() {
	scanf("%d%d", &N, &M);
	scanf("%d%d", &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 2) {
				sx = i;
				sy = j;
				visited[i][j] = true;
				map[i][j] = 0;
			}
		}
	}
	queue<node> q;
	q.push({ sx,sy,0,0 });
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int l_cur = q.front().l_cnt;
		int r_cur = q.front().r_cnt;
		q.pop();
		for (int k = 0; k < 2; k++) {
			int nx = x;
			while (1) {
				nx += dx[k];
				if (nx < 0 || nx >= N || map[nx][y] == 1) break;
				if (!visited[nx][y]) {
					cnt++;
					visited[nx][y] = true;
					q.push({ nx,y,l_cur,r_cur });
				}
				
			}
		}
		for (int k = 2; k < 4; k++){
			
			int ny = y + dy[k];
			if (ny < 0||  ny >= M || map[x][ny] == 1) continue;
			if (k == 2 && r_cur < R && !visited[x][ny]) {
				visited[x][ny] = true;
				q.push({ x,ny,l_cur,r_cur + 1 });
				cnt++;
			}
			else if (k == 3 && l_cur < L && !visited[x][ny]) {
				visited[x][ny] = true;
				q.push({ x,ny,l_cur + 1,r_cur });
				cnt++;
			}
			
		}
	}
	
	printf("%d\n", cnt);
}