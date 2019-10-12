#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

int r, c;
int t;
char map[21][21];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
//row,col,val,dir
int path[21][21][16][4];
string ans;
struct node {
	int x, y, val, dir;
	node() {}
	node(int _x, int _y, int _val, int _dir) : x(_x), y(_y), val(_val), dir(_dir) {}
};


int change_idx(char c) {
	int idx ;
	if (c == '<') idx = 1;
	else if (c == '>') idx = 0;
	else if (c == 'v') idx = 2;
	else if (c == '^') idx = 3;
	return idx;
}

int check_num(int &cnt) {
	if (cnt > 15) cnt = 0;
	else if (cnt < 0) cnt = 15;
	return cnt;
}

bool bfs() {
	queue<node> q;
	q.push(node(0, 0, 0, 0));
	path[0][0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int val = q.front().val;
		int dir = q.front().dir;
		
		q.pop();
		// normal direction (<,>,^,v)
		if (map[x][y] == '<' || map[x][y] == '>' || map[x][y] == '^' || map[x][y] == 'v') {
			dir = change_idx(map[x][y]);
		}
		// condition direction (_,l,?)
		else if (map[x][y] == '_') dir = val == 0 ? 0 : 1;
		else if (map[x][y] == '|') dir = val == 0 ? 2 : 3;
		// save number to memory (0~9)
		else if (0 <= map[x][y] - '0' && map[x][y] - '0' <= 9) {
			val = map[x][y] - '0';
		}
		// compute memory (+,-)
		else if (map[x][y] == '+') val = val == 15 ? 0 : val + 1;
		else if (map[x][y] == '-') val = val == 0 ? 15 : val - 1;
		
		else if (map[x][y] == '@') {
			return true;
		}
		else if (map[x][y] == '?') {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (nx == -1) nx = r - 1;
				else if (nx == r) nx = 0;
				if (ny == -1) ny = c - 1;
				else if (ny == c) ny = 0;
				
				if (!path[nx][ny][val][i]) {
					q.push(node(nx, ny, val, i));
					path[nx][ny][val][i] = true;
				}
			}
		}

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		if (nx == -1) nx = r - 1;
		else if (nx == r) nx = 0;
		if (ny == -1) ny = c - 1;
		else if (ny == c) ny = 0;
		
		if (!path[nx][ny][val][dir]) {
			q.push(node(nx, ny, val, dir));
			path[nx][ny][val][dir] = true;
		}
	}
	
	return false;
}
int main() {
	cin >> t;
	int cnt = 0;
	while (t--){
		cin >> r >> c;
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				scanf(" %1c",&map[i][j]);
			}
		}
		memset(path, false, sizeof(path));
		ans = bfs() ? "YES" : "NO";
		cout << '#'<< ++cnt << ' '<< ans << '\n';
	}
	return 0;
}
