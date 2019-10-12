#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAXN 50

int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N, M;
int sx, sy, sd;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	//freopen("input.txt","r",stdin);
	cin >> N >> M;
	cin >> sx >> sy >> sd;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int x = sx;
	int y = sy;
	int d = sd;
	map[x][y] = 2;
	while (1) {
		
		int tmp_d = d;
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			tmp_d--;
			if (tmp_d < 0) tmp_d = 3;
			int nx = x + dx[tmp_d];
			int ny = y + dy[tmp_d];
			if (map[nx][ny] == 0) {
				map[nx][ny] = 2;
				d = tmp_d;
				x = nx;
				y = ny;
				flag = true;
				break;
			}
		}
		if (flag) continue;
		tmp_d = (d + 2) % 4;
		int nx = x + dx[tmp_d];
		int ny = y + dy[tmp_d];
		if (map[nx][ny] == 1) break;
		x = nx;
		y = ny;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}