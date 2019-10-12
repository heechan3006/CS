#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int n, m;
char map[21][21];
bool chk_alpha[26];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


using namespace std;

void go(int x, int y, int count) {
	int ans = 0;
	chk_alpha[count - 'A'] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}
		if (chk_alpha[map[nx][ny] - 'A'] == true) continue;
		chk_alpha[map[nx][ny] - 'A'] = true;
		ans = max(ans,go(nx, ny, map[nx][ny]));
		chk_alpha[map[nx][ny] - 'A'] = false;
	}
	
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j];
		}
	}
	
	cout << go(0, 0,map[0][0]) << '\n';
	
}