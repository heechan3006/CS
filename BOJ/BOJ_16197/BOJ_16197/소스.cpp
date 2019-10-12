#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 20
using namespace std;

char map[MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN][MAXN];
int N, M;
struct node {
	int x;
	int y;
};
node coin_1;
node coin_2;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool is_range(node c) {
	return (c.x >= 0 && c.y >= 0 && c.x < N && c.y < M);
}
int bfs() {
	queue<pair<node, node> > q;
	visited[coin_1.x][coin_1.y][coin_2.x][coin_2.y] = true;
	q.push({ coin_1,coin_2 });
	int time = 0;
	while (!q.empty()) {
		int q_size = q.size();
		time++;
		if (time > 10) break;
		while (q_size--) {
			node c1 = q.front().first;
			node c2 = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				node c1_n;
				node c2_n;
				c1_n.x = c1.x + dx[k];
				c1_n.y = c1.y + dy[k];
				c2_n.x = c2.x + dx[k];
				c2_n.y = c2.y + dy[k];
				if (!is_range(c1_n) && !is_range(c2_n)) continue;
				else if (is_range(c1_n) && is_range(c2_n)) {
					if (map[c1_n.x][c1_n.y] == '#') {
						c1_n.x -= dx[k];
						c1_n.y -= dy[k];
					}
					if (map[c2_n.x][c2_n.y] == '#') {
						c2_n.x -= dx[k];
						c2_n.y -= dy[k];
					}
					if (!visited[c1_n.x][c1_n.y][c2_n.x][c2_n.y]) {
						visited[c1_n.x][c1_n.y][c2_n.x][c2_n.y] = true;
						q.push({ c1_n,c2_n });
					}
				}
				else if (!is_range(c1_n) || !is_range(c2_n)) {
					return time;
				}
			}
		}
	}
	return -1;
}
int main() {
	
	scanf("%d%d", &N, &M);
	coin_1.x = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'o') {
				if (coin_1.x == -1) {
					coin_1.x = i;
					coin_1.y = j;
				}
				else {
					coin_2.x = i;
					coin_2.y = j;
				}
			}		
		}
	}
	printf("%d\n",bfs());
	return 0;
}