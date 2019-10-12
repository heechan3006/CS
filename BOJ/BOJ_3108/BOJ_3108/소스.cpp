#include <iostream>
#define MAX 2001

using namespace std;
int N;
int map[MAX][MAX];
int dx[] = { 0,-1,1,0 };
int dy[] = { 1,0,0,-1 };

void dfs(int y, int x) {
	if (y < 0 || x < 0 || x >= MAX || y >= MAX) return;
	if (map[y][x] == 2 || map[y][x] == 0) return;
	map[y][x] = 2;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		dfs(ny, nx);
	}
}
int main() {
	cin >> N;
	int x1, y1, x2, y2;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1 = (x1 + 500) * 2;
		y1 = (y1 + 500) * 2;
		x2 = (x2 + 500) * 2;
		y2 = (y2 + 500) * 2;
		for (int i = x1; i <= x2; i++) {
			map[y1][i] = 1;
			map[y2][i] = 1;
		}
		for (int i = y1; i <= y2; i++) {
			map[i][x1] = 1;
			map[i][x2] = 1;
		}
	}
	
	int PU = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (map[i][j] == 1) {
				dfs(i, j);
				PU++;
			}
		}
	}
	if (map[1000][1000] == 2) PU--;
	printf("%d\n", PU);
}