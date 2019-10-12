#include <iostream>
#include <cstring>

#define MAXN 200
using namespace std;

int R, C, N;
char map[MAXN][MAXN];
int Time[MAXN][MAXN];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void install_boom(int T) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'O') continue;
			map[i][j] = 'O';
			Time[i][j] = T + 3;
		}
	}
}
void delete_boom(int T) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Time[i][j] == T) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
					if (map[nx][ny] == '.') continue;
					map[nx][ny] = '.';
				}
				map[i][j] = '.';
				Time[i][j] = 0;
			}
		}
	}
}
int main() {
	cin >> R >> C >> N;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O') {
				Time[i][j] = 3;
			}
		}
	}
	int time = 2;
	while (1) {
		if (time == N + 1) break;
		if (time % 2 == 0) {
			install_boom(time);
		}
		else {
			delete_boom(time);
		}
		time++;
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}