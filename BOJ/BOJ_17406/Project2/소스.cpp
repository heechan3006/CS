#include <iostream>
#include <cstring>
#include <vector>
#define MAXN 50
#define INF 987654321
using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
struct node {
	int x;
	int y;
	int s;
};
vector<node> v;
int num[6];
bool used[6];
int ans = INF;
int N, M, K;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

void rotate_arr(node a) {
	int x = a.x;
	int y = a.y;
	int s = a.s;
	int tmp[MAXN][MAXN];
	memcpy(tmp, copy_map, sizeof(copy_map));
	for (int k = s; k >= 1; k--) {
		int sx = x - k;
		int sy = y - k;
		int d = 0;
		int nx = sx;
		int ny = sy;
		
		while (1) {
			if (nx + dx[d] < x - k || ny + dy[d] < y - k || nx + dx[d] > x + k || ny + dy[d] > y + k) {
				d = (d + 1) % 4;
			}
			
			tmp[nx + dx[d]][ny + dy[d]] = copy_map[nx][ny];
			
			nx += dx[d];
			ny += dy[d];
			if (nx == sx && ny == sy) break;
		}
	}
	memcpy(copy_map, tmp, sizeof(tmp));
}
void dfs(int now) {
	if (now == K) {
		memcpy(copy_map, map, sizeof(map));
		for (int i = 0; i < K; i++) {
			
			rotate_arr(v[num[i]]);
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
		if (used[i]) continue;
		used[i] = true;
		num[i] = now;
		dfs(now + 1);
		used[i] = false;
		
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
	v.resize(K);
	for (int i = 0; i < K; i++) {
		int x, y, s;
		cin >> x >> y >> s;
		x--;
		y--;
		v[i] = { x,y,s };
	}
	dfs(0);
	cout << ans << "\n";
	return 0;
}
