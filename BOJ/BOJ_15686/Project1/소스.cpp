#include<iostream>
using namespace std;
#include<algorithm>
struct pos {
	int x;
	int y;
	int num;
	pos() {};
	pos(int x, int y, int num) :x(x), y(y), num(num) {};
};
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int N, M, map[15][15];
int cctv_num = 0;
pos cctv[8];
int ans = 210000000;
void draw(int x, int y, int dx, int dy) {
	int nx = x + dx;
	int ny = y + dy;
	if (nx < 0 || ny < 0 || nx >= N || ny >= M) return;
	if (map[nx][ny] == 6) return;
	if (map[nx][ny] == 0) map[nx][ny] = 9;
	draw(nx, ny, dx, dy);
}
void drawing(int arr[]) {
	int temp[15][15];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			temp[i][j] = map[i][j];
	for (int i = 0; i < cctv_num; i++) {
		int way = arr[i];
		if (cctv[i].num == 1)
			draw(cctv[i].x, cctv[i].y, dx[way], dy[way]);
		if (cctv[i].num == 2) {
			draw(cctv[i].x, cctv[i].y, dx[way], dy[way]);
			draw(cctv[i].x, cctv[i].y, dx[(way + 2) % 4], dy[(way + 2) % 4]);
		}
		if (cctv[i].num == 3) {
			draw(cctv[i].x, cctv[i].y, dx[way], dy[way]);
			draw(cctv[i].x, cctv[i].y, dx[(way + 1) % 4], dy[(way + 1) % 4]);
		}
		if (cctv[i].num == 4) {
			draw(cctv[i].x, cctv[i].y, dx[way], dy[way]);
			draw(cctv[i].x, cctv[i].y, dx[(way + 1) % 4], dy[(way + 1) % 4]);
			draw(cctv[i].x, cctv[i].y, dx[(way + 2) % 4], dy[(way + 2) % 4]);
		}
		if (cctv[i].num == 5) {
			for (int j = 0; j < 4; j++) {
				draw(cctv[i].x, cctv[i].y, dx[j], dy[j]);
			}
		}
	}
	int cc = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0) cc++;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map[i][j] = temp[i][j];
	ans = min(ans, cc);
}
void pick_way(int depth, int arr[]) {
	if (depth > cctv_num) return;
	if (depth == cctv_num) {
		drawing(arr);
		return;
	}
	for (int i = 0; i < 4; i++) {
		arr[depth] = i;
		pick_way(depth + 1, arr);
	}
}
int main() {
	cin >> N >> M;
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5)
				cctv[cctv_num++] = pos(i, j, map[i][j]);
			if (map[i][j] == 0) k++;
		}
	}
	ans = k;
	int arr[15] = { 0, };
	pick_way(0, arr);
	cout << ans;
}