#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>

using namespace std;

char map[5][5];
set<string> ans;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y, int cnt,string s) {
	if (cnt == 6) {
		ans.insert(s);
		return;
	}
	for (int k = 0; k < 4; k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
		dfs(nx, ny, cnt+1,s + map[nx][ny]);
	}
}
int main() {
	int tmp;
	char tmp_c;
	for (int i = 0; i < 5; i ++){
		for (int j = 0; j < 5; j++){
			scanf("%d", &tmp);
			tmp_c = '0' + tmp;
			map[i][j] = tmp_c;
		}
	}
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string s = "";
			dfs(i, j,1,s+map[i][j]);
		}
	}
	printf("%d\n", ans.size());
}