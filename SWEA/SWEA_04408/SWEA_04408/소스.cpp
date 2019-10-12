#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int map[3][200];
int dist[3][200];
bool visited[3][200];
int dx[] = {0,0,1,-1};
int dy[] = { 1,-1,0,0 };
int n;
int sx, sy, ex, ey;
int idx;
int curr_r, next_r;
void get_pos() {
	if (curr_r % 2 == 1) sx = 0;
	else sx = 2;
	sy = (curr_r+1) / 2 - 1;
	if (next_r % 2 == 1) ex = 0;
	else ex = 2;
	ey = (next_r + 1) / 2 - 1;
	if (curr_r < next_r) idx = 1;
	else idx = 0;
}
void bfs() {
	queue<pair<int,int>> q;
	q.push(make_pair(sx, sy));
	visited[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (map[x][y] == next_r) return;
		for (int k = 0; k < 4; k++) {
			if (k == idx) continue;
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 200) continue;
			if (nx != 1 && map[nx][ny] != next_r) continue;
			if (idx == 1 && ny > ey) continue;
			if (idx == 0 && ny < ey) continue;
			if (!visited[nx][ny]){
				q.push({ nx,ny });
				visited[nx][ny] = true;
				dist[nx][ny] += 1;
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++){
		cin >> n;

		int num = 0;
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < 3; j++) {
				if (j == 1) map[j][i] = 0;
				else{
					num++;
					map[j][i] = num;
				}
			}
		
		}
	
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			cin >> curr_r >> next_r;
			v.push_back(make_pair(curr_r, next_r));
		}
		memset(dist, 0, sizeof(dist));
	
		for (int i = 0; i < v.size(); i++) {
			curr_r = v[i].first;
			next_r = v[i].second;
 			get_pos();
			memset(visited, false, sizeof(visited));
			bfs();
		}
		int ans = 0;
		for (int i = 0; i < 200; i++) {
			if (ans < dist[1][i]) ans = dist[1][i];
		}
		printf("#%d %d\n", test_case,ans);
		memset(visited, false, sizeof(visited));
		v.clear();
	}
	return 0;
}