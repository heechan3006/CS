#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool visited[5][5];
char map[5][5];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 0;
bool check[5][5];
void dfs(int now, int cnt) {
	if (cnt == 7) {
		bool is_possible = true;
		int cnt_y = 0;
		int cnt_s = 0;
		for (int i = 0; i < 25; i++) {
			
			if (visited[i/5][i%5]) {
				memset(check, false, sizeof(check));
				queue<pair<int, int>> q;
				q.push({ i / 5,i % 5 });
				check[i / 5][i % 5] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					if (map[x][y] == 'S') cnt_s++;
					else cnt_y++;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)continue;
						if (!visited[nx][ny]) continue;
						if (check[nx][ny]) continue;
						check[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
				if (cnt_y + cnt_s == 7 && cnt_s > cnt_y) ans++;
				break;
			}
		}
		return;
	}
	for (int i = now + 1; i < 25; i++) {
		if (!visited[i/5][i%5]){
			visited[i / 5][i % 5] = true;
			dfs(i, cnt + 1);
			visited[i / 5][i % 5] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 5; i++) {
		cin >> map[i];
	}
	for (int i =0 ; i< 19; i++){
		if (!visited[i/5][i%5]) {
			
			visited[i/5][i%5] = true;
			dfs(i, 1);
			visited[i/5][i%5] = false;
		}
		
	}
	cout << ans << "\n";
	return 0;
}