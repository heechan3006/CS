#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int map[8][8];

struct node{
	int x;
	int y;
	int color;
	int count;
};
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

void go(int x, int y, int color) {
	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		int cnt = 0;
		int tmp_color=color;
		while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (map[nx][ny] == 0) break;
			if (tmp_color == map[nx][ny] && cnt == 0) break;
			if (cnt == 2) break;
			if (tmp_color == map[nx][ny]) {
				tmp_color = map[nx][ny];
				nx += dx[k];
				ny += dy[k];
				
			}
			else {
				tmp_color = map[nx][ny];
				nx += dx[k];
				ny += dy[k];
				
				cnt++;
			}
			
		}
		while (cnt == 2) {
			nx -= dx[k];
			ny -= dy[k];
			if (nx == x && ny == y) break;
			map[nx][ny] = color;
		}
	}
	
}
int main() {
	int t;
	vector<node> v;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++){
		scanf("%d %d", &N, &M);
		int tmp_x;
		int tmp_y;
		int tmp_color;
		
		memset(map, 0, sizeof(map));
		int mid_left_top_x = (N / 2) - 1;
		int mid_left_top_y = (N / 2) - 1;
		map[mid_left_top_x][mid_left_top_y] = 2;
		map[mid_left_top_x + 1][mid_left_top_y] = 1;
		map[mid_left_top_x][mid_left_top_y + 1] = 1;
		map[mid_left_top_x + 1][mid_left_top_y + 1] = 2;
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &tmp_y, &tmp_x, &tmp_color);
			map[tmp_x - 1][tmp_y - 1] = tmp_color;
			go(tmp_x -1, tmp_y-1, tmp_color);
		}
		int white = 0;
		int black = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) black++;
				else if (map[i][j] == 2) white++;
			}
		}
		printf("#%d %d %d\n",test_case, black, white);
	}
	return 0;
}