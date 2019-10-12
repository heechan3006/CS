#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 50

using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
int R, C, T;
int sx_up, sy_up, sx_down, sy_down;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool visited[MAXN][MAXN];
queue<pair<int, int>> q;

void COPY_MAP(int A[][MAXN], int B[][MAXN]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			A[i][j] = B[i][j];
		}
	}
}
void check_dust() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}
}
void change_dust() {
	COPY_MAP(copy_map, map);
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (map[i][j] != 0 && map[i][j] != -1){
				int cnt = 0;
				int value = map[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
					if (map[nx][ny] == -1) continue;
					
					copy_map[nx][ny] += value;
					cnt++;
				}
				copy_map[i][j] = copy_map[i][j] - (value* cnt);
			}
		}
	}
	COPY_MAP(map, copy_map);
}
void change_wind() {
	int dir_up = 3;
	int dir_down = 1;
	int x_up = sx_up - 1;
	int y_up = sy_up;
	int x_down = sx_down + 1;
	int y_down = sy_down;
	//up
	while (1) {
		int nx = x_up + dx[dir_up];
		int ny = y_up + dy[dir_up];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C || (nx == sx_down && ny == C-1)) {
			dir_up = (dir_up + 1) % 4;
			continue;
		}
		
		if (map[nx][ny] == -1) {
			map[x_up][y_up] = 0;
			break;
		}
		map[x_up][y_up] = map[nx][ny];
		x_up = nx;
		y_up = ny;
	}
	//down
	while (1) {
		int nx = x_down + dx[dir_down];
		int ny = y_down + dy[dir_down];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C || (nx == sx_up && ny == C-1)) {
			dir_down--;
			if (dir_down < 0) dir_down = 3;
			continue;
		}
		if (map[nx][ny] == -1) {
			map[x_down][y_down] = 0;
			break;
		}
		map[x_down][y_down] = map[nx][ny];
		x_down = nx;
		y_down = ny;
	}
}
void count_dust() {
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				ans += map[i][j];
			}
		}
	}
	printf("%d\n", ans);
}

int main() {
	scanf("%d%d%d", &R, &C, &T);
	int flag = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &map[i][j]);
			
			if (map[i][j] == -1 && flag == 0) {
				sx_up = i;
				sy_up = j;
				sx_down = i + 1;
				sy_down = j;
				flag = 1;
			}
		}
	}
	while (T--) {
		
		change_dust();
		change_wind();
	}
	count_dust();
}
