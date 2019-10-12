#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[21][21];

bool visited[30];
bool alpha[30];
int R, C;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans;
int tcnt;
bool flag;
void dfs(int x, int y, int cnt) {
	if (cnt == tcnt) {
		ans = tcnt;
		flag = true;
		return;
	}
	if (ans < cnt) ans = cnt;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 1 || ny <1 || nx > R || ny > C) continue;
		if (flag) continue;
		if (visited[map[nx][ny] - 'A']) continue;
		
		visited[map[nx][ny] - 'A'] = true;
		dfs(nx, ny, cnt+1);
		
		visited[map[nx][ny] - 'A'] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		memset(visited, false, sizeof(visited));

		cin >> R >> C;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				cin >> map[i][j];
				alpha[map[i][j] - 'A'] = true;
			}
		}
		ans = 0;
		tcnt = 0;
		flag = false;
		for (int i = 0; i < 26; i++) {
			tcnt += alpha[i];
		}
		
		visited[map[1][1] - 'A'] = true;
		
		dfs(1,1,1);
		
		cout << "#" << test_case<<" "<< ans << "\n";
	}
	return 0;
}
