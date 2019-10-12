#include <iostream>
#include <algorithm>

using namespace std;

int N;
int map[26][26];
int group[26][26];
char num[26];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans[25 * 25];
int count_tmp;
void dfs(int i, int j, int cnt) {

	group[i][j] = cnt;
	
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			if (map[nx][ny] == 1 && group[nx][ny] == 0) {
				dfs(nx, ny, cnt);
			}
		}
	}
}



int main() {
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		for (int j = 0; j < N; j++) {
			map[i][j] = (int)(num[j] - '0');
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && group[i][j] == 0) {
				dfs(i, j, ++cnt);

			}
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans[group[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		//cout << ans[i] << '\n';
		printf("%d\n", ans[i]);
	}
	return 0;
}