#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAXN 50
int copy_map[MAXN][MAXN];
int map[MAXN][MAXN];
using namespace std;
typedef struct node {
	int x;
	int y;
	int s;
} node;
int N, M, K;
vector<node> v;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int dir[] = { 0,1,2,3 };
void rotate_map(node a) {
	int sx = a.x;
	int sy = a.y;
	int s = a.s;
	int tmp_map[MAXN][MAXN] = { 0, };
	memcpy(tmp_map, copy_map, sizeof(copy_map));
	for (int l = 1; l <= s; l++) {
		int nx = sx - l;
		int ny = sy - l;
		int x = sx - l;
		int y = sy - l;
		int d = 0;
		while (1) {
			nx += dx[dir[d]];
			ny += dy[dir[d]];
			if (nx > sx + l  || ny > sy + l || nx < sx - l || ny < sy - l) {
				nx -= dx[dir[d]];
				ny -= dy[dir[d]];
				d++;
				continue;
			}
			tmp_map[nx][ny] = copy_map[x][y];
			if (nx == sx - l && ny == sy - l) break;
			x = nx;
			y = ny;
			
		}
	}
	memcpy(copy_map, tmp_map, sizeof(tmp_map));
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
		int x, y, s;
		cin >> x >> y >> s;
		x--;
		y--;
		v.push_back({ x,y,s });
	}
	vector<int> num;
	for (int i = 0; i < v.size(); i++) {
		num.push_back(i);
	}
	
	int ans = 987654321;
	do {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < num.size(); i++) {
			rotate_map(v[num[i]]);
		}
		
		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < M; j++) {
				sum += copy_map[i][j];
			}
			if (ans > sum) ans = sum;
		}
	} while (next_permutation(num.begin(), num.end()));
	cout << ans << "\n";
	return 0;
}