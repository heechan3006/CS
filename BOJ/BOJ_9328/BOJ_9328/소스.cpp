#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

char map[103][103];
bool visited[103][103];
bool alpha[26];
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;

	while (t--){
		memset(visited, false, sizeof(visited));
		memset(alpha, false, sizeof(alpha));
		cin >> N >> M;
		for (int i = 0; i <= N+1; i++) {
			for (int j = 0; j <= M+1; j++) {
				map[i][j] = '.';
			}
		}
		for (int i = 1; i <= N; i++) {
			string tmp;
			cin >> tmp;
			map[i][0] = '.';
			map[i][M] = '.';
			for (int j = 0; j < tmp.length(); j++) {
				map[i][j+1] = tmp[j];
			}
		
		}
	
		string s;
		cin >> s;
		if (s[0]!= '0'){
			for (int i = 0; i < s.length(); i++) {
				alpha[s[i] - 'a'] = true;
				for (int j = 0; j <= N; j++) {
					for (int k = 0; k <= M; k++) {
						if (map[j][k] == toupper(s[i])) {
							map[j][k] = '.';
						}
					}
				}
			}
		}
		queue<pair<int, int>> q;
	
		q.push({ 0,0 });
		visited[0][0] = true;
		int cnt = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
		
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx > N + 1 || ny > M + 1) continue;
				if (visited[nx][ny]) continue;
				if (map[nx][ny] == '.') {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
				else if (map[nx][ny] == '$') {
					visited[nx][ny] = true;
					map[nx][ny] = '.';
					cnt++;
					q.push({ nx,ny });
				}
				else if ('a' <= map[nx][ny] && map[nx][ny] <= 'z' ) {
					
					char door = (char)toupper(map[nx][ny]);
					map[nx][ny] = '.';
					if (alpha[door - 'A']) continue;
					alpha[door-'A'] = true;
					memset(visited, false, sizeof(visited));
					while (!q.empty()) q.pop();
					q.push({ nx,ny });
					visited[nx][ny] = true;
					for (int i = 1; i <= N; i++) {
						for (int j = 1; j <= M; j++) {
							if (map[i][j] == door) {
								map[i][j] = '.';
							}
						}
					}
					
					break;
				}
			}
		}
		cout << cnt << "\n";
	}
}