#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int x;
	int y;
	int num;
	int move_num;
	int dir;
};

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[101][101][2];
int visited[101][101];
node cell[1001];
int N, M, K;
int reverse_dir(int dir) {
	if (dir == 0) return 1;
	else if (dir == 1)return 0;
	else if (dir == 2) return 3;
	else if (dir == 3) return 2;
}
void move(int idx) {
	for (int i = 1; i <= K; i++) {
		cell[i].x += dx[cell[i].dir];
		cell[i].y += dy[cell[i].dir];
		if (cell[i].x == 0 || cell[i].y == 0 || cell[i].x == N - 1 || cell[i].y == N - 1) {
			cell[i].num /= 2;
			cell[i].move_num /= 2;
			cell[i].dir = reverse_dir(cell[i].dir);
				
		}
		if (visited[cell[i].x][cell[i].y]) {
			int tmp = visited[cell[i].x][cell[i].y];
			cell[tmp].num += cell[tmp].move_num;
			if (cell[i].move_num > cell[tmp].move_num) {
				cell[tmp].move_num = cell[i].move_num;
				cell[tmp].dir = cell[i].dir;
			}
			if ()
		}
		int& nidx = map[cell[i].x][cell[i].y][(i+1)% 2];
		if (nidx) {
			if (cell[i].move_num < cell[nidx].move_num) {
				
			}
		}
		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	
	for (int i = 1; i <= K; i++) {
		int tmp_x, tmp_y, tmp_dir, tmp_num;
		cin >> tmp_x >> tmp_y >> tmp_num >> tmp_dir;
		tmp_dir--;
		cell[i] = { tmp_x,tmp_y,tmp_num,tmp_num,tmp_dir };
	}
	for (int i = 0 ; i < M; i++){
		move(i);
		merge();
	}
}