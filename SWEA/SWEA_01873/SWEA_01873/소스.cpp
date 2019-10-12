#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

int h, w;
int n;
char map[20][20];
bool visited[20][20];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<char> v;
int sx, sy;
int dir;

void shoot(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	int tmp_dir;
	if (map[x][y] == '^') tmp_dir = 3;
	else if (map[x][y] == 'v') tmp_dir = 2;
	else if (map[x][y] == '<') tmp_dir = 1;
	else tmp_dir = 0;
	while (!q.empty()) {
		int nx = q.front().first + dx[tmp_dir];
		int ny = q.front().second + dy[tmp_dir];
		q.pop();
		if (nx < 0 || nx >= h || ny < 0 || ny >= w) break;
		if (map[nx][ny] == '#') break;
		if (map[nx][ny] == '*') {
			map[nx][ny] = '.';
			break;
		}
		else {
			q.push({ nx,ny });
		}
		
		
	}
}
void move(char c) {
	int idx;
	char temp;
	if (c == 'U') {
		idx = 3;
		temp = '^';
	}
	else if (c == 'D') {
		idx = 2;
		temp = 'v';
	}
	else if (c == 'L') {
		idx = 1;
		temp = '<';
	}
	else {
		idx = 0;
		temp = '>';
	}
	int nx = sx + dx[idx];
	int ny = sy + dy[idx];
	if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
		map[sx][sy] = temp;
		return;
	}
	if (map[nx][ny] == '.') {
		map[nx][ny] = temp;
		map[sx][sy] = '.';
		sx = nx;
		sy = ny;
	}
	else {
		map[sx][sy] = temp;
	}

}
int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++){
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf(" %1c", &map[i][j]);
				if (map[i][j] == '>' || map[i][j] == '<' || map[i][j] == '^' || map[i][j] == 'v') {
					sx = i;
					sy = j;
				}
			}
		}
		cin >> n;
		char tmp;
		for (int i = 0; i < n; i++) {
			scanf(" %1c", &tmp);
			v.push_back(tmp);
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 'S') {
				shoot(sx, sy);
			}
			else {
				move(v[i]);
			}
		}
		printf("#%d ", test_case);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		v.clear();
	}
	return 0;
}