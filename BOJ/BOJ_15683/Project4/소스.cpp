#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 8
#define INF 987654321
using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
int used[MAXN];

int kind[] = {0,1,5,3,7,15 };
int N, M;
int total_cnt = 0;
struct node {
	int x;
	int y;
	int kind;
};
vector<node> camera;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int ans = INF;
int move(node a, int shift,int tmp_cnt) {
	int tmp = kind[a.kind];
	if (a.kind != 5) {
		tmp = (tmp << shift) % 15;
	}
	int cnt = tmp_cnt;
	for (int i = 0; i < 4; i++) {
		if (tmp & (1 << i)) {
			int nx = a.x + dx[i];
			int ny = a.y + dy[i];
			while (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (copy_map[nx][ny] == 6) break;
				if (copy_map[nx][ny] == 0) cnt--;
				copy_map[nx][ny] = a.kind;
				nx += dx[i];
				ny += dy[i];
				
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] < 6) camera.push_back({ i,j ,map[i][j]});
			if (map[i][j] == 0) total_cnt++;
		}
	}
	
	for (int i = 0; i < camera.size(); i++) {
		int tmp_map[MAXN][MAXN] = { 0, };
		memcpy(tmp_map, map, sizeof(map));
		int tmp_cnt = total_cnt;
		int max_cnt = total_cnt;
		for (int j = 0; j < 4; j++) {
			memcpy(copy_map, map, sizeof(map));
			
			int cnt = move(camera[i], j,tmp_cnt);
			if (cnt < max_cnt) {
				max_cnt = cnt;
				memcpy(tmp_map, copy_map, sizeof(copy_map));
			}
		}
		total_cnt = max_cnt;
		memcpy(map, tmp_map, sizeof(tmp_map));

	}
	cout << total_cnt << "\n";
	return 0;
}