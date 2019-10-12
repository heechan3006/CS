#include <iostream>
#include <cstring>
#include <vector>
#define MAXN 50
using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
int N, M, K;
struct node {
	int x;
	int y;
	int s;
};
vector<node> arr;
int num[6];
bool visited[6];
int ans = 987654321;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int dir[] = { 1,0,3,2 };
void rotate_arr(node a) {
	int x = a.x;
	int y = a.y;
	int s = a.s;
	for (int k = 1; k <= s; k++) {
		int d = 0;
		int sx = x - k;
		int sy = y - k;
		int cx = x - k;
		int cy = y - k;
		int nx = x - k;
		int ny = y - k;
		int tmp = copy_map[cx][cy];
		while (1) {
			if (nx + dx[dir[d]] < x - k || ny + dy[dir[d]]< y - k || nx + dx[dir[d]]>x + k || ny + dy[dir[d]]>y + k) {
				d = (d + 1) % 4;
			}
			nx += dx[dir[d]];
			ny += dy[dir[d]];
			if (nx == sx && ny == sy) break;
			copy_map[cx][cy] = copy_map[nx][ny];
			cx = nx;
			cy = ny;
			
		}
		copy_map[cx][cy] = tmp;
	}
}
void dfs(int idx) {
	if (idx == K) {
		memcpy(copy_map, map, sizeof(map));
		for (int i = 0; i < K; i++) {
			
			rotate_arr(arr[num[i]]);
		}
		
		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < M; j++) {
				sum += copy_map[i][j];
			}
			if (ans > sum) ans = sum;
		}
		return;
	}
	for (int i = 0; i < K; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		num[i] = idx;
		
		dfs(idx + 1);
		
		visited[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		r--;
		c--;
		arr.push_back({ r,c,s });
	}
	dfs(0);
	cout << ans << "\n";
	return 0;
}

