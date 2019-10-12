#include <iostream>
#include <set>

using namespace std;

int map[4][4];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans[7];
int t;
set<int> visited;
void dfs(int i, int j, int cnt) {
	
	if (cnt == 7) {
		int answer = 0;
		for (int num = 0; num < 7; num++) {
			answer = answer* 10 + ans[num];
		}
		visited.insert(answer);
		return;
	}
	ans[cnt] = map[i][j];
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		dfs(nx, ny, cnt + 1);
	}
}
int main() {
	scanf("%d", &t);
	for (int test_case = 1 ; test_case <= t; test_case++){
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &map[i][j]);
			}
		}
	
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dfs(i, j,0);
			}
		}
		printf("#%d %d\n", test_case, visited.size());

		visited.clear();
	}
	return 0;
}