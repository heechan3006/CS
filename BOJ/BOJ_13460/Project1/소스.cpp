#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

char map[10][10];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool visited[10][10][10][10];
int N, M;
int rsx, rsy, bsx, bsy;
struct node {
	int rx;
	int ry;
	int bx;
	int by;
};
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'B') {
				bsx = i;
				bsy = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'R') {
				rsx = i;
				rsy = j;
				map[i][j] = '.';
			}
		}
	}
	queue<node> q;
	q.push({ rsx,rsy,bsx,bsy });
	visited[rsx][rsy][bsx][bsy] = true;
	int ans = 0;
	bool flag = false;
	while (!q.empty()&&!flag) {
		int q_size = q.size();
		while (q_size--){
			int rx = q.front().rx;
			int ry = q.front().ry;
			int bx = q.front().bx;
			int by = q.front().by;
			q.pop();
			if (map[rx][ry] == 'O' && map[bx][by] != 'O') {
				flag = true;
				break;
			}
			if (ans > 10) {
				ans = -1;
				flag = true;
				break;
			}
			for (int k = 0; k < 4; k++) {
				int nrx = rx;
				int nry = ry;
				int nbx = bx;
				int nby = by;
				
				while (map[nrx + dx[k]][nry + dy[k]] != '#' && map[nrx][nry] != 'O') {
					nrx += dx[k];
					nry += dy[k];
				}
				while (map[nbx + dx[k]][nby + dy[k]] != '#' && map[nbx][nby] != 'O') {
					nbx += dx[k];
					nby += dy[k];
				}
				if (nrx == nbx && nry == nby) {
					if (map[nrx][nry] == 'O') continue;
					if (abs(nrx - rx) + abs(nry - ry) < abs(nbx - bx) + abs(nby - by)) {
						nbx -= dx[k];
						nby -= dy[k];
					}
					else {
						nrx -= dx[k];
						nry -= dy[k];
					}
				}
			
				if (visited[nrx][nry][nbx][nby]) continue;
				visited[nrx][nry][nbx][nby] = true;
				q.push({ nrx,nry,nbx,nby });
			}
		}
		ans++;
	}
	ans--;
	if (flag && ans <= 10) cout << ans << "\n";
	else cout << -1 << "\n";
	return 0;
}