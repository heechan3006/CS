#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>

#define MAXN 100 + 4
using namespace std;
char map[MAXN][MAXN];
bool visited[MAXN][MAXN];
bool alpha[26];
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int bfs() {
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
			if (nx < 0 || ny < 0 || nx >= N + 2 || ny >= M + 2) continue;
			if (visited[nx][ny] || map[nx][ny]=='*') continue;
			if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z') {
				if (alpha[map[nx][ny] - 'A']) {
					map[nx][ny] = '.';
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
			else if ('a' <= map[nx][ny] && map[nx][ny] <= 'z') {
				if (alpha[map[nx][ny] - 'a']) {
					map[nx][ny] = '.';
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
				else {
					alpha[map[nx][ny] - 'a'] = true;
					while (!q.empty()) q.pop();
					memset(visited, false, sizeof(visited));
					q.push({ 0,0 });
				}
			}
			else if (map[nx][ny] == '$') {
				cnt++;
				map[nx][ny] = '.';
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
			else if (map[nx][ny] == '.') {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	return cnt;
}
int main() {
	int t;
	cin >> t;
	while (t--){
		memset(alpha, false, sizeof(alpha));
		memset(visited, false, sizeof(visited));
		cin >> N >> M;
		for (int i =0 ; i <= M+1; i++){
			for (int j = 0; j <= M + 1; j++) {
				map[i][j] = '.';
			}
		}
		for (int i = 1; i <= N ; i++) {
			string tmp;
			cin >> tmp;
			for (int j = 0; j < tmp.length(); j++) {
				map[i][j + 1] = tmp[j];
			}
		
		}
	
		string s;
		cin >> s;
		if (s[0] != '0') {
			for (int i = 0; i < s.length(); i++) {
				alpha[s[i] - 'a'] = true;
			}
		}
	
		int ans = bfs();
		cout << ans << "\n";
	}
	return 0;
}


