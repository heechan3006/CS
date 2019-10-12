#include <iostream>
#include <cstring>
#define MAXN 1000

using namespace std;
int sx, sy;
int R, C;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int K;
int dir[4] = { 0, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int tmp_x, tmp_y;
		cin >> tmp_x >> tmp_y;
		map[tmp_x][tmp_y] = 1;
	}
	cin >> sx >> sy;
	
	visited[sx][sy] = true;
	for (int i = 0; i < 4; i++) {
		int order;
		cin >> order;
		order--;
		dir[i] = order;
	}
	bool flag = false;
	int order = 0;
	int nx = sx;
	int ny = sy;
	int cnt = 0;
	while (cnt != 4) {
		
		nx = sx+dx[dir[order]];
		ny = sy+dy[dir[order]];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny] || map[nx][ny]) {
			order = (order + 1) % 4;
			cnt++;
			continue;
			
		}
		
		visited[nx][ny] = true;
		sx = nx;
		sy = ny;
		cnt = 0;
	}
	cout << sx << " " << sy << "\n";
	return 0;
}

