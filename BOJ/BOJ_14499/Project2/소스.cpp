#include <iostream>

using namespace std;

int map[20][20];

int sx, sy;
int N, M;
int K;
int dice[4][3];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void go(int x, int y, int dir) {
	// 동
	if (dir == 0) {
		int tmp = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = tmp;
	}
	// 서
	else if (dir == 1) {
		int tmp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = tmp;
	}
	// 북
	else if (dir == 2) {
		int tmp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = tmp;
	}
	// 남
	else if (dir == 3) {
		int tmp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = tmp;
	}
	// map[x][y]== 0 일경우 -> 주사위 숫자 복사 (3,1)
	if (map[x][y] == 0) {
		map[x][y] = dice[3][1];
	}
	// map[x][y] != 0 일경우 -> 주사위에 숫자복사, 칸은 0
	else {
		dice[3][1] = map[x][y];
		map[x][y] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> sx >> sy >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	while (K--) {
		int order;
		cin >> order;
		order--;
		int nx = sx + dx[order];
		int ny = sy + dy[order];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		go(nx, ny, order);
		cout << dice[1][1] << "\n";
		sx = nx;
		sy = ny;
	}
	return 0;
}