#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char map[13][7];
char copy_map[13][7];
bool visited[13][7];
bool check[13][7];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

queue<pair<int, int>> q;
int cnt;
void dfs(int x, int y) {
	visited[x][y] = true;
	
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
		if (!visited[nx][ny] && map[x][y] == map[nx][ny]) {
			cnt++;
			dfs(nx, ny);
		}
	}
}
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
			if (!check[nx][ny] && map[nx][ny] == map[x][y]) {
				copy_map[nx][ny] = '.';
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 12; i++) {
		cin >> map[i];
		for (int j = 0; j < 6; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
	int time = 0;
	while (1){
		memset(visited, false, sizeof(visited));
		memset(check, false, sizeof(check));
		//dfs Å½»ö
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (!visited[i][j] && map[i][j]!='.') {
					cnt = 1;
					dfs(i, j);
					if (cnt >= 4) {
						q.push({ i,j });
						check[i][j] = true;
						copy_map[i][j] = '.';
					}
				}
			}
		}
		// »Ñ¿ä Æø¹ß
		bfs();
		// »Ñ¿ä move
		for (int j = 0; j < 6; j++) {
			for (int i = 11; i >= 0; i--) {
				if (copy_map[i][j] != '.' && i != 11) {
					bool flag = false;
					int idx = i;
					while (idx+1<=11) {
						if (copy_map[idx + 1][j] == '.') {
							flag = true;
							idx++;
						}
						else break;
					}
					if(flag){
						copy_map[idx][j] = copy_map[i][j];
						copy_map[i][j] = '.';
					}
				}
			}
		}
		// »óÅÂº¯È­ °ËÅä
		int sum = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] == copy_map[i][j]) sum++;
				map[i][j] = copy_map[i][j];
			}
		}
		if (sum == 72) break;
		time++;
	}
	cout << time << "\n";
}