#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAXN 1500

using namespace std;
int N, M;
char map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0,0 };
queue<pair<int, int>> swan_q,swan_nq,water_q,water_nq;

bool Find;
int swan_x, swan_y;
void swan_bfs() {
	while (!swan_q.empty() && Find == false) {
		int x = swan_q.front().first;
		int y = swan_q.front().second;
		swan_q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] == '.') {
				visited[nx][ny] = true;
				swan_q.push({ nx,ny });
			}
			else if (map[nx][ny] == 'X') {
				visited[nx][ny] = true;
				swan_nq.push({ nx,ny });
			}
			else if (map[nx][ny] == 'L') {
				visited[nx][ny] = true;
				Find = true;
				break;
			}
		}
	}
}
void water_bfs() {
	while (!water_q.empty()) {
		int x = water_q.front().first;
		int y = water_q.front().second;
		water_q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] == 'X') {
				map[nx][ny] = '.';
				water_nq.push({ nx,ny });
			}
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	int day = 0;
	Find = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] != 'X') {
				water_q.push({ i,j });
			}
			if (map[i][j] == 'L') {
				swan_x = i;
				swan_y = j;
			}
		}
	}
	swan_q.push({ swan_x,swan_y });
	visited[swan_x][swan_y] = true;
	while (Find == false) {
		swan_bfs();
		if (Find == false) {
			water_bfs();
			water_q = water_nq;
			swan_q = swan_nq;
			while (!water_nq.empty()) water_nq.pop();
			while (!swan_nq.empty()) swan_nq.pop();
			day++;
		}
	}
	printf("%d", day);
}
