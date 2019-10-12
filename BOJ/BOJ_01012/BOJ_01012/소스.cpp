#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
/* 밭 가로 길이 M(1<= M <= 50), 세로길이 N ( 1<= N <= 50),
   배추 위치 개수 K(1<= K <= 2500),
   다음 K줄에 배추의 위치 X(0<=X<= M-1), Y(0 <= Y <= N-1)
   10 8 17
   0 0
   1 0
   1 1
   4 2
   4 3
   4 5
   2 4
   3 4
   7 4
   8 4
   9 4
   7 5
   8 5
   9 5
   7 6
   8 6 
   9 6*/

int n, m, k;
int map[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int x, int y) {
	
	map[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 1) {
				map[nx][ny] = 0;
				q.push(pair<int, int>(nx, ny));
			}
		}
	}
		
		
	
}
int main() {
	int x, y;
	int cnt;
	int T;
	cin >> T;
	for (int c = 0; c < T; c++) {
		cnt = 0;
		cin >> m >> n >> k;

		//fill(&map[0][0], &map[50][50], 0);
		memset(map, 0, sizeof(map));
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		
	}
	return 0;
}