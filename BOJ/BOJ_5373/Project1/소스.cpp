#include <iostream>
#include <cstring>
#define MAXN 12
#define MAXM 9
using namespace std;
char cube[14][11];
char tmp[14][11];
int N;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int cw[] = { 0,1,2,3 };
int ccw[] = { 1,0,3,2 };
void rotate_90(int sx, int sy, int dirs[]) {
	//cw
	int nx = sx-1;
	int ny = sy-1;
	int x = sx - 1;
	int y = sy - 1;
	int d = 0;
	int nd = 0;
	
	int cnt = 2;
	while (cnt--) {
		if (nx + dx[dirs[nd]] < sx - 1 || ny + dy[dirs[nd]] < sy - 1 || nx + dx[dirs[nd]]> sx + 1 || ny + dy[dirs[nd]]>sy + 1) {
			nd = (nd + 1) % 4;	
		}
	}
	tmp[nx][ny] = cube[x][y];
	while (1) {
		if (nx + dx[dirs[nd]] < sx - 1 || ny + dy[dirs[nd]] < sy - 1 || nx + dx[dirs[nd]]> sx + 1 || ny + dy[dirs[nd]]>sy + 1) {
			nd = (nd + 1) % 4;
		}
		if (x + dx[dirs[d]] < sx - 1 || y + dy[dirs[d]] < sy - 1 || x + dx[dirs[d]]> sx + 1 || y + dy[dirs[d]]>sy + 1) {
			d = (d + 1) % 4;
		}
		nx += dx[dirs[nd]];
		ny += dy[dirs[nd]];
		if (nx == sx - 1 && ny == sy - 1) break;
		x += dx[dirs[d]];
		y += dy[dirs[d]];
		tmp[nx][ny] = cube[x][y];

	}
	
}
void rotate(int which, int dir) {
	if (which == 'R') {
		if (dir == '+') {
			int i = 4;
			for (int j = 1; j <= 12; j++) {
				tmp[j][6] = cube[i][6];
				i++;
				if (i > MAXN) i = 0;
			}
			rotate_90(5, 8, cw);
		}
		else {
			int i = 7;
			for (int j = 12; j >= 1; j--) {
				tmp[j][6] = cube[i][6];
				i--;
				if (i <= 0) i = MAXN;
			}
			rotate_90(5, 8, ccw);
		}

	}
	else if (which == 'L') {
		if (dir == '+') {
			int i = 4;
			for (int j = 1; j <= 12; j++) {
				tmp[j][4] = cube[i][4];
				i++;
				if (i > MAXN) i = 0;
			}
			rotate_90(2, 5, ccw);
		}
		else {
			int i = 7;
			for (int j = 12; j >= 1; j--) {
				tmp[j][4] = cube[i][4];
				i--;
				if (i <= 0) i = MAXN;
			}
			rotate_90(2, 5, cw);
		}
	}
	else if (which == 'U') {
		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 12; i++) {
		for (int j = 4; j < 4 + 3; j++) {
			if (i >= 1 && i <= 3) cube[i][j] = 'o';
			else if (i > 3 && i <= 6) cube[i][j] = 'w';
			else if (i > 6 && i <= 9) cube[i][j] = 'r';
			else cube[i][j] = 'y';
		}
	}
	for (int i = 4; i < 4 + 3; i++) {
		for (int j = 1; j < 10; j++) {
			if (j >= 1 && j <= 3) cube[i][j] = 'g';
			else if (j > 3 && j <= 6) cube[i][j] = 'w';
			else cube[i][j] = 'b';
		}
	}
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		memcpy(tmp, cube, sizeof(cube));
		string s;
		cin >> s;
		rotate(s[0], s[1]);
	}
}
